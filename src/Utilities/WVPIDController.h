#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

class WVPIDController
{
public:
	WVPIDController(double Kp, double Ki, double Kd, double setPoint,
			bool integralThreshold);
	double Tick(double measuredValue);
	void SetSetPoint(double setPoint);
	double GetSetPoint();
	void SetKp(double Kp);
	double GetKp();
	void SetKi(double Ki);
	double GetKi();
	void SetKd(double Kd);
	double GetKd();
	double GetError();
	double GetLastPWM();
	static double Limit(double num, double max);
	static inline double Map(double num, double fromLow, double fromHigh,
			double toLow,
			double toHigh)

private:

	double Kp;
	double Ki;
	double Kd;
	double setPoint;
	bool integralThreshold;
	double error;
	double previousError;
	double integral;
	double lastPWM;
};

#endif
