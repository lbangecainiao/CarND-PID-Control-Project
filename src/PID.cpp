#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  i_error = 0;
  init = true; //If the class is just initialized, this flag is set to 1.
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;
  i_error += cte;
  if(init==true) {
    d_error = 0;  //When this class is just initialized, no cte_previous is stored, d_error is set to 0
  }else {
    d_error = cte - cte_previous;
  }
  init = false;
  cte_previous = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return -(Kp * p_error + Ki * i_error + Kd * d_error);  // TODO: Add your total error calc here!
}