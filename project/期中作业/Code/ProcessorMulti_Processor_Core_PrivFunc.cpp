// You need to program this file.

#include "../NoEdit/ProcessorMulti_Processor_Core_PrivFunc.h"
#include <cmath>

//*******************Please add static libraries in .pro file*******************
// e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void *paramsPtr, void *varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName, qstrNodeType, qstrNodeClass, qstrNodeName);
	ProcessorMulti_Processor_Core_Params *params = (ProcessorMulti_Processor_Core_Params *)paramsPtr;
	ProcessorMulti_Processor_Core_Vars *vars = (ProcessorMulti_Processor_Core_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void *paramsPtr, void *varsPtr)
{
	ProcessorMulti_Processor_Core_Params *params = (ProcessorMulti_Processor_Core_Params *)paramsPtr;
	ProcessorMulti_Processor_Core_Vars *vars = (ProcessorMulti_Processor_Core_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/

	return 1;
}

void DECOFUNC(getInternalTrigger)(void *paramsPtr, void *varsPtr, QObject *&internalTrigger, QString &internalTriggerSignal)
{
	ProcessorMulti_Processor_Core_Params *params = (ProcessorMulti_Processor_Core_Params *)paramsPtr;
	ProcessorMulti_Processor_Core_Vars *vars = (ProcessorMulti_Processor_Core_Vars *)varsPtr;
	internalTrigger = NULL;
	internalTriggerSignal = QString();
	/*======Occasionally Program above======*/
	/*
	Function: get internal trigger [defined in vars] for node.
	You need to program here when you need internal trigger (internalTrigger + internalTriggerSignal) for node.
	E.g.
	internalTrigger=&(vars->trigger);
	internalTriggerSignal=QString(SIGNAL(triggerSignal()));
	*/
}

void DECOFUNC(initializeOutputData)(void *paramsPtr, void *varsPtr, boost::shared_ptr<void> &outputDataPtr)
{
	ProcessorMulti_Processor_Core_Params *params = (ProcessorMulti_Processor_Core_Params *)paramsPtr;
	ProcessorMulti_Processor_Core_Vars *vars = (ProcessorMulti_Processor_Core_Vars *)varsPtr;
	outputDataPtr = boost::shared_ptr<void>(new SourceDrainMono_Sensor_EncoderIMU_Order_InputData());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
}

void DECOFUNC(getMultiInputDataSize)(void *paramsPtr, void *varsPtr, QList<int> &inputDataSize)
{
	ProcessorMulti_Processor_Core_Params *params = (ProcessorMulti_Processor_Core_Params *)paramsPtr;
	ProcessorMulti_Processor_Core_Vars *vars = (ProcessorMulti_Processor_Core_Vars *)varsPtr;
	inputDataSize = QList<int>();
	/*======Please Program above======*/
	/*
	Function: get input data size to be grabbed from buffer.
	Rules:
	inputDataSize=0: grab and remove all data from buffer.
	inputDataSize>0: grab inputDataSize latest data from buffer.
	inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
	E.g.
	inputDataSize=QList<int>()<<0<<1<<-1...;
	*/
}

// Input Port #0: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_EncoderIMU_Params, Data_Type = SourceDrainMono_Sensor_EncoderIMU_Data
// Input Port #1: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_URG_Params, Data_Type = SensorTimer_Sensor_URG_Data
// Input Port #2: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_xtion_Params, Data_Type = SensorTimer_Sensor_xtion_Data
bool DECOFUNC(processMultiInputData)(void *paramsPtr, void *varsPtr, QVector<QVector<void *>> inputParams, QVector<QVector<void *>> inputData, void *outputData, QList<int> &outputPortIndex)
{
	ProcessorMulti_Processor_Core_Params *params = (ProcessorMulti_Processor_Core_Params *)paramsPtr;
	ProcessorMulti_Processor_Core_Vars *vars = (ProcessorMulti_Processor_Core_Vars *)varsPtr;
	QVector<SourceDrainMono_Sensor_EncoderIMU_Params *> inputparams_0;
	copyQVector(inputparams_0, inputParams[0]);
	QVector<SensorTimer_Sensor_URG_Params *> inputparams_1;
	copyQVector(inputparams_1, inputParams[1]);
	QVector<SensorTimer_Sensor_xtion_Params *> inputparams_2;
	copyQVector(inputparams_2, inputParams[2]);
	QVector<SourceDrainMono_Sensor_EncoderIMU_Data *> inputdata_0;
	copyQVector(inputdata_0, inputData[0]);
	QVector<SensorTimer_Sensor_URG_Data *> inputdata_1;
	copyQVector(inputdata_1, inputData[1]);
	QVector<SensorTimer_Sensor_xtion_Data *> inputdata_2;
	copyQVector(inputdata_2, inputData[2]);
	SourceDrainMono_Sensor_EncoderIMU_Order_InputData *outputdata = (SourceDrainMono_Sensor_EncoderIMU_Order_InputData *)outputData;
	outputPortIndex = QList<int>();
	if (inputdata_0.size() == 0)
	{
		return 0;
	}
	if (inputdata_1.size() == 0)
	{
		return 0;
	}
	if (inputdata_2.size() == 0)
	{
		return 0;
	}
	/*======Please Program below======*/

	/////////////////////////////////////////
	short speed_straight = 180, speed_turn = 160;								 // 小车直行和转弯的速度
	int threshold_cnt = 35;														 // 大于2.5m的激光束大于这个数说明是转弯
	double P = 0.6, I = 0.2, D = 0.2, error_max = 100, straight_max_steer = 300; // PID参数
	int prevent_collide_dis = 30;
	/////////////////////////////////////////
	short steer = 0;		  // [-400, 400]
	short speed = speed_turn; // [-180, 180]

	printf("\n");
	printf("inputdata_0 timestamp: %d\n", inputdata_0.front()->qtimestamp);
	printf("inputdata_0 odometry: %lf\n", inputdata_0.front()->odometry);

	// 计算左右的距离均值，用于计算 error
	double l_avg_dis = 0, r_avg_dis = 0;
	int l_valid_cnt = 0, r_valid_cnt = 0;
	for (int i = 350; i <= 360; i++)
	{
		if (inputdata_1.front()->data[i] != 0 && i >= 350)
		{
			l_avg_dis += inputdata_1.front()->data[i];
			l_valid_cnt++;
		}
	}
	for (int i = 0; i <= 10; i++)
	{
		if (inputdata_1.front()->data[i] != 0 && i <= 10)
		{
			r_avg_dis += inputdata_1.front()->data[i];
			r_valid_cnt++;
		}
	}
	l_avg_dis /= l_valid_cnt;
	r_avg_dis /= r_valid_cnt;
	printf("l_avg_dis: %lf, r_avg_dis: %lf\n", l_avg_dis, r_avg_dis);

	// 计算error，算PID控制
	double error = (r_avg_dis - l_avg_dis) / error_max;
	static double Inte = 0, error_last = 0;
	Inte = error + I * Inte;
	double diff = error - error_last;
	error_last = error;
	steer = (short)((P * error + I * Inte + D * diff) * straight_max_steer);
	printf("error: %lf, PID steer: %d\n", error, steer);

	// special case 1
	if ((l_avg_dis > 400) && (l_avg_dis < 500))
	{
		printf("special case 1\n");
		steer = 0;
	}

	// special case 2 ascenseur
	if ((r_avg_dis > 550) && (r_avg_dis < 700))
	{
		printf("ascenseur\n");
		steer = 0;
	}

	// clip
	if (steer > straight_max_steer)
		steer = straight_max_steer;
	else if (steer < -straight_max_steer)
		steer = -straight_max_steer;
	printf("error: %lf, PID steer: %d\n", error, steer);

	// 分别统计大于阈值的左右激光束的个数
	int l_cnt = 0, r_cnt = 0;
	for (int i = 270; i < 360; i++)
	{
		printf("%d ", inputdata_1.front()->data[i]);
		if (inputdata_1.front()->data[i] > 250) // the longest turn is around 470, but consider the width of corridor
			l_cnt++;
	}
	printf("\n");
	for (int i = 0; i <= 90; i++)
	{
		printf("%d ", inputdata_1.front()->data[i]);
		if (inputdata_1.front()->data[i] > 250)
			r_cnt++;
	}
	printf("\n");
	printf("l_cnt: %d, r_cnt: %d\n", l_cnt, r_cnt);

	// 找最长的几束激光
	double max_dis = 0;
	int max_idx = 0;
	for (int i = 0; i <= 360; i++)
	{
		double avg = 0;
		int valid_cnt = 0;
		for (int j = -2; j <= 2; j++)
		{
			if (i + j < 0 || i + j > 360 || inputdata_1.front()->data[i + j] == 0)
				continue;
			avg += inputdata_1.front()->data[i + j];
			valid_cnt++;
		}
		if (valid_cnt == 0)
			continue;
		avg /= valid_cnt;
		if (avg > max_dis)
		{
			max_dis = avg;
			max_idx = i;
		}
	}
	printf("max_dis: %lf, max_idx: %d\n", max_dis, max_idx);

	// 判断是否转弯
	static int turning = 0;
	if (turning == 1)
	{
		printf("turning right\n");
		steer = 400;
		if ((max_idx >= 181) && (max_idx <= 360))
		{
			turning = 0;
		}
	}
	else if (turning == -1)
	{
		printf("turning left\n");
		steer = -400;
		if ((max_idx >= 0) && (max_idx <= 180))
		{
			turning = 0;
		}
	}
	else if (turning == 0)
	{
		printf("straight\n");
		speed = speed_straight;
		if (r_cnt > threshold_cnt && max_idx < 160) // change or not?
		{
			turning = 1;
			steer = 400;
		}
		else if (l_cnt > threshold_cnt && max_idx > 240)
		{
			turning = -1;
			steer = -400;
		}
	}

	// 防撞机制
	// 左边太近，右转
	// 右边太近，左转
	// 前方太近，向最远处转
	double l_min_dis = 1000000, r_min_dis = 1000000, f_min_dis = 1000000;
	int l_min_idx = 0, r_min_idx = 360, f_min_idx = 180;

	for (int i = 120; i <= 240; i++)
	{
		double avg = 0;
		int valid_cnt = 0;
		for (int j = -5; j <= 5; j++)
		{
			if (i + j < 0 || i + j > 360 || inputdata_1.front()->data[i + j] == 0)
				continue;
			avg += inputdata_1.front()->data[i + j];
			valid_cnt++;
		}
		if (valid_cnt == 0)
			continue;
		avg /= valid_cnt;
		if (avg < f_min_dis)
		{
			f_min_dis = avg;
			f_min_idx = i;
		}
	}
	for (int i = 0; i <= 180; i++)
	{
		double avg = 0;
		int valid_cnt = 0;
		for (int j = -5; j <= 5; j++)
		{
			if (i + j < 0 || i + j > 180 || inputdata_1.front()->data[i + j] == 0)
				continue;
			avg += inputdata_1.front()->data[i + j];
			valid_cnt++;
		}
		if (valid_cnt == 0)
			continue;
		avg /= valid_cnt;
		if (avg < r_min_dis)
		{
			r_min_dis = avg;
			r_min_idx = i;
		}
	}
	for (int i = 180; i <= 360; i++)
	{
		double avg = 0;
		int valid_cnt = 0;
		for (int j = -5; j <= 5; j++) // enlarge the range
		{
			if (i + j < 180 || i + j > 360 || inputdata_1.front()->data[i + j] == 0)
				continue;
			avg += inputdata_1.front()->data[i + j];
			valid_cnt++;
		}
		if (valid_cnt == 0)
			continue;
		avg /= valid_cnt;
		if (avg < l_min_dis)
		{
			l_min_dis = avg;
			l_min_idx = i;
		}
	}
	printf("l_min_dis: %lf, l_min_idx: %d\n", l_min_dis, l_min_idx);
	printf("r_min_dis: %lf, r_min_idx: %d\n", r_min_dis, r_min_idx);
	printf("f_min_dis: %lf, f_min_idx: %d\n", f_min_dis, f_min_idx);

	// 前方优先级最低
	if (f_min_dis < prevent_collide_dis)
	{
		printf("collide front, turn to the farthest\n");
		if (f_min_idx < 180)
		{
			steer = 400;
		}
		else
		{
			steer = -400;
		}
	}
	// 左转优先级较高
	if (r_min_dis < prevent_collide_dis)
	{
		printf("collide right, turn left\n");
		for (int j = -10; j <= 10; j++)
		{
			if (r_min_idx + j < 0 || r_min_idx + j > 360)
				continue;
			printf("%d ", inputdata_1.front()->data[r_min_idx + j]);
		}

		steer = -400;
	}
	// 右转优先级最高
	if (l_min_dis < prevent_collide_dis)
	{
		printf("collide left, turn right\n");
		for (int j = -10; j <= 10; j++)
		{
			if (r_min_idx + j < 0 || r_min_idx + j > 360)
				continue;
			printf("%d ", inputdata_1.front()->data[r_min_idx + j]);
		}
		steer = 400;
	}

	if (steer > 400)
	{
		steer = 400;
	}
	else if (steer < -400)
	{
		steer = -400;
	}

	printf("speed=%d, steer=%d\n", speed, steer);

	//--------------------------------------------

	int maxSpeed = 180;
	if (speed > maxSpeed)
		speed = maxSpeed;
	if (speed < -maxSpeed)
		speed = -maxSpeed;
	char dataput[20];
	dataput[0] = 0xF8;
	dataput[1] = 4;
	*(short *)&dataput[2] = (short)steer;
	*(short *)&dataput[4] = (short)-speed;
	dataput[6] = 0x8F;
	outputdata->datagram = QByteArray(dataput, 7);
	return 1;
}
