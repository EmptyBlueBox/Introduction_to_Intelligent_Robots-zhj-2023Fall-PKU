//You need to program this file.

#include "../NoEdit/SensorTimer_Sensor_URG_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorTimer_Sensor_URG_Params * params=(SensorTimer_Sensor_URG_Params *)paramsPtr;
	SensorTimer_Sensor_URG_Vars * vars=(SensorTimer_Sensor_URG_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetEnumParamValue(xmlloader, params, connection_type);
    GetParamValue(xmlloader, params, device_or_address);
    GetParamValue(xmlloader, params, baudreate_or_port);
    GetEnumParamValue(xmlloader, params, measurement_type);
    GetParamValue(xmlloader, params, skip_scan);
    GetParamValue(xmlloader, params, first_step);
    GetParamValue(xmlloader, params, last_step);
    GetParamValue(xmlloader, params, skip_step);
    GetParamValue(xmlloader, params, nearfilter);
    GetParamValue(xmlloader, params, farfilter);
    GetParamValue(xmlloader, params, unit);

    int rc;
    rc = urg_open(&(vars->urg), params->connection_type, params->device_or_address.toUtf8().data(),
                     params->baudreate_or_port);
    if (rc < 0) {
        return 0;
    }
    rc = urg_set_scanning_parameter(&(vars->urg), params->first_step, params->last_step, params->skip_step);
    if (rc < 0) {
        return 0;
    }
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorTimer_Sensor_URG_Params * params=(SensorTimer_Sensor_URG_Params *)paramsPtr;
	SensorTimer_Sensor_URG_Vars * vars=(SensorTimer_Sensor_URG_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    urg_close(&(vars->urg));
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SensorTimer_Sensor_URG_Params * params=(SensorTimer_Sensor_URG_Params *)paramsPtr;
	SensorTimer_Sensor_URG_Vars * vars=(SensorTimer_Sensor_URG_Vars *)varsPtr;
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
	SensorTimer_Sensor_URG_Params * params=(SensorTimer_Sensor_URG_Params *)paramsPtr;
	SensorTimer_Sensor_URG_Vars * vars=(SensorTimer_Sensor_URG_Vars *)varsPtr;
    int beamNumber = (params->last_step - params->first_step) / params->skip_step + 1;
    outputDataPtr=boost::shared_ptr<void>(new SensorTimer_Sensor_URG_Data(beamNumber));
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorTimer_Sensor_URG_Params * params=(SensorTimer_Sensor_URG_Params *)paramsPtr;
	SensorTimer_Sensor_URG_Vars * vars=(SensorTimer_Sensor_URG_Vars *)varsPtr;
	SensorTimer_Sensor_URG_Data * outputdata=(SensorTimer_Sensor_URG_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    long *urgdata = new long[outputdata->datasize];
    urg_start_measurement(&(vars->urg), params->measurement_type, 1, params->skip_scan);
    long timestamp;
    int num = urg_get_distance(&(vars->urg), urgdata, &(timestamp));
    outputdata->qtimestamp = QTime::currentTime();
    if(num <= 0 || num != outputdata->datasize) {
        return 0;
    }

    for(int i = 0; i < num; i++) {
        short distance = short(urgdata[i] / 10.0 + 0.5);
        if (distance < params->nearfilter || distance > params->farfilter) {
            outputdata->data[i] = 0;
        } else {
            outputdata->data[i] = distance;
        }
    }
	return 1;
}

