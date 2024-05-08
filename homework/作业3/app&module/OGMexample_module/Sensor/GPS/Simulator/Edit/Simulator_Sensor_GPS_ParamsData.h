//You need to modify this file.

#ifndef SIMULATOR_SENSOR_GPS_PARAMSDATA_H
#define SIMULATOR_SENSOR_GPS_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_GPS_ParamsData Simulator_Sensor_GPS_ParamsData
	\ingroup Simulator_Sensor_GPS
	\brief Simulator_Sensor_GPS_ParamsData defines the ParamsData in Simulator_Sensor_GPS.
*/

/*! \addtogroup Simulator_Sensor_GPS_ParamsData
	@{
*/

/*! \file Simulator_Sensor_GPS_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_GPS
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def Simulator_Sensor_GPS_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_GPS_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Sensor_GPS_Params 
	\brief The Params of Simulator_Sensor_GPS.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_GPS_Params 
{
public:
	/*! \fn Simulator_Sensor_GPS_Params()
		\brief The constructor of Simulator_Sensor_GPS_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_GPS_Params() 
	{
		
	}
	/*! \fn ~Simulator_Sensor_GPS_Params()
		\brief The destructor of Simulator_Sensor_GPS_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_GPS_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class Simulator_Sensor_GPS_Data 
	\brief The Data of Simulator_Sensor_GPS.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_GPS_Data 
{
public:
	/*! \fn Simulator_Sensor_GPS_Data()
		\brief The constructor of Simulator_Sensor_GPS_Data. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_GPS_Data() 
	{
		
	}
	/*! \fn ~Simulator_Sensor_GPS_Data()
		\brief The destructor of Simulator_Sensor_GPS_Data. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_GPS_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    double x;//x
    double y;//y
    double ori;//orientation
    long timestamp;//timestamp
};

/*! \def Simulator_Sensor_GPS_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_GPS_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
