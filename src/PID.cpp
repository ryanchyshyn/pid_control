#include "PID.h"

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;

	p_error = 0;
	i_error = 0;
	d_error = 0;

	i = 0;
}

double arrSum(double arr[], int len) {
	double ret = 0;
	for (int i = 0; i < len; i++) {
		ret += arr[i];
	}
	return ret;
}

void PID::UpdateError(double cte) {
	if (i == 0) {
		p_error = cte;
	}
	d_error = cte - p_error;
	p_error = cte;
	i_error += p_error;
	i++;
}

double PID::TotalError() {
	return -Kp * p_error - Kd * d_error - Ki * i_error;
}

