/* Copyright (c) 2010 Vladimir Chalupecky
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include "DormandPrince45.h"

DormandPrince45::DormandPrince45()
  : ExplicitRungeKuttaBase( 4, 7, true  ) // 4th order, 7 stages, FSAL true
{
  solverName_ = "Dormand-Prince5(4)7M (also implemented in Matlab as ode45)";

  c_(0) = 0.0;
  c_(1) = 1.0/5.0;
  c_(2) = 3.0/10.0;
  c_(3) = 4.0/5.0;
  c_(4) = 8.0/9.0;
  c_(5) = 1.0;
  c_(6) = 1.0;

  b_(0) =    35.0/384.0;
  b_(1) =     0.0; 
  b_(2) =   500.0/1113.0;
  b_(3) =   125.0/192.0;
  b_(4) = -2187.0/6784.0;
  b_(5) =    11.0/84.0;
  b_(6) =     0.0; 

  e_(0) =     71.0/57600.0;
  e_(1) =      0.0; 
  e_(2) =    -71.0/16695.0;
  e_(3) =     71.0/1920.0;
  e_(4) = -17253.0/339200.0;
  e_(5) =     22.0/525.0;
  e_(6) =     -1.0/40.0;

  a_(0,0) = 0.0; a_(0,1) = 0.0; a_(0,2) = 0.0; a_(0,3) = 0.0; a_(0,4) = 0.0; a_(0,5) = 0.0; a_(0,6) = 0.0;
  a_(1,0) = 1.0/5.0; a_(1,1) = 0.0; a_(1,2) = 0.0; a_(1,3) = 0.0; a_(1,4) = 0.0; a_(1,5) = 0.0; a_(1,6) = 0.0;
  a_(2,0) = 3.0/40.0; a_(2,1) = 9.0/40.0; a_(2,2) = 0.0; a_(2,3) = 0.0; a_(2,4) = 0.0; a_(2,5) = 0.0; a_(2,6) = 0.0;
  a_(3,0) = 44.0/45.0; a_(3,1) = -56.0/15.0; a_(3,2) = 32.0/9.0; a_(3,3) = 0.0; a_(3,4) = 0.0; a_(3,5) = 0.0; a_(3,6) = 0.0;
  a_(4,0) = 19372.0/6561.0; a_(4,1) = -25360.0/2187.0; a_(4,2) = 64448.0/6561.0; a_(4,3) = -212.0/729.0; a_(4,4) = 0.0; a_(4,5) = 0.0; a_(4,6) = 0.0;
  a_(5,0) = 9017.0/3168.0; a_(5,1) = -355.0/33.0; a_(5,2) = 46732.0/5247.0; a_(5,3) = 49.0/176.0; a_(5,4) = -5103.0/18656.0; a_(5,5) = 0.0; a_(5,6) = 0.0;
  a_(6,0) = 35.0/384.0; a_(6,1) = 0.0; a_(6,2) = 500.0/1113.0; a_(6,3) = 125.0/192.0; a_(6,4) = -2187.0/6784.0; a_(6,5) = 11.0/84.0; a_(6,6) = 0.0;
}


OdeIntegratorBase * createDormandPrince45Solver()
{
    return new DormandPrince45();
}

