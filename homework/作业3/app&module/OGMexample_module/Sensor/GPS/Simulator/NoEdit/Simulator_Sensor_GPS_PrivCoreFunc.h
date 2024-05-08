//You need not to modify this file.

/*! \defgroup Simulator_Sensor_GPS Simulator_Sensor_GPS
	\ingroup Simulator_Library Sensor_GPS_NodeClass
	\brief Simulator_Sensor_GPS defines the Sensor_GPS in Simulator.
*/

#ifndef SIMULATOR_SENSOR_GPS_PRIVCOREFUNC_H
#define SIMULATOR_SENSOR_GPS_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_GPS_PrivCoreFunc Simulator_Sensor_GPS_PrivCoreFunc
	\ingroup Simulator_Sensor_GPS
	\brief Simulator_Sensor_GPS_PrivCoreFunc defines the PrivCoreFunc in Simulator_Sensor_GPS.
*/

/*! \addtogroup Simulator_Sensor_GPS_PrivCoreFunc
	@{
*/

/*! \file Simulator_Sensor_GPS_PrivCoreFunc.h
	 Defines the PrivCoreFunc of Simulator_Sensor_GPS
*/

//*******************Please add other headers below*******************


#include "../Edit/Simulator_Sensor_GPS_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG Simulator_Sensor_GPS

/*! void Simulator_Sensor_GPS_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void Simulator_Sensor_GPS_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void Simulator_Sensor_GPS_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif