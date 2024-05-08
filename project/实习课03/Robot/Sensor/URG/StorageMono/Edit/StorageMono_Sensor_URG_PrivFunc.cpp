//You need to program this file.

#include "../NoEdit/StorageMono_Sensor_URG_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	StorageMono_Sensor_URG_Params * params=(StorageMono_Sensor_URG_Params *)paramsPtr;
	StorageMono_Sensor_URG_Vars * vars=(StorageMono_Sensor_URG_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,filename);
    GetParamValue(xmlloader,params,storagePath);
    QString filename=QString("%1/%2").arg(params->storagePath).arg(params->filename);
    vars->file.setFileName(filename);
    if(vars->file.open(QFile::WriteOnly)) {
        vars->writehead=1;
        return 1;
    } else {
        return 0;
    }
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	StorageMono_Sensor_URG_Params * params=(StorageMono_Sensor_URG_Params *)paramsPtr;
	StorageMono_Sensor_URG_Vars * vars=(StorageMono_Sensor_URG_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->file.close();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	StorageMono_Sensor_URG_Params * params=(StorageMono_Sensor_URG_Params *)paramsPtr;
	StorageMono_Sensor_URG_Vars * vars=(StorageMono_Sensor_URG_Vars *)varsPtr;
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

void DECOFUNC(getMonoDrainDataSize)(void * paramsPtr, void * varsPtr, int & drainDataSize)
{
	StorageMono_Sensor_URG_Params * params=(StorageMono_Sensor_URG_Params *)paramsPtr;
	StorageMono_Sensor_URG_Vars * vars=(StorageMono_Sensor_URG_Vars *)varsPtr;
    drainDataSize=-1;
	/*======Please Program above======*/
	/*
	Function: get drain data size to be grabbed from buffer.
	Rules:
	drainDataSize=0: grab and remove all data from buffer.
	drainDataSize>0: grab drainDataSize latest data from buffer.
	drainDataSize<0: grab and remove drainDataSize ancient data from buffer.
	*/
}

//Input Port #0: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_URG_Params, Data_Type = SensorTimer_Sensor_URG_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	StorageMono_Sensor_URG_Params * params=(StorageMono_Sensor_URG_Params *)paramsPtr;
	StorageMono_Sensor_URG_Vars * vars=(StorageMono_Sensor_URG_Vars *)varsPtr;
	QVector<SensorTimer_Sensor_URG_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<SensorTimer_Sensor_URG_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    if(vars->writehead) {
        float angrng = (drainparams.front()->last_step - drainparams.front()->first_step) * 0.25;
        float angres = drainparams.front()->skip_step * 0.25;
        float unit=100.0;
        vars->file.write((char *)&angrng, sizeof(angrng));
        vars->file.write((char *)&angres, sizeof(angres));
        vars->file.write((char *)&unit, sizeof(unit));
        vars->writehead=0;
    }
    int n=drainData.size();
    if (n == 0) {
        return 0;
    }
    for (int i = n-1; i >= 0; i--) {
        SensorTimer_Sensor_URG_Data * data=(SensorTimer_Sensor_URG_Data *)drainData[i];
        int timestamp=((data->qtimestamp.hour() * 60 + data->qtimestamp.minute()) * 60 +
                        data->qtimestamp.second()) * 1000 + data->qtimestamp.msec();
        vars->file.write((char *)&timestamp, sizeof(timestamp));
        vars->file.write((char *)(data->data), sizeof(short) * (data->datasize));
    }
	return 1;
}

