//You need to modify this file.

#ifndef SENSORTIMER_SENSOR_URG_PARAMSDATA_H
#define SENSORTIMER_SENSOR_URG_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Sensor_URG_ParamsData SensorTimer_Sensor_URG_ParamsData
	\ingroup SensorTimer_Sensor_URG
	\brief SensorTimer_Sensor_URG_ParamsData defines the ParamsData in SensorTimer_Sensor_URG.
*/

/*! \addtogroup SensorTimer_Sensor_URG_ParamsData
	@{
*/

/*! \file SensorTimer_Sensor_URG_ParamsData.h
	 Defines the ParamsData of SensorTimer_Sensor_URG
*/

//*******************Please add other headers below*******************
#include <urg_c/urg_utils.h>
#include <urg_c/urg_sensor.h>
#include <cmath>
#include <opencv2/opencv.hpp>

//There is no input data headers.

/*! \def SensorTimer_Sensor_URG_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorTimer_Sensor_URG_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorTimer_Sensor_URG_Params 
	\brief The Params of SensorTimer_Sensor_URG.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Sensor_URG_Params 
{
public:
	/*! \fn SensorTimer_Sensor_URG_Params()
		\brief The constructor of SensorTimer_Sensor_URG_Params. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Sensor_URG_Params() 
	{
        first_step = -360;
        last_step = 360;
        skip_step = 2;
        nearfilter = 0;
        farfilter = 5000;
        unit = 100.0;

        skip_scan = 0;
        connection_type   = URG_ETHERNET;
        device_or_address = "192.168.0.10";
        baudreate_or_port = 10940;
        measurement_type  = URG_DISTANCE;
	}
	/*! \fn ~SensorTimer_Sensor_URG_Params()
		\brief The destructor of SensorTimer_Sensor_URG_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Sensor_URG_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int first_step, last_step, skip_step;
    short nearfilter, farfilter;
    double unit;
    int skip_scan;
    urg_connection_type_t connection_type;
    QString device_or_address;
    long baudreate_or_port;
    urg_measurement_type_t measurement_type;
};

//The Output Data is defined as below
/*! \class SensorTimer_Sensor_URG_Data 
	\brief The Data of SensorTimer_Sensor_URG.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Sensor_URG_Data 
{
public:
	/*! \fn SensorTimer_Sensor_URG_Data()
		\brief The constructor of SensorTimer_Sensor_URG_Data. [required]
		\details ****Please add details below****

	*/
    SensorTimer_Sensor_URG_Data(int _datasize)
	{
        datasize = _datasize;
        if(datasize > 0) {
            data = new short[datasize];
        } else {
            data = NULL;
        }
	}
	/*! \fn ~SensorTimer_Sensor_URG_Data()
		\brief The destructor of SensorTimer_Sensor_URG_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Sensor_URG_Data() 
	{
        delete []data;
        data =NULL;
	}
public:
	//*******************Please add variables below*******************
    int timestamp;
    QTime qtimestamp;
    int datasize;
    short * data;
};

/*! \def SensorTimer_Sensor_URG_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorTimer_Sensor_URG_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
