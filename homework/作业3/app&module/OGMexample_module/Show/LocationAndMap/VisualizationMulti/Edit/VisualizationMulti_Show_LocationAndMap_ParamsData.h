//You need to modify this file.

#ifndef VISUALIZATIONMULTI_SHOW_LOCATIONANDMAP_PARAMSDATA_H
#define VISUALIZATIONMULTI_SHOW_LOCATIONANDMAP_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Show_LocationAndMap_ParamsData VisualizationMulti_Show_LocationAndMap_ParamsData
	\ingroup VisualizationMulti_Show_LocationAndMap
	\brief VisualizationMulti_Show_LocationAndMap_ParamsData defines the ParamsData in VisualizationMulti_Show_LocationAndMap.
*/

/*! \addtogroup VisualizationMulti_Show_LocationAndMap_ParamsData
	@{
*/

/*! \file VisualizationMulti_Show_LocationAndMap_ParamsData.h
	 Defines the ParamsData of VisualizationMulti_Show_LocationAndMap
*/

//*******************Please add other headers below*******************


//2 input data header(s) refered

//Defines Params ProcessorMulti_Algor_Mapping_Params and Input Data ProcessorMulti_Algor_Mapping_Data
#include<OGMexample_module/Algor/Mapping/ProcessorMulti/Edit/ProcessorMulti_Algor_Mapping_ParamsData.h>
//Defines Params Simulator_Sensor_GPS_Params and Input Data Simulator_Sensor_GPS_Data
#include<OGMexample_module/Sensor/GPS/Simulator/Edit/Simulator_Sensor_GPS_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMulti_Show_LocationAndMap_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 1, Params_Type = ProcessorMulti_Algor_Mapping_Params, Data_Type = ProcessorMulti_Algor_Mapping_Data
	- Input Port #1: Buffer_Size = 5, Params_Type = Simulator_Sensor_GPS_Params, Data_Type = Simulator_Sensor_GPS_Data
*/
#define VisualizationMulti_Show_LocationAndMap_INPUTPORTSSIZE QList<int>()<<1<<20

//The Params is defined as below
/*! \class VisualizationMulti_Show_LocationAndMap_Params 
	\brief The Params of VisualizationMulti_Show_LocationAndMap.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_Show_LocationAndMap_Params 
{
public:
	/*! \fn VisualizationMulti_Show_LocationAndMap_Params()
		\brief The constructor of VisualizationMulti_Show_LocationAndMap_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_Show_LocationAndMap_Params() 
	{
        mapHeight=600;
        mapWidth=640;
        mapGrid=20;
        mapRes=0.5;
        ZeroX=-360;
        ZeroY=-500;
	}
	/*! \fn ~VisualizationMulti_Show_LocationAndMap_Params()
		\brief The destructor of VisualizationMulti_Show_LocationAndMap_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_Show_LocationAndMap_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int mapHeight;
    int mapWidth;
    int mapGrid;
    double mapRes;
    int ZeroX;
    int ZeroY;
};

//There is no Output Data.

/*! \def VisualizationMulti_Show_LocationAndMap_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMulti_Show_LocationAndMap_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
