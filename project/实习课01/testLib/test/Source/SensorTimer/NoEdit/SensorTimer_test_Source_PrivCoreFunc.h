//You need not to modify this file.

/*! \defgroup SensorTimer_test_Source SensorTimer_test_Source
	\ingroup SensorTimer_Library test_Source_NodeClass
	\brief SensorTimer_test_Source defines the test_Source in SensorTimer.
*/

#ifndef SENSORTIMER_TEST_SOURCE_PRIVCOREFUNC_H
#define SENSORTIMER_TEST_SOURCE_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_test_Source_PrivCoreFunc SensorTimer_test_Source_PrivCoreFunc
	\ingroup SensorTimer_test_Source
	\brief SensorTimer_test_Source_PrivCoreFunc defines the PrivCoreFunc in SensorTimer_test_Source.
*/

/*! \addtogroup SensorTimer_test_Source_PrivCoreFunc
	@{
*/

/*! \file SensorTimer_test_Source_PrivCoreFunc.h
	 Defines the PrivCoreFunc of SensorTimer_test_Source
*/

//*******************Please add other headers below*******************


#include "../Edit/SensorTimer_test_Source_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG SensorTimer_test_Source

/*! void SensorTimer_test_Source_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void SensorTimer_test_Source_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void SensorTimer_test_Source_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif