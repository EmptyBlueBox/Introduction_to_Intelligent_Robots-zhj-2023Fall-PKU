//You need to modify this file.

#ifndef PROCESSORMULTI_ALGOR_MAPPING_PARAMSDATA_H
#define PROCESSORMULTI_ALGOR_MAPPING_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algor_Mapping_ParamsData ProcessorMulti_Algor_Mapping_ParamsData
	\ingroup ProcessorMulti_Algor_Mapping
	\brief ProcessorMulti_Algor_Mapping_ParamsData defines the ParamsData in ProcessorMulti_Algor_Mapping.
*/

/*! \addtogroup ProcessorMulti_Algor_Mapping_ParamsData
	@{
*/

/*! \file ProcessorMulti_Algor_Mapping_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Algor_Mapping
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>
#include <cmath>
#include "Bresenham.h"

//2 input data header(s) refered

//Defines Params Simulator_Sensor_GPS_Params and Input Data Simulator_Sensor_GPS_Data
#include<OGMexample_module/Sensor/GPS/Simulator/Edit/Simulator_Sensor_GPS_ParamsData.h>
//Defines Params Simulator_Sensor_laser_Params and Input Data Simulator_Sensor_laser_Data
#include<OGMexample_module/Sensor/laser/Simulator/Edit/Simulator_Sensor_laser_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Algor_Mapping_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 1, Params_Type = Simulator_Sensor_laser_Params, Data_Type = Simulator_Sensor_laser_Data
	- Input Port #1: Buffer_Size = 5, Params_Type = Simulator_Sensor_GPS_Params, Data_Type = Simulator_Sensor_GPS_Data
*/
#define ProcessorMulti_Algor_Mapping_INPUTPORTSSIZE QList<int>()<<1<<5

//The Params is defined as below
/*! \class ProcessorMulti_Algor_Mapping_Params 
	\brief The Params of ProcessorMulti_Algor_Mapping.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algor_Mapping_Params 
{
public:
	/*! \fn ProcessorMulti_Algor_Mapping_Params()
		\brief The constructor of ProcessorMulti_Algor_Mapping_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algor_Mapping_Params() 
	{
        mapRes = 0.5;
        ZeroX = -360;//26355-26496
        ZeroY = -500;//-1227- -1453
        mapWidth = 640;
        mapHeight = 600;
        logodd_occu=1;
        logodd_free=-0.7;
	}
	/*! \fn ~ProcessorMulti_Algor_Mapping_Params()
		\brief The destructor of ProcessorMulti_Algor_Mapping_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algor_Mapping_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    double mapRes;
    int ZeroX;
    int ZeroY;
    int mapWidth;
    int mapHeight;
    double logodd_occu;
    double logodd_free;
};

//The Output Data is defined as below
/*! \class ProcessorMulti_Algor_Mapping_Data 
	\brief The Data of ProcessorMulti_Algor_Mapping.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algor_Mapping_Data 
{
public:
	/*! \fn ProcessorMulti_Algor_Mapping_Data()
		\brief The constructor of ProcessorMulti_Algor_Mapping_Data. [required]
		\details ****Please add details below****

	*/
    ProcessorMulti_Algor_Mapping_Data(int w,int h)
	{
        mapWidth = w;
        mapHeight = h;
        if(mapWidth > 0 && mapHeight > 0)
        {
            map = new double * [mapHeight];
            for(int i = 0 ; i < mapHeight ; i ++)
            {
                map[i] = new double [mapWidth];
            }
        }
        else
        {
            map = NULL;
        }
	}
	/*! \fn ~ProcessorMulti_Algor_Mapping_Data()
		\brief The destructor of ProcessorMulti_Algor_Mapping_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algor_Mapping_Data() 
	{
        if(map != NULL)
        {
            for(int i = 0 ; i < mapHeight ; i ++)
            {
                delete map[i];
            }
            delete [] map;
            map = NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    int mapPOSX;
    int mapPOSY;
    int mapHeight;
    int mapWidth;
    double mapPOSOri;
    double ** map;
    long timestamp_GPS;
    long timestamp_laser;
    cv::Mat singlelaser;
};

/*! \def ProcessorMulti_Algor_Mapping_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Algor_Mapping_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
