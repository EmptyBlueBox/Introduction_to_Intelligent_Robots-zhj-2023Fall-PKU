//Generally you need not to program this file.

#include "VisualizationMulti_Show_LocationAndMap_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=VisualizationMulti_Show_LocationAndMap_INPUTPORTSSIZE;
	outputPortsNumber=VisualizationMulti_Show_LocationAndMap_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new VisualizationMulti_Show_LocationAndMap_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new VisualizationMulti_Show_LocationAndMap_Vars());
	/*======No Need to Program======*/
}

