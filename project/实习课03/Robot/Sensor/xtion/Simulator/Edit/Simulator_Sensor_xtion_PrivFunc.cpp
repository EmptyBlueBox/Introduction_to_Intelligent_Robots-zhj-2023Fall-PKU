//You need to program this file.

#include "../NoEdit/Simulator_Sensor_xtion_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	Simulator_Sensor_xtion_Params * params=(Simulator_Sensor_xtion_Params *)paramsPtr;
	Simulator_Sensor_xtion_Vars * vars=(Simulator_Sensor_xtion_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, storagePath);
    GetParamValue(xmlloader, params, colorFilename);
    GetParamValue(xmlloader, params, depthFilename);

    QString colorFilename = QString("%1/%2").arg(params->storagePath).arg(params->colorFilename);
    QString depthFilename = QString("%1/%2").arg(params->storagePath).arg(params->depthFilename);
    vars->colorDir = colorFilename;
    vars->depthDir = depthFilename;
    vars->timestampSim.setFileName(QString("%1_timestamp.log").arg(colorFilename));
    if (!vars->timestampSim.open(QFile::ReadOnly | QFile::Text))
    {
        return 0;
    }
    vars->textStream.setDevice(&(vars->timestampSim));
    vars->frameNum = 0;
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	Simulator_Sensor_xtion_Params * params=(Simulator_Sensor_xtion_Params *)paramsPtr;
	Simulator_Sensor_xtion_Vars * vars=(Simulator_Sensor_xtion_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    if (vars->timestampSim.isOpen()) {
        vars->timestampSim.close();
    }
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	Simulator_Sensor_xtion_Params * params=(Simulator_Sensor_xtion_Params *)paramsPtr;
	Simulator_Sensor_xtion_Vars * vars=(Simulator_Sensor_xtion_Vars *)varsPtr;
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
	Simulator_Sensor_xtion_Params * params=(Simulator_Sensor_xtion_Params *)paramsPtr;
	Simulator_Sensor_xtion_Vars * vars=(Simulator_Sensor_xtion_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SensorTimer_Sensor_xtion_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	Simulator_Sensor_xtion_Params * params=(Simulator_Sensor_xtion_Params *)paramsPtr;
	Simulator_Sensor_xtion_Vars * vars=(Simulator_Sensor_xtion_Vars *)varsPtr;
	SensorTimer_Sensor_xtion_Data * outputdata=(SensorTimer_Sensor_xtion_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    if (vars->textStream.atEnd()) {
        return 0;
    }
    QString colorFilename = QString("%1/%2.jpg").arg(vars->colorDir).arg(vars->frameNum);
    QString depthFilename = QString("%1/%2.png").arg(vars->depthDir).arg(vars->frameNum);
    vars->frameNum++;
    outputdata->cvColorImg = cv::imread(colorFilename.toStdString(), 1);
    outputdata->cvDepthImg = cv::imread(depthFilename.toStdString(), -1);
    if (!outputdata->cvColorImg.data || !outputdata->cvDepthImg.data) return 0;
    QTime qtimestamp = QTime::fromMSecsSinceStartOfDay(vars->textStream.readLine().toInt());
    timeStamp = outputdata->qtimestamp = qtimestamp;
	return 1;
}

