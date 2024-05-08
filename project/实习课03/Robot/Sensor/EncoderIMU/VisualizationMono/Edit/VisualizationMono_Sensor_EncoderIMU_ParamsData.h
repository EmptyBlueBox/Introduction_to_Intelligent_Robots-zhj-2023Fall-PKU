//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_ENCODERIMU_PARAMSDATA_H
#define VISUALIZATIONMONO_SENSOR_ENCODERIMU_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_EncoderIMU_ParamsData VisualizationMono_Sensor_EncoderIMU_ParamsData
	\ingroup VisualizationMono_Sensor_EncoderIMU
	\brief VisualizationMono_Sensor_EncoderIMU_ParamsData defines the ParamsData in VisualizationMono_Sensor_EncoderIMU.
*/

/*! \addtogroup VisualizationMono_Sensor_EncoderIMU_ParamsData
	@{
*/

/*! \file VisualizationMono_Sensor_EncoderIMU_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Sensor_EncoderIMU
*/

//*******************Please add other headers below*******************
#include <opencv2/opencv.hpp>

//1 input data header(s) refered

//Defines Params SourceDrainMono_Sensor_EncoderIMU_Params and Input Data SourceDrainMono_Sensor_EncoderIMU_Data
#include<Robot/Sensor/EncoderIMU/SourceDrainMono/Edit/SourceDrainMono_Sensor_EncoderIMU_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Sensor_EncoderIMU_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = SourceDrainMono_Sensor_EncoderIMU_Params, Data_Type = SourceDrainMono_Sensor_EncoderIMU_Data
*/
#define VisualizationMono_Sensor_EncoderIMU_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class VisualizationMono_Sensor_EncoderIMU_Params 
	\brief The Params of VisualizationMono_Sensor_EncoderIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_EncoderIMU_Params 
{
public:
	/*! \fn VisualizationMono_Sensor_EncoderIMU_Params()
		\brief The constructor of VisualizationMono_Sensor_EncoderIMU_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_EncoderIMU_Params() 
	{
        pixelSize = 1.0;
        mapSize = 500;
	}
	/*! \fn ~VisualizationMono_Sensor_EncoderIMU_Params()
		\brief The destructor of VisualizationMono_Sensor_EncoderIMU_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_EncoderIMU_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    double pixelSize;
    int mapSize;
};

//There is no Output Data.

/*! \def VisualizationMono_Sensor_EncoderIMU_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Sensor_EncoderIMU_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
