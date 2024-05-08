//You need not to modify this file.

/*! \defgroup ProcessorMono_test_Processor ProcessorMono_test_Processor
	\ingroup ProcessorMono_Library test_Processor_NodeClass
	\brief ProcessorMono_test_Processor defines the test_Processor in ProcessorMono.
*/

#ifndef PROCESSORMONO_TEST_PROCESSOR_PRIVCOREFUNC_H
#define PROCESSORMONO_TEST_PROCESSOR_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_test_Processor_PrivCoreFunc ProcessorMono_test_Processor_PrivCoreFunc
	\ingroup ProcessorMono_test_Processor
	\brief ProcessorMono_test_Processor_PrivCoreFunc defines the PrivCoreFunc in ProcessorMono_test_Processor.
*/

/*! \addtogroup ProcessorMono_test_Processor_PrivCoreFunc
	@{
*/

/*! \file ProcessorMono_test_Processor_PrivCoreFunc.h
	 Defines the PrivCoreFunc of ProcessorMono_test_Processor
*/

//*******************Please add other headers below*******************


#include "../Edit/ProcessorMono_test_Processor_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG ProcessorMono_test_Processor

/*! void ProcessorMono_test_Processor_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void ProcessorMono_test_Processor_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void ProcessorMono_test_Processor_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif