//You need to modify this file.

#ifndef SENSORTIMER_SENSOR_URG_VARS_H
#define SENSORTIMER_SENSOR_URG_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Sensor_URG_Vars SensorTimer_Sensor_URG_Vars
	\ingroup SensorTimer_Sensor_URG
	\brief SensorTimer_Sensor_URG_Vars defines the Vars in SensorTimer_Sensor_URG.
*/

/*! \addtogroup SensorTimer_Sensor_URG_Vars
	@{
*/

/*! \file SensorTimer_Sensor_URG_Vars.h
	 Defines the Vars of SensorTimer_Sensor_URG
*/

//*******************Please add other headers below*******************


#include "SensorTimer_Sensor_URG_ParamsData.h"

//The Vars is defined as below
/*! \class SensorTimer_Sensor_URG_Vars 
	\brief The Vars of SensorTimer_Sensor_URG.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_Sensor_URG_Vars 
{
public:
	/*! \fn SensorTimer_Sensor_URG_Vars()
		\brief The constructor of SensorTimer_Sensor_URG_Vars. [required]
		\details ****Please add details below****

	*/
	SensorTimer_Sensor_URG_Vars() 
	{

	}
	/*! \fn ~SensorTimer_Sensor_URG_Vars()
		\brief The destructor of SensorTimer_Sensor_URG_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_Sensor_URG_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    urg_t urg;
};

/*! @}*/ 

#endif
