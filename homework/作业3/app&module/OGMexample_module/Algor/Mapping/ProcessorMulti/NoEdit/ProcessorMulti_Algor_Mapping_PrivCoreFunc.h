//You need not to modify this file.

/*! \defgroup ProcessorMulti_Algor_Mapping ProcessorMulti_Algor_Mapping
	\ingroup ProcessorMulti_Library Algor_Mapping_NodeClass
	\brief ProcessorMulti_Algor_Mapping defines the Algor_Mapping in ProcessorMulti.
*/

#ifndef PROCESSORMULTI_ALGOR_MAPPING_PRIVCOREFUNC_H
#define PROCESSORMULTI_ALGOR_MAPPING_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algor_Mapping_PrivCoreFunc ProcessorMulti_Algor_Mapping_PrivCoreFunc
	\ingroup ProcessorMulti_Algor_Mapping
	\brief ProcessorMulti_Algor_Mapping_PrivCoreFunc defines the PrivCoreFunc in ProcessorMulti_Algor_Mapping.
*/

/*! \addtogroup ProcessorMulti_Algor_Mapping_PrivCoreFunc
	@{
*/

/*! \file ProcessorMulti_Algor_Mapping_PrivCoreFunc.h
	 Defines the PrivCoreFunc of ProcessorMulti_Algor_Mapping
*/

//*******************Please add other headers below*******************


#include "../Edit/ProcessorMulti_Algor_Mapping_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG ProcessorMulti_Algor_Mapping

/*! void ProcessorMulti_Algor_Mapping_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void ProcessorMulti_Algor_Mapping_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void ProcessorMulti_Algor_Mapping_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif