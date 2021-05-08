
task main()
{
	SensorType[S2] = sensorEV3_Ultrasonic;
	SensorType[S1] = sensorEV3_Touch;
	SensorType[S3] = sensorEV3_Gyro;

	float distance = 0;

	while (!getButtonPress(buttonEnter))
	{}

	while (getButtonPress(buttonEnter))
	{}

	distance = SensorValue[S2];

	displayString(5, "The distance is %f", distance);

	motor[motorA] = motor[motorD] = 30;

	while (SensorValue[S1] == 0)
	{}
	motor[motorA] = motor[motorD] = 0;

	wait1Msec(2000);

	motor[motorA] = motor[motorD] = -30;

	while (SensorValue[S2] < distance)
	{}

	motor[motorA] = motor[motorD] = 0;

	displayString(7, "The distance is %f", distance);

	wait1Msec(1000);

	resetGyro(S3);

	motor[motorA] = -30;
	motor[motorD] = 30;

	while(getGyroDegrees(S3) > -180)
	{}

	motor[motorA] = motor[motorD] = 0;

	wait1Msec(3000);
}
