#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID():p_error(0.0),i_error(0.0),d_error(0.0) {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

// Name does not really make sense ?
// not sure if this formula is called total error
double PID::TotalError() {
    return -Kp*p_error -Ki*i_error -Kd*d_error;
}

