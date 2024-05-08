//You need to program this file.

#include "../NoEdit/StorageMono_Sensor_xtion_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
    XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
    StorageMono_Sensor_xtion_Params * params=(StorageMono_Sensor_xtion_Params *)paramsPtr;
    StorageMono_Sensor_xtion_Vars * vars=(StorageMono_Sensor_xtion_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: open node.
    Procedure:
    1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
    2: initialize variables (vars).
    3: If everything is OK, return 1 for successful opening and vice versa.
    */
    GetParamValue(xmlloader, params, colorFilename);
    GetParamValue(xmlloader, params, depthFilename);
    GetParamValue(xmlloader, params, storagePath);
    GetParamValue(xmlloader, params, width);
    GetParamValue(xmlloader, params, height);
    GetParamValue(xmlloader, params, fps);

    QString colorFilename = QString("%1/%2").arg(params->storagePath).arg(params->colorFilename);
    QString depthFilename = QString("%1/%2").arg(params->storagePath).arg(params->depthFilename);
    QDir colorDir(colorFilename);
    QDir depthDir(depthFilename);
    QString colorFilepath = colorDir.absolutePath();
    QString depthFilepath = depthDir.absolutePath();
    bool flag = true;
    flag &= !colorDir.exists();
    flag &= !depthDir.exists();
    flag &= colorDir.mkdir(colorFilepath);
    flag &= depthDir.mkdir(depthFilepath);
    vars->timestampWriter.setFileName(QString("%1_timestamp.log").arg(colorFilename));
    vars->colorDir = colorFilepath;
    vars->depthDir = depthFilepath;
    flag &= vars->timestampWriter.open(QFile::WriteOnly | QFile::Text);
    if (!flag) {
        vars->timestampWriter.close();
        return 0;
    }
    vars->frameNum = 0;
    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
    StorageMono_Sensor_xtion_Params * params=(StorageMono_Sensor_xtion_Params *)paramsPtr;
    StorageMono_Sensor_xtion_Vars * vars=(StorageMono_Sensor_xtion_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: close node.
    Procedure:
    1: handle/close variables (vars).
    2: If everything is OK, return 1 for successful closing and vice versa.
    */
    if (vars->timestampWriter.isOpen()) {
        vars->timestampWriter.close();
    }
    return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
    StorageMono_Sensor_xtion_Params * params=(StorageMono_Sensor_xtion_Params *)paramsPtr;
    StorageMono_Sensor_xtion_Vars * vars=(StorageMono_Sensor_xtion_Vars *)varsPtr;
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
    StorageMono_Sensor_xtion_Params * params=(StorageMono_Sensor_xtion_Params *)paramsPtr;
    StorageMono_Sensor_xtion_Vars * vars=(StorageMono_Sensor_xtion_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_xtion_Params, Data_Type = SensorTimer_Sensor_xtion_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
    StorageMono_Sensor_xtion_Params * params=(StorageMono_Sensor_xtion_Params *)paramsPtr;
    StorageMono_Sensor_xtion_Vars * vars=(StorageMono_Sensor_xtion_Vars *)varsPtr;
    QVector<SensorTimer_Sensor_xtion_Params *> drainparams; copyQVector(drainparams,drainParams);
    QVector<SensorTimer_Sensor_xtion_Data *> draindata; copyQVector(draindata,drainData);
    if(draindata.size()==0){return 0;}
    /*======Please Program below======*/
    /*
    Function: process draindata.
    */
    for (int i = draindata.size() - 1; i >= 0; i--)
    {
        SensorTimer_Sensor_xtion_Data *data = draindata[i];
        int timestamp=((data->qtimestamp.hour() * 60 + data->qtimestamp.minute()) * 60
                        + data->qtimestamp.second()) * 1000 + data->qtimestamp.msec();
        vars->timestampWriter.write(QString("%1\n").arg(timestamp).toUtf8());
        QString colorFilename = QString("%1/%2.jpg").arg(vars->colorDir).arg(vars->frameNum);
        QString depthFilename = QString("%1/%2.png").arg(vars->depthDir).arg(vars->frameNum);
        vars->frameNum++;
        cv::imwrite(colorFilename.toStdString(), data->cvColorImg);
        cv::imwrite(depthFilename.toStdString(), data->cvDepthImg);
    }
    return 1;
}

