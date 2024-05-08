//You need to program this file.

#include "../NoEdit/SensorTimer_test_Source_PrivFunc.h"
#include <fstream>

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorTimer_test_Source_Params * params=(SensorTimer_test_Source_Params *)paramsPtr;
	SensorTimer_test_Source_Vars * vars=(SensorTimer_test_Source_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
    */

    //---------------------------------------------------Key Code---------------------------------------------------------------------------------------

    int tmpX, tmpY;
    std::fstream fin;
    fin.open("/home/rsys/SDK/RobotSDK/ModuleDev/testLib/path.txt",std::ios::in);    // Load path of "POSS"
    while (fin >> tmpX >> tmpY) {
        vars->keyPoint[vars->tot][0] = tmpX;
        vars->keyPoint[vars->tot][1] = tmpY;
        vars->tot ++;
    }
    //---------------------------------------------------Key Code---------------------------------------------------------------------------------------

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorTimer_test_Source_Params * params=(SensorTimer_test_Source_Params *)paramsPtr;
	SensorTimer_test_Source_Vars * vars=(SensorTimer_test_Source_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
	
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SensorTimer_test_Source_Params * params=(SensorTimer_test_Source_Params *)paramsPtr;
	SensorTimer_test_Source_Vars * vars=(SensorTimer_test_Source_Vars *)varsPtr;
	internalTrigger=NULL;
	internalTriggerSignal=QString();
	/*======Occasionally Program above======*/
	/*
	Function: get internal trigger [defined in vars] for node.
	You need to program here when you need internal trigger (internalTrigger + internalTriggerSignal) for node.
	E.g.
	internalTrigger=&(vars->trigger);
	internalTriggerSignal=QString(SIGNAL(triggerSignal()));
	*/
}

void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
{
	SensorTimer_test_Source_Params * params=(SensorTimer_test_Source_Params *)paramsPtr;
	SensorTimer_test_Source_Vars * vars=(SensorTimer_test_Source_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SensorTimer_test_Source_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorTimer_test_Source_Params * params=(SensorTimer_test_Source_Params *)paramsPtr;
	SensorTimer_test_Source_Vars * vars=(SensorTimer_test_Source_Vars *)varsPtr;
	SensorTimer_test_Source_Data * outputdata=(SensorTimer_test_Source_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    //---------------------------------------------------Key Code---------------------------------------------------------------------------------------

    memcpy(outputdata->keyPoint, vars->keyPoint, sizeof(vars->keyPoint));   // Assign keyPoint to output data
    outputdata->tot = vars->tot;
    //---------------------------------------------------Key Code---------------------------------------------------------------------------------------

	return 1;
}

