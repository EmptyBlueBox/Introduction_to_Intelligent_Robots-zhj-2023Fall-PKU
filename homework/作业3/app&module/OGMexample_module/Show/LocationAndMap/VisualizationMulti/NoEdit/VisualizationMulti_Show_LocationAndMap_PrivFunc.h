//You need not to modify this file.

#ifndef VISUALIZATIONMULTI_SHOW_LOCATIONANDMAP_PRIVFUNC_H
#define VISUALIZATIONMULTI_SHOW_LOCATIONANDMAP_PRIVFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Show_LocationAndMap_PrivFunc VisualizationMulti_Show_LocationAndMap_PrivFunc
	\ingroup VisualizationMulti_Show_LocationAndMap
	\brief VisualizationMulti_Show_LocationAndMap_PrivFunc defines the PrivFunc in VisualizationMulti_Show_LocationAndMap.
*/

/*! \addtogroup VisualizationMulti_Show_LocationAndMap_PrivFunc
	@{
*/

/*! \file VisualizationMulti_Show_LocationAndMap_PrivFunc.h
	 Defines the PrivFunc of VisualizationMulti_Show_LocationAndMap
*/

//*******************Please add other headers below*******************


#include "../Edit/VisualizationMulti_Show_LocationAndMap_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG VisualizationMulti_Show_LocationAndMap

/*! bool VisualizationMulti_Show_LocationAndMap_setParamsVarsOpenNode(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
	\brief [required] Function pointer type for interface function of setting node's parameters and variables while openning node.
	\param [in] qstrConfigName The config-name of the node.
	\param [in] qstrNodeType The type-name of the node.
	\param [in] qstrNodeClass The class-name of the node.
	\param [in] qstrNodeName The node-name of the node.
	\param [in,out] paramsPtr The parameters(\ref Node::paramsptr) to be loaded.
	\param [in,out] varsPtr The variables(\ref Node::varsptr) to be set
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr);

/*! bool VisualizationMulti_Show_LocationAndMap_handleVarsCloseNode(void * paramsPtr, void * varsPtr)
	\brief [required] Function pointer type for interface function of handling node's variables while closing node.
	\param [in] paramsPtr The parameters(\ref Node::paramsptr) for setting variables.
	\param [in,out] varsPtr The variables(\ref Node::varsptr) to be handled
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr);

/*! void VisualizationMulti_Show_LocationAndMap_getInternalTrigger(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
	\brief [optional] Function pointer type for interface function of getting node's internal trigger.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr) that contains internal trigger.
	\param [out] internalTrigger The internal trigger.
	\param [out] internalTriggerSignal The internal trigger signal embelished by QString.
	\details To embelish internal trigger signal:
	- QString(SIGNAL(<internal trigger signal>));
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal);

/*! void VisualizationMulti_Show_LocationAndMap_getMultiDrainDataSize(void * paramsPtr, void * varsPtr, QList<int> & drainDataSize)
	\brief [required] Function pointer type for interface function of getting multi drain data size.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [out] drainDataSize The required multi drain data size. (see InputNode::grabDrainData(int grabSize))
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getMultiDrainDataSize)(void * paramsPtr, void * varsPtr, QList<int> & drainDataSize);

/*! bool VisualizationMulti_Show_LocationAndMap_processMultiDrainData(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > drainParams, QVector<QVector<void *> > drainData)
	\brief [required] Function pointer type for interface function of processing multi drain data.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [in] drainParams The multi drain parameters of input node.
	\param [in] drainData The multi drain data of input node.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(processMultiDrainData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > drainParams, QVector<QVector<void *> > drainData);

/*! void VisualizationMulti_Show_LocationAndMap_visualizationWidgets(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
	\brief [optional] Function pointer type for interface function of getting node's visualization widgets.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr) that contains visualization widget.
	\param [out] widgets The visualization widgets.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets);

/*! @}*/ 

#endif