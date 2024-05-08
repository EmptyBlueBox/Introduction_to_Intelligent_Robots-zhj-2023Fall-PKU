//You need to modify this file.

#ifndef SIMULATOR_SENSOR_ENCODERIMU_VARS_H
#define SIMULATOR_SENSOR_ENCODERIMU_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_EncoderIMU_Vars Simulator_Sensor_EncoderIMU_Vars
	\ingroup Simulator_Sensor_EncoderIMU
	\brief Simulator_Sensor_EncoderIMU_Vars defines the Vars in Simulator_Sensor_EncoderIMU.
*/

/*! \addtogroup Simulator_Sensor_EncoderIMU_Vars
	@{
*/

/*! \file Simulator_Sensor_EncoderIMU_Vars.h
	 Defines the Vars of Simulator_Sensor_EncoderIMU
*/

//*******************Please add other headers below*******************


#include "Simulator_Sensor_EncoderIMU_ParamsData.h"

//The Vars is defined as below
/*! \class Simulator_Sensor_EncoderIMU_Vars 
	\brief The Vars of Simulator_Sensor_EncoderIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_EncoderIMU_Vars 
{
public:
	/*! \fn Simulator_Sensor_EncoderIMU_Vars()
		\brief The constructor of Simulator_Sensor_EncoderIMU_Vars. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_EncoderIMU_Vars() 
	{
        initx = 0;
        inity = 0;
        initori = 0;
        pulse = 0;
        lastlength = 0;
	}
	/*! \fn ~Simulator_Sensor_EncoderIMU_Vars()
		\brief The destructor of Simulator_Sensor_EncoderIMU_Vars. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_EncoderIMU_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QVector<SourceDrainMono_Sensor_EncoderIMU_Data> AllComData;
    int ComDataIndex;
    double initx;
    double inity;
    double initori;
    double lastlength;
    int pulse;
};

/*! @}*/ 

#endif
