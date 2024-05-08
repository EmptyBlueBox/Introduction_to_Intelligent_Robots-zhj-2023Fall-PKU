//You need to modify this file.

#ifndef SIMULATOR_SENSOR_URG_PARAMSDATA_H
#define SIMULATOR_SENSOR_URG_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_URG_ParamsData Simulator_Sensor_URG_ParamsData
	\ingroup Simulator_Sensor_URG
	\brief Simulator_Sensor_URG_ParamsData defines the ParamsData in Simulator_Sensor_URG.
*/

/*! \addtogroup Simulator_Sensor_URG_ParamsData
	@{
*/

/*! \file Simulator_Sensor_URG_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_URG
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def Simulator_Sensor_URG_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_URG_INPUTPORTSSIZE QList<int>()

//The Params SensorTimer_Sensor_URG_Params is defined in the header below
#include<Robot/Sensor/URG/SensorTimer/Edit/SensorTimer_Sensor_URG_ParamsData.h>

//The Output Data SensorTimer_Sensor_URG_Data is defined in the header below
#include<Robot/Sensor/URG/SensorTimer/Edit/SensorTimer_Sensor_URG_ParamsData.h>

/*! \def Simulator_Sensor_URG_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_URG_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif