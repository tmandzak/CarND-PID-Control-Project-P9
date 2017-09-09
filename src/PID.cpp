#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double eval_step, double init_speed) {
  
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->eval_step = eval_step;
  this->init_speed = init_speed;
  
  i_error = 0;
  step = 0;
  total_error = 0;
}

void PID::UpdateError(double cte) {
  p_error = cte;
  i_error += cte;
  
  if (step == 0) {
    d_error = 0;
  }else{
    d_error = cte - prev_cte; 
  }
  
  prev_cte = cte;
  
  step++;
  
  if (step > eval_step){
    total_error += cte * cte;
  }
  
}

double PID::GetValue() {
  double value = - Kp * p_error - Ki * i_error - Kd * d_error;
  
  if (value > 1) {value = 1;}
  else if (value < -1) {value = -1;}
  
  return value; 
}

double PID::TotalError() {
  double error;
  if (step > eval_step){
    error = total_error / (step - eval_step);
  }else{
    error = 0;
  }
      
  return error;
}

