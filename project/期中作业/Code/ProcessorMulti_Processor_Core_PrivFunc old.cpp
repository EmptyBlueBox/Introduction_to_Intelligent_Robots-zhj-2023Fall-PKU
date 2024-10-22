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
	double offset = 0;							  // 对于小车 odometry 的偏移量
	short speed_straight = 180, speed_turn = 140; // 小车直行和转弯的速度
	int turn_angle = 30;						  // 最远距离的激光束大于这个角度说明是转弯
	double P = 0.2, I = 0.05, D = 0.05, error_max = 100, noise_max_steer = 50, straight_max_steer = 100, turn_max_steer = 800;
	int turn_1_1 = 37, turn_1_2 = 42, turn_2_1 = 72, turn_2_2 = 79, turn_3_1 = 96, turn_3_2 = 108;
	int turn_4_1 = 110, turn_4_2 = 120, cone_start = 135, cone_end = 150, turn_5_1 = 150, turn_5_2 = 160;
	int noise_1_1 = 0, noise_1_2 = 8;
	double cone_dis = 1;		   // 开始绕锥桶时，锥桶的距离，或者说锥桶间距离
	int circle_cone_clockwise = 1; // -1:顺时针，左侧绕行第一个锥桶，1:逆时针，右侧绕行第一个锥桶
	double prevent_collide_dis = 30;
	/////////////////////////////////////////
	printf("\n");
	printf("inputdata_0 timestamp: %d\n", inputdata_0.front()->qtimestamp);
	printf("inputdata_0 odometry: %lf\n", inputdata_0.front()->odometry);

	// 计算左右的距离均值，用于计算 error
	double l_avg_dis = 0, r_avg_dis = 0;
	int l_valid_cnt = 0, r_valid_cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		if (inputdata_1.front()->data[i] != 0 && i <= 10)
		{
			l_avg_dis += inputdata_1.front()->data[i];
			l_valid_cnt++;
		}
	}
	for (int i = 350; i < inputdata_1.front()->datasize; i++)
	{
		if (inputdata_1.front()->data[i] != 0 && i >= 350)
		{
			r_avg_dis += inputdata_1.front()->data[i];
			r_valid_cnt++;
		}
	}
	l_avg_dis /= l_valid_cnt;
	r_avg_dis /= r_valid_cnt;

	// 有了error，先算PID控制
	static double Inte = 0, error_last = 0;

	short steer = 0;		  // [-400, 400]
	short speed = speed_turn; // [-180, 180]
	double error = (l_avg_dis - r_avg_dis) / error_max;
	Inte = error + I * Inte;
	double diff = error - error_last;
	error_last = error;
	steer = (short)((P * error + I * Inte + D * diff) * turn_max_steer);
	printf("error: %lf, PID steer: %d\n", error, steer);

	// PID之后特判转弯、直行、z字弯等
	int distence = inputdata_0.front()->odometry;
	distence += offset;

	// 找到左右两侧最大距离，windowsize=5，注意排除最前面和最侧面，可能被岔路影响
	double l_max_dis = 0, r_max_dis = 0;
	int l_max_idx = 0, r_max_idx = 360;
	for (int i = 20; i < 140; i++)
	{
		double avg = 0;
		int valid_cnt = 0;
		for (int j = -2; j <= 2; j++)
		{
			if (i + j < 0 || i + j > 180 || inputdata_1.front()->data[i + j] == 0)
				continue;
			avg += inputdata_1.front()->data[i + j];
			valid_cnt++;
		}
		avg /= valid_cnt;
		if (avg > l_max_dis)
		{
			l_max_dis = avg;
			l_max_idx = i;
		}
	}
	for (int i = 220; i < inputdata_1.front()->datasize - 20; i++)
	{
		double avg = 0;
		int valid_cnt = 0;
		for (int j = -2; j <= 2; j++)
		{
			if (i + j < 180 || i + j > inputdata_1.front()->datasize || inputdata_1.front()->data[i + j] == 0)
				continue;
			avg += inputdata_1.front()->data[i + j];
			valid_cnt++;
		}
		avg /= valid_cnt;
		if (avg > r_max_dis)
		{
			r_max_dis = avg;
			r_max_idx = i;
		}
	}

	// 普通右转的范围
	if ((turn_1_1 <= distence && distence <= turn_1_2) || (turn_2_1 <= distence && distence <= turn_2_2) || (turn_4_1 <= distence && distence <= turn_4_2) || (turn_5_1 <= distence && distence <= turn_5_2))
	{
		printf("turn right, orient angle=%lf\n", r_max_idx / 2.0 - 90);
		// 不允许应该右转时左转
		if (steer < -noise_max_steer)
		{
			steer = -noise_max_steer;
		}
		// 开始具体的转弯
		if ((r_max_idx / 2.0 - 90) > turn_angle)
		{
			printf("turning right\n");
			double steer_tmp = (r_max_idx / 2.0 - 90) / 90 * 400 * 2; // 多乘一个2，让小车在转了45度多时候也可以满舵机
			steer = steer_tmp > steer ? steer_tmp : steer;
		}
	}
	// z字弯的范围
	else if (turn_3_1 <= distence && distence <= turn_3_2)
	{
		double max_dis = (l_max_dis > r_max_dis ? l_max_dis : r_max_dis);
		int max_idx = (l_max_dis > r_max_dis ? l_max_idx : r_max_idx);
		printf("z, orient angle=%lf\n", max_idx / 2.0 - 90);
		// 开始具体的转弯
		if ((max_idx / 2.0 - 90) > turn_angle)
		{
			printf("turning z\n");
			double steer_tmp = (max_idx / 2.0 - 90) / 90 * 400 * 2; // 多乘一个2，让小车在转了45度多时候也可以满舵机
			steer = steer_tmp > steer ? steer_tmp : steer;
		}
	}
	// 锥桶的范围
	else if (cone_start <= distence && distence <= cone_end)
	{
		// 找锥桶的位置
		double cone_dis_now = 0;
		int cone_idx_now = 180;
		for (int i = l_max_idx; i <= r_max_idx; i++)
		{
			if (inputdata_1.front()->data[i] < cone_dis)
			{
				cone_dis_now = inputdata_1.front()->data[i];
				cone_idx_now = i;
			}
		}
		printf("cone, orient angle=%lf\n", cone_idx_now / 2.0 - 90);
		// 开始具体的转弯
		if (cone_dis_now < cone_dis)
		{
			printf("turning cone\n");
			double steer_tmp = (cone_idx_now / 2.0 - 90) / 90 * 400 * 2; // 多乘一个2，让小车在转了45度多时候也可以满舵机
			steer = steer_tmp > steer ? steer_tmp : steer;
		}
	}
	// 直道的范围
	else
	{
		printf("straight\n");
		if (steer > straight_max_steer)
		{
			steer = straight_max_steer;
		}
		else if (steer < -straight_max_steer)
		{
			steer = -straight_max_steer;
		}
		speed = speed_straight;
	}

	// 噪音（开始的岔路）
	if (noise_1_1 <= distence && distence <= noise_1_2)
	{
		printf("branch road 0-8m\n");
		if (steer < -noise_max_steer)
		{
			steer = -noise_max_steer;
		}
		else if (steer > noise_max_steer)
		{
			steer = noise_max_steer;
		}
	}

	// 防撞机制
	double l_min_dis = 1000000, r_min_dis = 1000000;
	int l_min_idx = 0, r_min_idx = 360;
	for (int i = 0; i < 180; i++)
	{
		double avg = 0;
		int valid_cnt = 0;
		for (int j = -2; j <= 2; j++)
		{
			if (i + j < 0 || i + j > 180 || inputdata_1.front()->data[i + j] == 0)
				continue;
			avg += inputdata_1.front()->data[i + j];
			valid_cnt++;
		}
		avg /= valid_cnt;
		if (avg < l_min_dis)
		{
			l_min_dis = avg;
			l_min_idx = i;
		}
	}
	for (int i = 180; i < inputdata_1.front()->datasize; i++)
	{
		double avg = 0;
		int valid_cnt = 0;
		for (int j = -2; j <= 2; j++)
		{
			if (i + j < 180 || i + j > inputdata_1.front()->datasize || inputdata_1.front()->data[i + j] == 0)
				continue;
			avg += inputdata_1.front()->data[i + j];
			valid_cnt++;
		}
		avg /= valid_cnt;
		if (avg < r_min_dis)
		{
			r_min_dis = avg;
			r_min_idx = i;
		}
	}

	if (r_min_dis < prevent_collide_dis)
	{
		printf("collide right, turn left\n");
		steer = -400;
	}
	// 右转优先级更高
	if (l_min_dis < prevent_collide_dis)
	{
		printf("collide left, turn right\n");
		steer = 400;
	}

	else if (steer > 400)
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
