#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    prev_cte = -1.0;
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
}

void PID::UpdateError(double cte) {
    if (prev_cte == -1.0) {
        prev_cte = cte;
    }
    double diff_cte = cte - prev_cte;
    prev_cte = cte;
    int_cte += cte;

    p_error = Kp * cte;
    d_error = Kd * diff_cte;
    i_error = Ki * int_cte;
    
    std::cout << "Accumulated err: " << int_cte << std::endl; 
}

double PID::TotalError() {
    return -p_error - i_error - d_error;
}

