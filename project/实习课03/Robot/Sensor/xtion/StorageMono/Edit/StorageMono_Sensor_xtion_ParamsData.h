//You need to modify this file.

#ifndef STORAGEMONO_SENSOR_XTION_PARAMSDATA_H
#define STORAGEMONO_SENSOR_XTION_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup StorageMono_Sensor_xtion_ParamsData StorageMono_Sensor_xtion_ParamsData
	\ingroup StorageMono_Sensor_xtion
	\brief StorageMono_Sensor_xtion_ParamsData defines the ParamsData in StorageMono_Sensor_xtion.
*/

/*! \addtogroup StorageMono_Sensor_xtion_ParamsData
	@{
*/

/*! \file StorageMono_Sensor_xtion_ParamsData.h
	 Defines the ParamsData of StorageMono_Sensor_xtion
*/

//*******************Please add other headers below*******************
#include <QDir>

//1 input data header(s) refered

//Defines Params SensorTimer_Sensor_xtion_Params and Input Data SensorTimer_Sensor_xtion_Data
#include<Robot/Sensor/xtion/SensorTimer/Edit/SensorTimer_Sensor_xtion_ParamsData.h>

//0 new input data type(s) created

/*! \def StorageMono_Sensor_xtion_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_xtion_Params, Data_Type = SensorTimer_Sensor_xtion_Data
*/
#define StorageMono_Sensor_xtion_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class StorageMono_Sensor_xtion_Params 
	\brief The Params of StorageMono_Sensor_xtion.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT StorageMono_Sensor_xtion_Params 
{
public:
	/*! \fn StorageMono_Sensor_xtion_Params()
		\brief The constructor of StorageMono_Sensor_xtion_Params. [required]
		\details ****Please add details below****

	*/
	StorageMono_Sensor_xtion_Params() 
	{
        colorFilename = QString("$(CurTime)_color");
        depthFilename = QString("$(CurTime)_depth");
        storagePath   = QString("#(DataPath)");
        fps    = 30;
        width  = 640;
        height = 480;
	}
	/*! \fn ~StorageMono_Sensor_xtion_Params()
		\brief The destructor of StorageMono_Sensor_xtion_Params. [required]
		\details *****Please add details below*****

	*/
	~StorageMono_Sensor_xtion_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString colorFilename, depthFilename, storagePath;
    int fps, width, height;
};

//There is no Output Data.

/*! \def StorageMono_Sensor_xtion_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define StorageMono_Sensor_xtion_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
