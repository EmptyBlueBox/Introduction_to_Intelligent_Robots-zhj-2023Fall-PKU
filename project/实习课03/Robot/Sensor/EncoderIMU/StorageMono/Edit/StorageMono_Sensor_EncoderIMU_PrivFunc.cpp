//You need to program this file.

#include "../NoEdit/StorageMono_Sensor_EncoderIMU_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	StorageMono_Sensor_EncoderIMU_Params * params=(StorageMono_Sensor_EncoderIMU_Params *)paramsPtr;
	StorageMono_Sensor_EncoderIMU_Vars * vars=(StorageMono_Sensor_EncoderIMU_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, filename);
    GetParamValue(xmlloader, params, storagePath);
    QString filename=QString("%1/%2").arg(params->storagePath).arg(params->filename);
    vars->fwriter.setFileName(filename);

    if(!vars->fwriter.open(QFile::WriteOnly | QFile::Text))
    {
        return 0;
    }
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	StorageMono_Sensor_EncoderIMU_Params * params=(StorageMono_Sensor_EncoderIMU_Params *)paramsPtr;
	StorageMono_Sensor_EncoderIMU_Vars * vars=(StorageMono_Sensor_EncoderIMU_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    if (vars->fwriter.isOpen()) {
        vars->fwriter.close();
    }
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	StorageMono_Sensor_EncoderIMU_Params * params=(StorageMono_Sensor_EncoderIMU_Params *)paramsPtr;
	StorageMono_Sensor_EncoderIMU_Vars * vars=(StorageMono_Sensor_EncoderIMU_Vars *)varsPtr;
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
	StorageMono_Sensor_EncoderIMU_Params * params=(StorageMono_Sensor_EncoderIMU_Params *)paramsPtr;
	StorageMono_Sensor_EncoderIMU_Vars * vars=(StorageMono_Sensor_EncoderIMU_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = SourceDrainMono_Sensor_EncoderIMU_Params, Data_Type = SourceDrainMono_Sensor_EncoderIMU_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	StorageMono_Sensor_EncoderIMU_Params * params=(StorageMono_Sensor_EncoderIMU_Params *)paramsPtr;
	StorageMono_Sensor_EncoderIMU_Vars * vars=(StorageMono_Sensor_EncoderIMU_Vars *)varsPtr;
	QVector<SourceDrainMono_Sensor_EncoderIMU_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<SourceDrainMono_Sensor_EncoderIMU_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    for(int i = draindata.size() - 1; i >= 0; i--) {
        SourceDrainMono_Sensor_EncoderIMU_Data *data=(SourceDrainMono_Sensor_EncoderIMU_Data*)drainData[i];
        long timestamp = ((data->qtimestamp.hour() * 60 + data->qtimestamp.minute()) * 60
            + data->qtimestamp.second()) * 1000 + data->qtimestamp.msec();

        vars->fwriter.write(QString("%1\t%2\t%3\t%4\t%5\t%6\t%7\n").arg(timestamp).arg(data->x).arg(data->y)
            .arg(data->orientation).arg(data->speed).arg(data->encoderRawData).arg(data->backDis).toUtf8());
    }
	return 1;
}

