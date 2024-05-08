//You need to modify this file.

#ifndef SIMULATOR_SENSOR_XTION_PARAMSDATA_H
#define SIMULATOR_SENSOR_XTION_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_xtion_ParamsData Simulator_Sensor_xtion_ParamsData
	\ingroup Simulator_Sensor_xtion
	\brief Simulator_Sensor_xtion_ParamsData defines the ParamsData in Simulator_Sensor_xtion.
*/

/*! \addtogroup Simulator_Sensor_xtion_ParamsData
	@{
*/

/*! \file Simulator_Sensor_xtion_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_xtion
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def Simulator_Sensor_xtion_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_xtion_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Sensor_xtion_Params 
	\brief The Params of Simulator_Sensor_xtion.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_xtion_Params 
{
public:
	/*! \fn Simulator_Sensor_xtion_Params()
		\brief The constructor of Simulator_Sensor_xtion_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_xtion_Params() 
	{
        storagePath = QString("#(DataPath)");
        colorFilename = QString("color.avi");
        depthFilename = QString("depth.avi");
	}
	/*! \fn ~Simulator_Sensor_xtion_Params()
		\brief The destructor of Simulator_Sensor_xtion_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_xtion_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString storagePath;
    QString colorFilename, depthFilename;
};

//The Output Data SensorTimer_Sensor_xtion_Data is defined in the header below
#include<Robot/Sensor/xtion/SensorTimer/Edit/SensorTimer_Sensor_xtion_ParamsData.h>

/*! \def Simulator_Sensor_xtion_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_xtion_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
