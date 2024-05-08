//You need not to modify this file.

/*! \defgroup SensorTimer_Sensor_URG SensorTimer_Sensor_URG
	\ingroup SensorTimer_Library Sensor_URG_NodeClass
	\brief SensorTimer_Sensor_URG defines the Sensor_URG in SensorTimer.
*/

#ifndef SENSORTIMER_SENSOR_URG_PRIVCOREFUNC_H
#define SENSORTIMER_SENSOR_URG_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_Sensor_URG_PrivCoreFunc SensorTimer_Sensor_URG_PrivCoreFunc
	\ingroup SensorTimer_Sensor_URG
	\brief SensorTimer_Sensor_URG_PrivCoreFunc defines the PrivCoreFunc in SensorTimer_Sensor_URG.
*/

/*! \addtogroup SensorTimer_Sensor_URG_PrivCoreFunc
	@{
*/

/*! \file SensorTimer_Sensor_URG_PrivCoreFunc.h
	 Defines the PrivCoreFunc of SensorTimer_Sensor_URG
*/

//*******************Please add other headers below*******************


#include "../Edit/SensorTimer_Sensor_URG_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG SensorTimer_Sensor_URG

/*! void SensorTimer_Sensor_URG_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void SensorTimer_Sensor_URG_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void SensorTimer_Sensor_URG_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif