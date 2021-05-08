
task main()
{

	SensorType[S2]=sensorEV3_Touch;
	wait1Msec(50);
	SensorType[S4]=sensorEV3_Gyro;
	wait1Msec(50);
	SensorMode[S4]=modeEV3Gyro_RateAndAngle;
	wait1Msec(50);
	SensorMode[S3]=sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S3]=modeEV3Color_Color;
	wait1Msec(50);

	const int distanceTravelled = 50 * 180 / (PI *2.75);
	int count = 1;

	while (SensorValue[S2] == 0)
	{

		motor[motorA] = motor[motorD] = 30;

		if (SensorValue[S3] == (int)colorRed)
		{

			resetGyro(S4);

			motor[motorA] = -30;
			motor[motorD] = 30;

			count = count * -1;

			while(getGyroDegrees(S4) > -180)
			{}
		}

		else if (nMotorEncoder[motorA] > distanceTravelled)
		{

			motor[motorA] = motor[motorD] = 0;

			wait1Msec(1000);

			resetGyro(S4);

			if (count == -1)
			{
				motor[motorA] = -30;
				motor[motorD] = 30;
			}

			if (count == 1)
			{
				motor[motorA] = 30;
				motor[motorD] = -30;
			}

			while(getGyroDegrees(S4) > -90)
			{}

			nMotorEncoder[motorA] = 0;
		}
	}
}
