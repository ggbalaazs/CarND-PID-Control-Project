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

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  bool first_run;

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
  void init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void updateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double totalError();
};

#endif /* PID_H */
