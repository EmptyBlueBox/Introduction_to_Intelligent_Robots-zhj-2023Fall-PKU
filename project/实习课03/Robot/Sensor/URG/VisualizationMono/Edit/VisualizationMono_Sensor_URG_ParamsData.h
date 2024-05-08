//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_URG_PARAMSDATA_H
#define VISUALIZATIONMONO_SENSOR_URG_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_URG_ParamsData VisualizationMono_Sensor_URG_ParamsData
	\ingroup VisualizationMono_Sensor_URG
	\brief VisualizationMono_Sensor_URG_ParamsData defines the ParamsData in VisualizationMono_Sensor_URG.
*/

/*! \addtogroup VisualizationMono_Sensor_URG_ParamsData
	@{
*/

/*! \file VisualizationMono_Sensor_URG_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Sensor_URG
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorTimer_Sensor_URG_Params and Input Data SensorTimer_Sensor_URG_Data
#include<Robot/Sensor/URG/SensorTimer/Edit/SensorTimer_Sensor_URG_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Sensor_URG_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 1, Params_Type = SensorTimer_Sensor_URG_Params, Data_Type = SensorTimer_Sensor_URG_Data
*/
#define VisualizationMono_Sensor_URG_INPUTPORTSSIZE QList<int>()<<1

//The Params is defined as below
/*! \class VisualizationMono_Sensor_URG_Params 
	\brief The Params of VisualizationMono_Sensor_URG.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_URG_Params 
{
public:
	/*! \fn VisualizationMono_Sensor_URG_Params()
		\brief The constructor of VisualizationMono_Sensor_URG_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_URG_Params() 
	{
        range = 2500;
        interval = 500;
        imageRadius = 400;
        frontOnly = 1;
        laserBeam = 1;
	}
	/*! \fn ~VisualizationMono_Sensor_URG_Params()
		\brief The destructor of VisualizationMono_Sensor_URG_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_URG_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    short range;
    short interval;
    int imageRadius;
    bool frontOnly;
    bool laserBeam;
};

//There is no Output Data.

/*! \def VisualizationMono_Sensor_URG_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Sensor_URG_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
