//---------------------------------------------------------------------------
//    timer.cc,v 1.23 2005/03/29 00:49:28 guido Exp
//    Version: Version-5-2-0
//
//    Copyright (C) 1998, 1999, 2000, 2001, 2002, 2003, 2005 by the deal.II authors
//
//    This file is subject to QPL and may not be  distributed
//    without copyright and license information. Please refer
//    to the file deal.II/doc/license.html for the  text  and
//    further information on this license.
//
//---------------------------------------------------------------------------


#include "Timer.h"


// these includes should probably be properly
// ./configure'd using the AC_HEADER_TIME macro:
#include <sys/time.h>
#include <sys/resource.h>


Timer::Timer()
  :
    cumulative_time (0.)
{
  start();
}



void Timer::start ()
{
  running = true;
  rusage usage;
  getrusage (RUSAGE_SELF, &usage);
  start_time = usage.ru_utime.tv_sec + 1.e-6 * usage.ru_utime.tv_usec;

  rusage usage_children;
  getrusage (RUSAGE_CHILDREN, &usage_children);
  start_time_children = usage_children.ru_utime.tv_sec + 1.e-6 * usage_children.ru_utime.tv_usec;
}



double Timer::stop ()
{
  if (running)
  {
    running = false;
    rusage usage;
    getrusage (RUSAGE_SELF, &usage);
    const double dtime = usage.ru_utime.tv_sec + 1.e-6 * usage.ru_utime.tv_usec;
    cumulative_time += dtime - start_time;

    rusage usage_children;
    getrusage (RUSAGE_CHILDREN, &usage_children);
    const double dtime_children =
      usage_children.ru_utime.tv_sec + 1.e-6 * usage_children.ru_utime.tv_usec;
    cumulative_time += dtime_children - start_time_children;
  }
  return cumulative_time;
}



double Timer::operator() () const
{
  if (running)
  {
    rusage usage;
    getrusage (RUSAGE_SELF, &usage);
    const double dtime =  usage.ru_utime.tv_sec + 1.e-6 * usage.ru_utime.tv_usec;

    rusage usage_children;
    getrusage (RUSAGE_CHILDREN, &usage_children);
    const double dtime_children =
      usage_children.ru_utime.tv_sec + 1.e-6 * usage_children.ru_utime.tv_usec;

    return dtime - start_time + dtime_children - start_time_children + cumulative_time;
  }
  else
    return cumulative_time;
}



void Timer::reset ()
{
  cumulative_time = 0.;
  running         = false;
}