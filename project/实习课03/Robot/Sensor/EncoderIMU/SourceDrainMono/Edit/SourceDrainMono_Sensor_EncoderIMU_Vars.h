//You need to modify this file.

#ifndef SOURCEDRAINMONO_SENSOR_ENCODERIMU_VARS_H
#define SOURCEDRAINMONO_SENSOR_ENCODERIMU_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SourceDrainMono_Sensor_EncoderIMU_Vars SourceDrainMono_Sensor_EncoderIMU_Vars
	\ingroup SourceDrainMono_Sensor_EncoderIMU
	\brief SourceDrainMono_Sensor_EncoderIMU_Vars defines the Vars in SourceDrainMono_Sensor_EncoderIMU.
*/

/*! \addtogroup SourceDrainMono_Sensor_EncoderIMU_Vars
	@{
*/

/*! \file SourceDrainMono_Sensor_EncoderIMU_Vars.h
	 Defines the Vars of SourceDrainMono_Sensor_EncoderIMU
*/

//*******************Please add other headers below*******************


#include "SourceDrainMono_Sensor_EncoderIMU_ParamsData.h"

//The Vars is defined as below
/*! \class SourceDrainMono_Sensor_EncoderIMU_Vars 
	\brief The Vars of SourceDrainMono_Sensor_EncoderIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SourceDrainMono_Sensor_EncoderIMU_Vars 
{
public:
	/*! \fn SourceDrainMono_Sensor_EncoderIMU_Vars()
		\brief The constructor of SourceDrainMono_Sensor_EncoderIMU_Vars. [required]
		\details ****Please add details below****

	*/
	SourceDrainMono_Sensor_EncoderIMU_Vars() 
	{
        port = "/dev/ttyS5";
        baudrate = QSerialPort::Baud38400;
        databitstype = QSerialPort::Data8;
        paritytype = QSerialPort::NoParity;
        stopbitstype = QSerialPort::OneStop;
        flowtype = QSerialPort::NoFlowControl;
        recvpacksize = 1;
        char ctmp = char(0xA2);
        packhead = QByteArray(&ctmp,1);
        ctmp = char(0x2A);
        packtail = QByteArray(&ctmp,1);
        distancePerPulse = 0.00000700423671;
        MaxPulse = 30000;
        initx = 0;
        inity = 0;
        initori = 0 ;
        odometry = 0;
        backDis = 0;
        isInit = false;
	}
	/*! \fn ~SourceDrainMono_Sensor_EncoderIMU_Vars()
		\brief The destructor of SourceDrainMono_Sensor_EncoderIMU_Vars. [required]
		\details *****Please add details below*****

	*/
	~SourceDrainMono_Sensor_EncoderIMU_Vars() 
	{
        if (serialport.isOpen()) {
            serialport.close();
        }
	}
public:
	//*******************Please add variables below*******************
    QString port;
    QSerialPort::BaudRate baudrate;
    QSerialPort::DataBits databitstype;
    QSerialPort::Parity paritytype;
    QSerialPort::StopBits stopbitstype;
    QSerialPort::FlowControl flowtype;
    int recvpacksize;
    QByteArray packhead;
    QByteArray packtail;
    double distancePerPulse;
    short MaxPulse;
    double initx;
    double inity;
    double initori;

    QSerialPort serialport;
    QByteArray databuffer;
    double odometry;
    double lastx;
    double lasty;
    double lastori;
    short lastpulsenum;
    double lastspeed;
    short backDis;  // Distance data from infrared sensor
    QTime qlasttimestamp;

    bool isInit;
    double initOriValue;

    QWidget* tempWidget;
};

/*! @}*/ 

#endif
