//You need to modify this file.

#ifndef SIMULATOR_SENSOR_XTION_VARS_H
#define SIMULATOR_SENSOR_XTION_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_xtion_Vars Simulator_Sensor_xtion_Vars
	\ingroup Simulator_Sensor_xtion
	\brief Simulator_Sensor_xtion_Vars defines the Vars in Simulator_Sensor_xtion.
*/

/*! \addtogroup Simulator_Sensor_xtion_Vars
	@{
*/

/*! \file Simulator_Sensor_xtion_Vars.h
	 Defines the Vars of Simulator_Sensor_xtion
*/

//*******************Please add other headers below*******************


#include "Simulator_Sensor_xtion_ParamsData.h"

//The Vars is defined as below
/*! \class Simulator_Sensor_xtion_Vars 
	\brief The Vars of Simulator_Sensor_xtion.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_xtion_Vars 
{
public:
	/*! \fn Simulator_Sensor_xtion_Vars()
		\brief The constructor of Simulator_Sensor_xtion_Vars. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_xtion_Vars() 
	{
		
	}
	/*! \fn ~Simulator_Sensor_xtion_Vars()
		\brief The destructor of Simulator_Sensor_xtion_Vars. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_xtion_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QFile timestampSim;
    QTextStream textStream;
    QString colorDir, depthDir;
    int frameNum;
};

/*! @}*/ 

#endif
