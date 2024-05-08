//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_CORE_PARAMSDATA_H
#define PROCESSORMULTI_PROCESSOR_CORE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_Core_ParamsData ProcessorMulti_Processor_Core_ParamsData
	\ingroup ProcessorMulti_Processor_Core
	\brief ProcessorMulti_Processor_Core_ParamsData defines the ParamsData in ProcessorMulti_Processor_Core.
*/

/*! \addtogroup ProcessorMulti_Processor_Core_ParamsData
	@{
*/

/*! \file ProcessorMulti_Processor_Core_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Processor_Core
*/

//*******************Please add other headers below*******************


//3 input data header(s) refered

//Defines Params SourceDrainMono_Sensor_EncoderIMU_Params and Input Data SourceDrainMono_Sensor_EncoderIMU_Data
#include<Robot/Sensor/EncoderIMU/SourceDrainMono/Edit/SourceDrainMono_Sensor_EncoderIMU_ParamsData.h>
//Defines Params SensorTimer_Sensor_URG_Params and Input Data SensorTimer_Sensor_URG_Data
#include<Robot/Sensor/URG/SensorTimer/Edit/SensorTimer_Sensor_URG_ParamsData.h>
//Defines Params SensorTimer_Sensor_xtion_Params and Input Data SensorTimer_Sensor_xtion_Data
#include<Robot/Sensor/xtion/SensorTimer/Edit/SensorTimer_Sensor_xtion_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Processor_Core_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=3
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_EncoderIMU_Params, Data_Type = SourceDrainMono_Sensor_EncoderIMU_Data
	- Input Port #1: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_URG_Params, Data_Type = SensorTimer_Sensor_URG_Data
	- Input Port #2: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_xtion_Params, Data_Type = SensorTimer_Sensor_xtion_Data
*/
#define ProcessorMulti_Processor_Core_INPUTPORTSSIZE QList<int>()<<10<<10<<10

//The Params is defined as below
/*! \class ProcessorMulti_Processor_Core_Params 
	\brief The Params of ProcessorMulti_Processor_Core.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_Core_Params 
{
public:
	/*! \fn ProcessorMulti_Processor_Core_Params()
		\brief The constructor of ProcessorMulti_Processor_Core_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_Core_Params() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Processor_Core_Params()
		\brief The destructor of ProcessorMulti_Processor_Core_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_Core_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data SourceDrainMono_Sensor_EncoderIMU_Order_InputData is defined in the header below
#include<Robot/Sensor/EncoderIMU/SourceDrainMono/Edit/SourceDrainMono_Sensor_EncoderIMU_ParamsData.h>

/*! \def ProcessorMulti_Processor_Core_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Processor_Core_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif