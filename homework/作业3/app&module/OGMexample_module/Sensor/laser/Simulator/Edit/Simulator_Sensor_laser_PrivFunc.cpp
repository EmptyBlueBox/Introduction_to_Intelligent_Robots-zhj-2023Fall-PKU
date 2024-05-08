//You need to program this file.

#include "../NoEdit/Simulator_Sensor_laser_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	Simulator_Sensor_laser_Params * params=(Simulator_Sensor_laser_Params *)paramsPtr;
	Simulator_Sensor_laser_Vars * vars=(Simulator_Sensor_laser_Vars *)varsPtr;
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
  //  GetParamValue(xmlloader,params,nearfilter);
  //  GetParamValue(xmlloader,params,farfilter);
    vars->file.open(QString("%1/%2").arg(vars->path).arg(vars->filename).toStdString().c_str(),std::ios::binary |std::ios::in);

    if(!vars->file.is_open()){
        return 0;
    }
    float para[3];
    vars->file.read((char*)para,sizeof(float)*3);
    params->rng=para[0];
    params->res=para[1];
    params->unit=para[2];
    int tmp;
    vars->file.read((char *)&(tmp),sizeof(tmp));
    for (int i=0;i<params->rng/params->res+1;i++){
        short a;
        vars->file.read((char*)&a,sizeof(short));
    }
    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	Simulator_Sensor_laser_Params * params=(Simulator_Sensor_laser_Params *)paramsPtr;
	Simulator_Sensor_laser_Vars * vars=(Simulator_Sensor_laser_Vars *)varsPtr;
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
	Simulator_Sensor_laser_Params * params=(Simulator_Sensor_laser_Params *)paramsPtr;
	Simulator_Sensor_laser_Vars * vars=(Simulator_Sensor_laser_Vars *)varsPtr;
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
	Simulator_Sensor_laser_Params * params=(Simulator_Sensor_laser_Params *)paramsPtr;
	Simulator_Sensor_laser_Vars * vars=(Simulator_Sensor_laser_Vars *)varsPtr;
    outputDataPtr=boost::shared_ptr<void>(new Simulator_Sensor_laser_Data(params->rng/params->res+1));
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	Simulator_Sensor_laser_Params * params=(Simulator_Sensor_laser_Params *)paramsPtr;
	Simulator_Sensor_laser_Vars * vars=(Simulator_Sensor_laser_Vars *)varsPtr;
	Simulator_Sensor_laser_Data * outputdata=(Simulator_Sensor_laser_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/

//    if(vars->file.peek()==EOF)
//    {
//        return 0;
//    }
    int tmp;

    if(vars->file.read((char *)&(tmp),sizeof(tmp))){

    int datalen=params->rng/params->res+1;


    outputdata->timestamp=tmp;

    vars->file.read((char *)outputdata->data,sizeof(short)*datalen);


    for(int i=0;i<datalen;i++)
    {
        if(outputdata->data[i]/params->unit<params->nearThres||outputdata->data[i]/params->unit>params->farThres)
        {
            outputdata->data[i]=0;
        }
    }

    timeStamp=QTime::fromMSecsSinceStartOfDay(outputdata->timestamp);
    return 1;}
    else
        return 0;
}



