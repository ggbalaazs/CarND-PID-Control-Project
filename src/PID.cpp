#include "PID.h"

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  first_run = true;
  p_error = 0;
  i_error = 0;
  d_error = 0;
}

void PID::updateError(double cte) {
  if (!first_run)
    d_error = cte - p_error;
  else
    first_run = false;
  
  i_error += cte;
  p_error = cte;
}

double PID::totalError() {
  return Kp * p_error + Ki * i_error + Kd * d_error;
}

