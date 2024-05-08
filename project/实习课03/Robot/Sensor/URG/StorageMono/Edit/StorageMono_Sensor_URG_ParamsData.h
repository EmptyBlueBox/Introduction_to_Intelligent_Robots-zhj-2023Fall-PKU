//You need to modify this file.

#ifndef STORAGEMONO_SENSOR_URG_PARAMSDATA_H
#define STORAGEMONO_SENSOR_URG_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup StorageMono_Sensor_URG_ParamsData StorageMono_Sensor_URG_ParamsData
	\ingroup StorageMono_Sensor_URG
	\brief StorageMono_Sensor_URG_ParamsData defines the ParamsData in StorageMono_Sensor_URG.
*/

/*! \addtogroup StorageMono_Sensor_URG_ParamsData
	@{
*/

/*! \file StorageMono_Sensor_URG_ParamsData.h
	 Defines the ParamsData of StorageMono_Sensor_URG
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorTimer_Sensor_URG_Params and Input Data SensorTimer_Sensor_URG_Data
#include<Robot/Sensor/URG/SensorTimer/Edit/SensorTimer_Sensor_URG_ParamsData.h>

//0 new input data type(s) created

/*! \def StorageMono_Sensor_URG_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_URG_Params, Data_Type = SensorTimer_Sensor_URG_Data
*/
#define StorageMono_Sensor_URG_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class StorageMono_Sensor_URG_Params 
	\brief The Params of StorageMono_Sensor_URG.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT StorageMono_Sensor_URG_Params 
{
public:
	/*! \fn StorageMono_Sensor_URG_Params()
		\brief The constructor of StorageMono_Sensor_URG_Params. [required]
		\details ****Please add details below****

	*/
	StorageMono_Sensor_URG_Params() 
	{
        filename=QString("$(CurTime).lms");
        storagePath = QString("#(DataPath)");
	}
	/*! \fn ~StorageMono_Sensor_URG_Params()
		\brief The destructor of StorageMono_Sensor_URG_Params. [required]
		\details *****Please add details below*****

	*/
	~StorageMono_Sensor_URG_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString filename;
    QString storagePath;
};

//There is no Output Data.

/*! \def StorageMono_Sensor_URG_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define StorageMono_Sensor_URG_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
