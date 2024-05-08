//You need to program this file.

#include "../NoEdit/Simulator_Sensor_GPS_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
    XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
    Simulator_Sensor_GPS_Params * params=(Simulator_Sensor_GPS_Params *)paramsPtr;
    Simulator_Sensor_GPS_Vars * vars=(Simulator_Sensor_GPS_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: open node.
    Procedure:
    1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
    2: initialize variables (vars).
    3: If everything is OK, return 1 for successful opening and vice versa.
    */
    GetParamValue(xmlloader,vars,path);
    GetParamValue(xmlloader,vars,filename);
    vars->file.open(QString("%1/%2").arg(vars->path).arg(vars->filename).toStdString().c_str(),std::ios::in);
    vars->isInit=true;
    return vars->file.is_open();
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
    Simulator_Sensor_GPS_Params * params=(Simulator_Sensor_GPS_Params *)paramsPtr;
    Simulator_Sensor_GPS_Vars * vars=(Simulator_Sensor_GPS_Vars *)varsPtr;
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
    Simulator_Sensor_GPS_Params * params=(Simulator_Sensor_GPS_Params *)paramsPtr;
    Simulator_Sensor_GPS_Vars * vars=(Simulator_Sensor_GPS_Vars *)varsPtr;
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
    Simulator_Sensor_GPS_Params * params=(Simulator_Sensor_GPS_Params *)paramsPtr;
    Simulator_Sensor_GPS_Vars * vars=(Simulator_Sensor_GPS_Vars *)varsPtr;
    outputDataPtr=boost::shared_ptr<void>(new Simulator_Sensor_GPS_Data());
    /*======Occasionally Program below/above======*/
    /*
    Function: initial output data.
    You need to program here when you need to manually initialize output data.
    */

}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
    Simulator_Sensor_GPS_Params * params=(Simulator_Sensor_GPS_Params *)paramsPtr;
    Simulator_Sensor_GPS_Vars * vars=(Simulator_Sensor_GPS_Vars *)varsPtr;
    Simulator_Sensor_GPS_Data * outputdata=(Simulator_Sensor_GPS_Data *)outputData;
    outputPortIndex=QList<int>();
    timeStamp=QTime();
    /*======Please Program below======*/
    /*
    Step 1: fill outputdata.
    Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
    E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
    Step 3: set the timeStamp for Simulator.
    */

    double tmp;
    double x,y,ori;
    //    if(!(vars->file.peek()==EOF)){
    if(vars->file>>outputdata->timestamp){
        vars->file>>tmp;
        vars->file>>tmp;
        vars->file>>ori;//rad
        vars->file>>x;
        vars->file>>y;
        vars->file>>tmp;
        timeStamp=QTime::fromMSecsSinceStartOfDay(outputdata->timestamp);

        if(vars->isInit){
            vars->isInit=false;
            vars->iniX=x;
            vars->iniY=y;
            vars->iniOri=ori;
        }

        outputdata->x=x-vars->iniX;
        outputdata->y=-(y-vars->iniY);
        outputdata->ori=-ori-3.1415926/2;





        return 1;
    }
    else
        return 0;
}
