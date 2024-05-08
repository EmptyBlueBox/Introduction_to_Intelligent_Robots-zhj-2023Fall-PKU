//You need to modify this file.

#ifndef STORAGEMONO_SENSOR_ENCODERIMU_PARAMSDATA_H
#define STORAGEMONO_SENSOR_ENCODERIMU_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup StorageMono_Sensor_EncoderIMU_ParamsData StorageMono_Sensor_EncoderIMU_ParamsData
	\ingroup StorageMono_Sensor_EncoderIMU
	\brief StorageMono_Sensor_EncoderIMU_ParamsData defines the ParamsData in StorageMono_Sensor_EncoderIMU.
*/

/*! \addtogroup StorageMono_Sensor_EncoderIMU_ParamsData
	@{
*/

/*! \file StorageMono_Sensor_EncoderIMU_ParamsData.h
	 Defines the ParamsData of StorageMono_Sensor_EncoderIMU
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SourceDrainMono_Sensor_EncoderIMU_Params and Input Data SourceDrainMono_Sensor_EncoderIMU_Data
#include<Robot/Sensor/EncoderIMU/SourceDrainMono/Edit/SourceDrainMono_Sensor_EncoderIMU_ParamsData.h>

//0 new input data type(s) created

/*! \def StorageMono_Sensor_EncoderIMU_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = SourceDrainMono_Sensor_EncoderIMU_Params, Data_Type = SourceDrainMono_Sensor_EncoderIMU_Data
*/
#define StorageMono_Sensor_EncoderIMU_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class StorageMono_Sensor_EncoderIMU_Params 
	\brief The Params of StorageMono_Sensor_EncoderIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT StorageMono_Sensor_EncoderIMU_Params 
{
public:
	/*! \fn StorageMono_Sensor_EncoderIMU_Params()
		\brief The constructor of StorageMono_Sensor_EncoderIMU_Params. [required]
		\details ****Please add details below****

	*/
	StorageMono_Sensor_EncoderIMU_Params() 
    {
        filename =  QString("$(CurTime).odom");
        storagePath = QString("#(DataPath)");
	}
	/*! \fn ~StorageMono_Sensor_EncoderIMU_Params()
		\brief The destructor of StorageMono_Sensor_EncoderIMU_Params. [required]
		\details *****Please add details below*****

	*/
	~StorageMono_Sensor_EncoderIMU_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString filename;
    QString storagePath;
};

//There is no Output Data.

/*! \def StorageMono_Sensor_EncoderIMU_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define StorageMono_Sensor_EncoderIMU_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
