//You need to modify this file.

#ifndef SIMULATOR_SENSOR_ENCODERIMU_PARAMSDATA_H
#define SIMULATOR_SENSOR_ENCODERIMU_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_EncoderIMU_ParamsData Simulator_Sensor_EncoderIMU_ParamsData
	\ingroup Simulator_Sensor_EncoderIMU
	\brief Simulator_Sensor_EncoderIMU_ParamsData defines the ParamsData in Simulator_Sensor_EncoderIMU.
*/

/*! \addtogroup Simulator_Sensor_EncoderIMU_ParamsData
	@{
*/

/*! \file Simulator_Sensor_EncoderIMU_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_EncoderIMU
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def Simulator_Sensor_EncoderIMU_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_EncoderIMU_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Sensor_EncoderIMU_Params 
	\brief The Params of Simulator_Sensor_EncoderIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_EncoderIMU_Params 
{
public:
	/*! \fn Simulator_Sensor_EncoderIMU_Params()
		\brief The constructor of Simulator_Sensor_EncoderIMU_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_EncoderIMU_Params() 
	{
        path = "#(DataPath)";
        filename = "0.odom";
        distancePerPulse = 1.0;
        maxPulse = 30000;
	}
	/*! \fn ~Simulator_Sensor_EncoderIMU_Params()
		\brief The destructor of Simulator_Sensor_EncoderIMU_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_EncoderIMU_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString path;
    QString filename;
    double distancePerPulse;
    short maxPulse;
};

//The Output Data SourceDrainMono_Sensor_EncoderIMU_Data is defined in the header below
#include<Robot/Sensor/EncoderIMU/SourceDrainMono/Edit/SourceDrainMono_Sensor_EncoderIMU_ParamsData.h>

/*! \def Simulator_Sensor_EncoderIMU_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_EncoderIMU_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
