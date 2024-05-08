//You need to modify this file.

#ifndef SENSORTIMER_SENSOR_XTION_VARS_H
#define SENSORTIMER_SENSOR_XTION_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Sensor_xtion_Vars SensorTimer_Sensor_xtion_Vars
	\ingroup SensorTimer_Sensor_xtion
	\brief SensorTimer_Sensor_xtion_Vars defines the Vars in SensorTimer_Sensor_xtion.
*/

/*! \addtogroup SensorTimer_Sensor_xtion_Vars
	@{
*/

/*! \file SensorTimer_Sensor_xtion_Vars.h
	 Defines the Vars of SensorTimer_Sensor_xtion
*/

//*******************Please add other headers below*******************


#include "SensorTimer_Sensor_xtion_ParamsData.h"

//The Vars is defined as below
/*! \class SensorTimer_Sensor_xtion_Vars 
	\brief The Vars of SensorTimer_Sensor_xtion.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Sensor_xtion_Vars 
{
public:
	/*! \fn SensorTimer_Sensor_xtion_Vars()
		\brief The constructor of SensorTimer_Sensor_xtion_Vars. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Sensor_xtion_Vars() 
	{
		
	}
	/*! \fn ~SensorTimer_Sensor_xtion_Vars()
		\brief The destructor of SensorTimer_Sensor_xtion_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Sensor_xtion_Vars() 
	{
        if (oniDepthImg.isValid()) {
            oniDepthImg.release();
        }
        if (oniColorImg.isValid()) {
            oniColorImg.release();
        }
	}
public:
	//*******************Please add variables below*******************
    openni::VideoFrameRef oniDepthImg, oniColorImg;
    openni::Device device;

    openni::VideoStream oniDepthStream;
    openni::VideoStream oniColorStream;
};

/*! @}*/ 

#endif
