//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_XTION_PARAMSDATA_H
#define VISUALIZATIONMONO_SENSOR_XTION_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_xtion_ParamsData VisualizationMono_Sensor_xtion_ParamsData
	\ingroup VisualizationMono_Sensor_xtion
	\brief VisualizationMono_Sensor_xtion_ParamsData defines the ParamsData in VisualizationMono_Sensor_xtion.
*/

/*! \addtogroup VisualizationMono_Sensor_xtion_ParamsData
	@{
*/

/*! \file VisualizationMono_Sensor_xtion_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Sensor_xtion
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorTimer_Sensor_xtion_Params and Input Data SensorTimer_Sensor_xtion_Data
#include<Robot/Sensor/xtion/SensorTimer/Edit/SensorTimer_Sensor_xtion_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Sensor_xtion_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 1, Params_Type = SensorTimer_Sensor_xtion_Params, Data_Type = SensorTimer_Sensor_xtion_Data
*/
#define VisualizationMono_Sensor_xtion_INPUTPORTSSIZE QList<int>()<<1

//The Params is defined as below
/*! \class VisualizationMono_Sensor_xtion_Params 
	\brief The Params of VisualizationMono_Sensor_xtion.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_xtion_Params 
{
public:
	/*! \fn VisualizationMono_Sensor_xtion_Params()
		\brief The constructor of VisualizationMono_Sensor_xtion_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_xtion_Params() 
	{
		
	}
	/*! \fn ~VisualizationMono_Sensor_xtion_Params()
		\brief The destructor of VisualizationMono_Sensor_xtion_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_xtion_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMono_Sensor_xtion_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Sensor_xtion_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif