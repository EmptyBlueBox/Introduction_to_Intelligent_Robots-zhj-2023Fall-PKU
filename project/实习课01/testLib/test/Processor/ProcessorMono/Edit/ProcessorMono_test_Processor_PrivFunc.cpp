//You need to program this file.

#include "../NoEdit/ProcessorMono_test_Processor_PrivFunc.h"
#include <opencv2/opencv.hpp>

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMono_test_Processor_Params * params=(ProcessorMono_test_Processor_Params *)paramsPtr;
	ProcessorMono_test_Processor_Vars * vars=(ProcessorMono_test_Processor_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, startx);
    GetParamValue(xmlloader, params, starty);
    GetParamValue(xmlloader, params, width);
    GetParamValue(xmlloader, params, height);
    GetParamValue(xmlloader, params, step);
    vars->currentx = params->startx;
    vars->currenty = params->starty;
    vars->index    = -1;
    vars->tot      = 0;
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMono_test_Processor_Params * params=(ProcessorMono_test_Processor_Params *)paramsPtr;
	ProcessorMono_test_Processor_Vars * vars=(ProcessorMono_test_Processor_Vars *)varsPtr;
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
	ProcessorMono_test_Processor_Params * params=(ProcessorMono_test_Processor_Params *)paramsPtr;
	ProcessorMono_test_Processor_Vars * vars=(ProcessorMono_test_Processor_Vars *)varsPtr;
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
	ProcessorMono_test_Processor_Params * params=(ProcessorMono_test_Processor_Params *)paramsPtr;
	ProcessorMono_test_Processor_Vars * vars=(ProcessorMono_test_Processor_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMono_test_Processor_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMonoInputDataSize)(void * paramsPtr, void * varsPtr, int & inputDataSize)
{
	ProcessorMono_test_Processor_Params * params=(ProcessorMono_test_Processor_Params *)paramsPtr;
	ProcessorMono_test_Processor_Vars * vars=(ProcessorMono_test_Processor_Vars *)varsPtr;
	inputDataSize=0;
	/*======Please Program above======*/
	/*
	Function: get input data size to be grabbed from buffer.
	Rules:
	inputDataSize=0: grab and remove all data from buffer.
	inputDataSize>0: grab inputDataSize latest data from buffer.
	inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
	*/
}

//------------------------------------------------Key Code------------------------------------------------------------------------------------------
int CalcDirection(SensorTimer_test_Source_Data * inputdata, int i)
{
    // inputdata->keyPoint[i][0..1] is the ith key point position(x, y)
    // Return the direction of the car [0 - up][1 - down][2 - left][3 - right][4 - stop]
    return 4;
}
//-------------------------------------------------Key Code-----------------------------------------------------------------------------------------

//Input Port #0: Buffer_Size = 10, Params_Type = SensorTimer_test_Source_Params, Data_Type = SensorTimer_test_Source_Data
bool DECOFUNC(processMonoInputData)(void * paramsPtr, void * varsPtr, QVector<void *> inputParams, QVector<void *> inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMono_test_Processor_Params * params=(ProcessorMono_test_Processor_Params *)paramsPtr;
	ProcessorMono_test_Processor_Vars * vars=(ProcessorMono_test_Processor_Vars *)varsPtr;
	QVector<SensorTimer_test_Source_Params *> inputparams; copyQVector(inputparams,inputParams);
	QVector<SensorTimer_test_Source_Data *> inputdata; copyQVector(inputdata,inputData);
	ProcessorMono_test_Processor_Data * outputdata=(ProcessorMono_test_Processor_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/

    //---------------------------------------------------Key Code---------------------------------------------------------------------------------------

    int direction = 0;  // Direction of the car [0 - up][1 - down][2 - left][3 - right]

    // Initialization. Set the Car to the start point
    if (vars->index == -1){
        vars->currentx = inputdata[0]->keyPoint[0][0];
        vars->currenty = inputdata[0]->keyPoint[0][1];
        vars->tot = inputdata[0]->tot;
        vars->index = 0;
    }

    // Reach the next key point, so index ++
    if (vars->currentx == inputdata[0]->keyPoint[vars->index + 1][0]
     && vars->currenty == inputdata[0]->keyPoint[vars->index + 1][1]) {
        vars->index ++;
    }

    // Reached the last key point or not ?
    if (vars->index < vars->tot - 1) {
        direction = CalcDirection(inputdata[0] , vars->index + 1); // Calculate current direction of the car
    }
    else {
        vars->index = -1;   // Set the car to initial point
    }

    // Output data for visualization
    outputdata->direction = (ProcessorMono_test_Processor_Data::Direction)direction;
    outputdata->x = vars->currentx + vars->dx[direction] * params->step;
    outputdata->y = vars->currenty + vars->dy[direction] * params->step;

    // Update current position
    vars->currentx = outputdata->x;
    vars->currenty = outputdata->y;

    //----------------------------------------------------Key Code--------------------------------------------------------------------------------------
	return 1;
}

