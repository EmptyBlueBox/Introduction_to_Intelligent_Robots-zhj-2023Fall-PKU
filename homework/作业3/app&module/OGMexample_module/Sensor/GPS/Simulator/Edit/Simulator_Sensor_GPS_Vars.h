//You need to modify this file.

#ifndef SIMULATOR_SENSOR_GPS_VARS_H
#define SIMULATOR_SENSOR_GPS_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_GPS_Vars Simulator_Sensor_GPS_Vars
	\ingroup Simulator_Sensor_GPS
	\brief Simulator_Sensor_GPS_Vars defines the Vars in Simulator_Sensor_GPS.
*/

/*! \addtogroup Simulator_Sensor_GPS_Vars
	@{
*/

/*! \file Simulator_Sensor_GPS_Vars.h
	 Defines the Vars of Simulator_Sensor_GPS
*/

//*******************Please add other headers below*******************
#include <fstream>

#include "Simulator_Sensor_GPS_ParamsData.h"

//The Vars is defined as below
/*! \class Simulator_Sensor_GPS_Vars 
	\brief The Vars of Simulator_Sensor_GPS.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_GPS_Vars 
{
public:
	/*! \fn Simulator_Sensor_GPS_Vars()
		\brief The constructor of Simulator_Sensor_GPS_Vars. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_GPS_Vars() 
	{
        path="/home/rsys/Build/APP/example_app2";
        filename="a-XW-20160801135224.nav";
	}
	/*! \fn ~Simulator_Sensor_GPS_Vars()
		\brief The destructor of Simulator_Sensor_GPS_Vars. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_GPS_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    std::ifstream file;
    QString path;
    QString filename;
    double iniX;
    double iniY;
    double iniOri;
    bool isInit;
};

/*! @}*/ 

#endif
