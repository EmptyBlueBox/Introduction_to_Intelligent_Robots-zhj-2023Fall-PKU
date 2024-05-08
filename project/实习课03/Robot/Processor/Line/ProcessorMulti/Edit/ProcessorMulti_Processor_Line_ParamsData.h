//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_LINE_PARAMSDATA_H
#define PROCESSORMULTI_PROCESSOR_LINE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_Line_ParamsData ProcessorMulti_Processor_Line_ParamsData
	\ingroup ProcessorMulti_Processor_Line
	\brief ProcessorMulti_Processor_Line_ParamsData defines the ParamsData in ProcessorMulti_Processor_Line.
*/

/*! \addtogroup ProcessorMulti_Processor_Line_ParamsData
	@{
*/

/*! \file ProcessorMulti_Processor_Line_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Processor_Line
*/

//*******************Please add other headers below*******************


//2 input data header(s) refered

//Defines Params SourceDrainMono_Sensor_EncoderIMU_Params and Input Data SourceDrainMono_Sensor_EncoderIMU_Data
#include<Robot/Sensor/EncoderIMU/Simulator/Edit/Simulator_Sensor_EncoderIMU_ParamsData.h>
//Defines Params SensorTimer_Sensor_URG_Params and Input Data SensorTimer_Sensor_URG_Data
#include<Robot/Sensor/URG/SensorTimer/Edit/SensorTimer_Sensor_URG_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Processor_Line_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_EncoderIMU_Params, Data_Type = SourceDrainMono_Sensor_EncoderIMU_Data
	- Input Port #1: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_URG_Params, Data_Type = SensorTimer_Sensor_URG_Data
*/
#define ProcessorMulti_Processor_Line_INPUTPORTSSIZE QList<int>()<<10<<10

//The Params is defined as below
/*! \class ProcessorMulti_Processor_Line_Params 
	\brief The Params of ProcessorMulti_Processor_Line.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_Line_Params 
{
public:
	/*! \fn ProcessorMulti_Processor_Line_Params()
		\brief The constructor of ProcessorMulti_Processor_Line_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_Line_Params() 
	{

	}
	/*! \fn ~ProcessorMulti_Processor_Line_Params()
		\brief The destructor of ProcessorMulti_Processor_Line_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_Line_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
#include<Robot/Sensor/EncoderIMU/SourceDrainMono/Edit/SourceDrainMono_Sensor_EncoderIMU_ParamsData.h>

/*! \class ProcessorMulti_Processor_Line_Data : public SourceDrainMono_Sensor_EncoderIMU_Order_InputData 
	\brief The Data of ProcessorMulti_Processor_Line.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_Line_Data : public SourceDrainMono_Sensor_EncoderIMU_Order_InputData 
{
public:
	/*! \fn ProcessorMulti_Processor_Line_Data()
		\brief The constructor of ProcessorMulti_Processor_Line_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_Line_Data() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Processor_Line_Data()
		\brief The destructor of ProcessorMulti_Processor_Line_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_Line_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    double x, y, theta;
    QVector<cv::Point2d> laserPoints;
    QVector<cv::Point2d> obPoints;
    QVector<cv::Point2d> safeZone;
};

/*! \def ProcessorMulti_Processor_Line_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Processor_Line_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
