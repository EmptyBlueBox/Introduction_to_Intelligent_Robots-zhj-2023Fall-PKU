//You need not to modify this file.

/*! \defgroup VisualizationMono_Sensor_xtion VisualizationMono_Sensor_xtion
	\ingroup VisualizationMono_Library Sensor_xtion_NodeClass
	\brief VisualizationMono_Sensor_xtion defines the Sensor_xtion in VisualizationMono.
*/

#ifndef VISUALIZATIONMONO_SENSOR_XTION_PRIVCOREFUNC_H
#define VISUALIZATIONMONO_SENSOR_XTION_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_xtion_PrivCoreFunc VisualizationMono_Sensor_xtion_PrivCoreFunc
	\ingroup VisualizationMono_Sensor_xtion
	\brief VisualizationMono_Sensor_xtion_PrivCoreFunc defines the PrivCoreFunc in VisualizationMono_Sensor_xtion.
*/

/*! \addtogroup VisualizationMono_Sensor_xtion_PrivCoreFunc
	@{
*/

/*! \file VisualizationMono_Sensor_xtion_PrivCoreFunc.h
	 Defines the PrivCoreFunc of VisualizationMono_Sensor_xtion
*/

//*******************Please add other headers below*******************


#include "../Edit/VisualizationMono_Sensor_xtion_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG VisualizationMono_Sensor_xtion

/*! void VisualizationMono_Sensor_xtion_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void VisualizationMono_Sensor_xtion_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void VisualizationMono_Sensor_xtion_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif