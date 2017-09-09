#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  
  double prev_cte;
  double total_error;
  int step;
  int eval_step;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  double init_speed;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd, double eval_step, double init_speed);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);
  
  /*
  * Return PID value
  */
  double GetValue();

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
