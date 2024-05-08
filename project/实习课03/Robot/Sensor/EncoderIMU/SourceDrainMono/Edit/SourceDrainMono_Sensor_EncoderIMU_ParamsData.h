//You need to modify this file.

#ifndef SOURCEDRAINMONO_SENSOR_ENCODERIMU_PARAMSDATA_H
#define SOURCEDRAINMONO_SENSOR_ENCODERIMU_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SourceDrainMono_Sensor_EncoderIMU_ParamsData SourceDrainMono_Sensor_EncoderIMU_ParamsData
	\ingroup SourceDrainMono_Sensor_EncoderIMU
	\brief SourceDrainMono_Sensor_EncoderIMU_ParamsData defines the ParamsData in SourceDrainMono_Sensor_EncoderIMU.
*/

/*! \addtogroup SourceDrainMono_Sensor_EncoderIMU_ParamsData
	@{
*/

/*! \file SourceDrainMono_Sensor_EncoderIMU_ParamsData.h
	 Defines the ParamsData of SourceDrainMono_Sensor_EncoderIMU
*/

//*******************Please add other headers below*******************
#include <QSerialPort>
#include <cmath>
struct PID
{
    double Kp;
    double Ki;
    double Kd;
};

//0 input data header(s) refered


//1 new input data type(s) created

/*! \class SourceDrainMono_Sensor_EncoderIMU_Order_InputParams 
	\brief The Order_InputParams of SourceDrainMono_Sensor_EncoderIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SourceDrainMono_Sensor_EncoderIMU_Order_InputParams 
{
public:
	/*! \fn SourceDrainMono_Sensor_EncoderIMU_Order_InputParams()
		\brief The constructor of SourceDrainMono_Sensor_EncoderIMU_Order_InputParams. [required]
		\details ****Please add details below****

	*/
	SourceDrainMono_Sensor_EncoderIMU_Order_InputParams() 
	{
        char ctmp;
        ctmp = char(0xf8);
        pack_header = QByteArray(&ctmp,1);
        ctmp = char(0x8f);
        pack_tail = QByteArray(&ctmp,1);
        ctmp = char(0xEE);
        estop = QByteArray(&ctmp,1);
        ctmp = char(0xDD);
        normal = QByteArray(&ctmp,1);

        MaxSpeed = 65;
        MinSpeed = -60;
        MaxSteer = 500;
        MinSteer = -500;

        order_type = both;

        SteerPID.Kp = 5.0;
        SteerPID.Ki = 0.0;
        SteerPID.Kd = 1.0;

        SpeedPID.Kp = 45;
        SpeedPID.Ki = 25;
        SpeedPID.Kd = 0;
	}
	/*! \fn ~SourceDrainMono_Sensor_EncoderIMU_Order_InputParams()
		\brief The destructor of SourceDrainMono_Sensor_EncoderIMU_Order_InputParams. [required]
		\details *****Please add details below*****

	*/
	~SourceDrainMono_Sensor_EncoderIMU_Order_InputParams() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QByteArray pack_header;
    QByteArray pack_tail;
    QByteArray estop;
    QByteArray normal;

    int MaxSpeed;
    int MinSpeed;
    int MaxSteer;
    int MinSteer;

    enum ORDERTYPE{steer, speed, speedPID, both} order_type;

    PID SteerPID;
    PID SpeedPID;
};

/*! \class SourceDrainMono_Sensor_EncoderIMU_Order_InputData 
	\brief The Order_InputData of SourceDrainMono_Sensor_EncoderIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SourceDrainMono_Sensor_EncoderIMU_Order_InputData 
{
public:
	/*! \fn SourceDrainMono_Sensor_EncoderIMU_Order_InputData()
		\brief The constructor of SourceDrainMono_Sensor_EncoderIMU_Order_InputData. [required]
		\details ****Please add details below****

	*/
	SourceDrainMono_Sensor_EncoderIMU_Order_InputData() 
	{
		
	}
	/*! \fn ~SourceDrainMono_Sensor_EncoderIMU_Order_InputData()
		\brief The destructor of SourceDrainMono_Sensor_EncoderIMU_Order_InputData. [required]
		\details *****Please add details below*****

	*/
	~SourceDrainMono_Sensor_EncoderIMU_Order_InputData() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QByteArray datagram;
    QTime qtimestamp;
};

/*! \def SourceDrainMono_Sensor_EncoderIMU_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_EncoderIMU_Order_InputParams, Data_Type = SourceDrainMono_Sensor_EncoderIMU_Order_InputData
*/
#define SourceDrainMono_Sensor_EncoderIMU_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class SourceDrainMono_Sensor_EncoderIMU_Params 
	\brief The Params of SourceDrainMono_Sensor_EncoderIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SourceDrainMono_Sensor_EncoderIMU_Params 
{
public:
	/*! \fn SourceDrainMono_Sensor_EncoderIMU_Params()
		\brief The constructor of SourceDrainMono_Sensor_EncoderIMU_Params. [required]
		\details ****Please add details below****

	*/
	SourceDrainMono_Sensor_EncoderIMU_Params() 
	{
		
	}
	/*! \fn ~SourceDrainMono_Sensor_EncoderIMU_Params()
		\brief The destructor of SourceDrainMono_Sensor_EncoderIMU_Params. [required]
		\details *****Please add details below*****

	*/
	~SourceDrainMono_Sensor_EncoderIMU_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class SourceDrainMono_Sensor_EncoderIMU_Data 
	\brief The Data of SourceDrainMono_Sensor_EncoderIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SourceDrainMono_Sensor_EncoderIMU_Data 
{
public:
	/*! \fn SourceDrainMono_Sensor_EncoderIMU_Data()
		\brief The constructor of SourceDrainMono_Sensor_EncoderIMU_Data. [required]
		\details ****Please add details below****

	*/
	SourceDrainMono_Sensor_EncoderIMU_Data() 
	{
		
	}
	/*! \fn ~SourceDrainMono_Sensor_EncoderIMU_Data()
		\brief The destructor of SourceDrainMono_Sensor_EncoderIMU_Data. [required]
		\details *****Please add details below*****

	*/
	~SourceDrainMono_Sensor_EncoderIMU_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QTime qtimestamp;
    double x, y;
    double orientation;
    double orientationX;
    double orientationY;
    double speed;
    double odometry;
    unsigned short encoderRawData;
    short  backDis;  // Distance data from infrared sensor
};

/*! \def SourceDrainMono_Sensor_EncoderIMU_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SourceDrainMono_Sensor_EncoderIMU_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
