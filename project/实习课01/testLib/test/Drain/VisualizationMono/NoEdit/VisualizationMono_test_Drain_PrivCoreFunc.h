//You need not to modify this file.

/*! \defgroup VisualizationMono_test_Drain VisualizationMono_test_Drain
	\ingroup VisualizationMono_Library test_Drain_NodeClass
	\brief VisualizationMono_test_Drain defines the test_Drain in VisualizationMono.
*/

#ifndef VISUALIZATIONMONO_TEST_DRAIN_PRIVCOREFUNC_H
#define VISUALIZATIONMONO_TEST_DRAIN_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_test_Drain_PrivCoreFunc VisualizationMono_test_Drain_PrivCoreFunc
	\ingroup VisualizationMono_test_Drain
	\brief VisualizationMono_test_Drain_PrivCoreFunc defines the PrivCoreFunc in VisualizationMono_test_Drain.
*/

/*! \addtogroup VisualizationMono_test_Drain_PrivCoreFunc
	@{
*/

/*! \file VisualizationMono_test_Drain_PrivCoreFunc.h
	 Defines the PrivCoreFunc of VisualizationMono_test_Drain
*/

//*******************Please add other headers below*******************


#include "../Edit/VisualizationMono_test_Drain_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG VisualizationMono_test_Drain

/*! void VisualizationMono_test_Drain_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void VisualizationMono_test_Drain_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void VisualizationMono_test_Drain_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif