#include "PID.h"

/*
* TODO: Complete the PID class.
*/

#include <math.h>


PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

  this->Kp = Kp ;
  this->Ki = Ki ;
  this->Kd = Kd ;

  this->p_error = 0 ;
  this->i_error = 0 ;
  this->d_error = 0 ;

  this->previous_cte = 0 ;
}

void PID::UpdateError(double cte) {

  this->p_error = cte ;

  this->d_error = cte - this->previous_cte ;
  this->previous_cte = cte ;

  this->i_error += cte ;

}

double PID::TotalError() {

  return fabs(this->p_error) + fabs(this->i_error) + fabs(this->d_error) ;

}

