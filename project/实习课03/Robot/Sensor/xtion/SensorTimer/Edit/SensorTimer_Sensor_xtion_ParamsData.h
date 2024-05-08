//You need to modify this file.

#ifndef SENSORTIMER_SENSOR_XTION_PARAMSDATA_H
#define SENSORTIMER_SENSOR_XTION_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Sensor_xtion_ParamsData SensorTimer_Sensor_xtion_ParamsData
	\ingroup SensorTimer_Sensor_xtion
	\brief SensorTimer_Sensor_xtion_ParamsData defines the ParamsData in SensorTimer_Sensor_xtion.
*/

/*! \addtogroup SensorTimer_Sensor_xtion_ParamsData
	@{
*/

/*! \file SensorTimer_Sensor_xtion_ParamsData.h
	 Defines the ParamsData of SensorTimer_Sensor_xtion
*/

//*******************Please add other headers below*******************
#include <opencv2/opencv.hpp>
#include <openni2/OpenNI.h>

//There is no input data headers.

/*! \def SensorTimer_Sensor_xtion_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorTimer_Sensor_xtion_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorTimer_Sensor_xtion_Params 
	\brief The Params of SensorTimer_Sensor_xtion.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Sensor_xtion_Params 
{
public:
	/*! \fn SensorTimer_Sensor_xtion_Params()
		\brief The constructor of SensorTimer_Sensor_xtion_Params. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Sensor_xtion_Params() 
	{
        width = 640;
        height = 480;
        fps = 30;
	}
	/*! \fn ~SensorTimer_Sensor_xtion_Params()
		\brief The destructor of SensorTimer_Sensor_xtion_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Sensor_xtion_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int fps, width, height;
};

//The Output Data is defined as below
/*! \class SensorTimer_Sensor_xtion_Data 
	\brief The Data of SensorTimer_Sensor_xtion.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Sensor_xtion_Data 
{
public:
	/*! \fn SensorTimer_Sensor_xtion_Data()
		\brief The constructor of SensorTimer_Sensor_xtion_Data. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Sensor_xtion_Data() 
	{

	}
	/*! \fn ~SensorTimer_Sensor_xtion_Data()
		\brief The destructor of SensorTimer_Sensor_xtion_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Sensor_xtion_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    cv::Mat cvDepthImg, cvColorImg;
    QTime qtimestamp;
};

/*! \def SensorTimer_Sensor_xtion_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorTimer_Sensor_xtion_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
