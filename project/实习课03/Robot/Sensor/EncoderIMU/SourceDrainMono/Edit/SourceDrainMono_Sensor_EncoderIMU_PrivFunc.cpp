//You need to program this file.

#include "../NoEdit/SourceDrainMono_Sensor_EncoderIMU_PrivFunc.h"
#include <QDebug>
//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
    XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
    SourceDrainMono_Sensor_EncoderIMU_Params * params=(SourceDrainMono_Sensor_EncoderIMU_Params *)paramsPtr;
    SourceDrainMono_Sensor_EncoderIMU_Vars * vars=(SourceDrainMono_Sensor_EncoderIMU_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: open node.
    Procedure:
    1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
    2: initialize variables (vars).
    3: If everything is OK, return 1 for successful opening and vice versa.
    */
    GetParamValue(xmlloader, vars, port);
    GetEnumParamValue(xmlloader, vars, baudrate);
    GetEnumParamValue(xmlloader, vars, databitstype);
    GetEnumParamValue(xmlloader, vars, paritytype);
    GetEnumParamValue(xmlloader, vars, stopbitstype);
    GetEnumParamValue(xmlloader, vars, flowtype);
    GetParamValue(xmlloader, vars, recvpacksize);
    GetParamValue(xmlloader, vars, packhead);
    GetParamValue(xmlloader, vars, packtail);
    GetParamValue(xmlloader, vars, distancePerPulse);
    GetParamValue(xmlloader, vars, MaxPulse);
    GetParamValue(xmlloader, vars, initx);
    GetParamValue(xmlloader, vars, inity);
    GetParamValue(xmlloader, vars, initori);

    vars->databuffer.clear();
    vars->lastx = vars->initx;
    vars->lasty = vars->inity;
    vars->lastori = vars->initori;
    vars->lastpulsenum = -1;
    vars->lastspeed = 0;
    vars->qlasttimestamp = QTime();
    vars->odometry = 0;
    vars->backDis = 0;
    vars->serialport.setPortName(vars->port);
    if(!(vars->serialport.open(QIODevice::ReadWrite))) {
        qDebug() << vars->serialport.errorString();
        return 0;
    }
    vars->serialport.setBaudRate(vars->baudrate);
    vars->serialport.setDataBits(vars->databitstype);
    vars->serialport.setParity(vars->paritytype);
    vars->serialport.setStopBits(vars->stopbitstype);
    vars->serialport.setFlowControl(vars->flowtype);

    vars->isInit = false;
    vars->initOriValue = 0;

    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
    SourceDrainMono_Sensor_EncoderIMU_Params * params=(SourceDrainMono_Sensor_EncoderIMU_Params *)paramsPtr;
    SourceDrainMono_Sensor_EncoderIMU_Vars * vars=(SourceDrainMono_Sensor_EncoderIMU_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: close node.
    Procedure:
    1: handle/close variables (vars).
    2: If everything is OK, return 1 for successful closing and vice versa.
    */

    if (vars->serialport.isOpen()) {
        vars->serialport.close();
    }

    return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
    SourceDrainMono_Sensor_EncoderIMU_Params * params=(SourceDrainMono_Sensor_EncoderIMU_Params *)paramsPtr;
    SourceDrainMono_Sensor_EncoderIMU_Vars * vars=(SourceDrainMono_Sensor_EncoderIMU_Vars *)varsPtr;
    internalTrigger=&(vars->serialport);
    internalTriggerSignal=QString(SIGNAL(readyRead()));
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
    SourceDrainMono_Sensor_EncoderIMU_Params * params=(SourceDrainMono_Sensor_EncoderIMU_Params *)paramsPtr;
    SourceDrainMono_Sensor_EncoderIMU_Vars * vars=(SourceDrainMono_Sensor_EncoderIMU_Vars *)varsPtr;
    outputDataPtr=boost::shared_ptr<void>(new SourceDrainMono_Sensor_EncoderIMU_Data());
    /*======Occasionally Program below/above======*/
    /*
    Function: initial output data.
    You need to program here when you need to manually initialize output data.
    */

}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
    SourceDrainMono_Sensor_EncoderIMU_Params * params=(SourceDrainMono_Sensor_EncoderIMU_Params *)paramsPtr;
    SourceDrainMono_Sensor_EncoderIMU_Vars * vars=(SourceDrainMono_Sensor_EncoderIMU_Vars *)varsPtr;
    SourceDrainMono_Sensor_EncoderIMU_Data * outputdata=(SourceDrainMono_Sensor_EncoderIMU_Data *)outputData;
    outputPortIndex=QList<int>();
    timeStamp=QTime();
    /*======Please Program below======*/
    /*
    Step 1: fill outputdata.
    Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
    E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
    Step 3: set the timeStamp for Simulator.
    */
    if(vars->serialport.bytesAvailable() < vars->recvpacksize) {
        return 0;
    }
    QByteArray datagram=vars->serialport.readAll();
    QTime tmptimestamp=QTime::currentTime();
    vars->databuffer.append(datagram);
    int startid=vars->databuffer.indexOf(vars->packhead);
    // int meslen = 9;
    // Gao Biao
    int meslen = 11;
    if (startid >= 0) {
        int endid = vars->databuffer.indexOf(vars->packtail,startid+meslen);
        if((endid - meslen) == startid) {
            if(vars->qlasttimestamp.isNull()) {
                vars->qlasttimestamp=QTime::currentTime();
            }
            double deltaTime = vars->qlasttimestamp.msecsTo(tmptimestamp) / 1000.0;
            vars->qlasttimestamp=tmptimestamp;

            QByteArray datagram = vars->databuffer.mid(startid + vars->packhead.size(), endid - (startid + vars->packhead.size()));
            short sAngleX   =  (*(short*)(datagram.data()));
            short sAngleY   =  (*(short*)(datagram.data() + sizeof(short)));
            short sAngleZ   = -(*(short*)(datagram.data() + sizeof(short) * 2));
            short sPulseNum =  (*(short*)(datagram.data() + sizeof(short) * 3));
            short sBackDis  =  (*(short*)(datagram.data() + sizeof(short) * 4));

            double curori = M_PI * sAngleZ / 1800.0;

            bool isEStop = (sAngleZ == 0 && sPulseNum == 0);
            if (isEStop) {
                vars->lastpulsenum = 0;
                vars->initOriValue = -vars->lastori;
            }

            if (!vars->isInit) {
                vars->initOriValue = curori;
                vars->isInit = true;
            }
            curori -= vars->initOriValue;
            double aveori= fabs(vars->lastori - curori) > M_PI ? (vars->lastori + curori) / 2.0 + M_PI : (vars->lastori + curori) / 2.0;
            vars->lastori = curori;

            if (vars->lastpulsenum == -1) {
                vars->lastpulsenum = sPulseNum;
            }
            short deltaP = sPulseNum - vars->lastpulsenum;
            if (deltaP < -vars->MaxPulse / 2 ) {
                deltaP += vars->MaxPulse;
            }
            else if (deltaP > vars->MaxPulse / 2 ) {
                deltaP -= vars->MaxPulse;
            }
            double distance = deltaP * vars->distancePerPulse;
            vars->lastpulsenum = sPulseNum;
            vars->odometry = distance + vars->odometry;

            vars->lastx += cos(aveori) * distance;
            vars->lasty += sin(aveori) * distance;

            outputdata->qtimestamp = tmptimestamp;
            outputdata->speed = deltaTime < 1e-5 ? vars->lastspeed : distance / deltaTime;
            vars->lastspeed = outputdata->speed;
            outputdata->odometry = vars->odometry;
            outputdata->orientation = vars->lastori;
            outputdata->x = vars->lastx;
            outputdata->y = vars->lasty;
            outputdata->encoderRawData = sPulseNum;
            outputdata->backDis = sBackDis;
//            printf("Speed : %.1lf   x : %.1lf   y : %.1lf  odom : %.1lf\n",
//                   outputdata->speed, outputdata->x, outputdata->y, outputdata->odometry);
            vars->databuffer.clear();
            return 1;
        }
    }
    return 0;
}

void DECOFUNC(getMonoDrainDataSize)(void * paramsPtr, void * varsPtr, int & drainDataSize)
{
    SourceDrainMono_Sensor_EncoderIMU_Params * params=(SourceDrainMono_Sensor_EncoderIMU_Params *)paramsPtr;
    SourceDrainMono_Sensor_EncoderIMU_Vars * vars=(SourceDrainMono_Sensor_EncoderIMU_Vars *)varsPtr;
    drainDataSize=0;
    /*======Please Program above======*/
    /*
    Function: get drain data size to be grabbed from buffer.
    Rules:
    drainDataSize=0: grab and remove all data from buffer.
    drainDataSize>0: grab drainDataSize latest data from buffer.
    drainDataSize<0: grab and remove drainDataSize ancient data from buffer.
    */
}

//Input Port #0: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_EncoderIMU_Order_InputParams, Data_Type = SourceDrainMono_Sensor_EncoderIMU_Order_InputData
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
    SourceDrainMono_Sensor_EncoderIMU_Params * params=(SourceDrainMono_Sensor_EncoderIMU_Params *)paramsPtr;
    SourceDrainMono_Sensor_EncoderIMU_Vars * vars=(SourceDrainMono_Sensor_EncoderIMU_Vars *)varsPtr;
    QVector<SourceDrainMono_Sensor_EncoderIMU_Order_InputParams *> drainparams; copyQVector(drainparams,drainParams);
    QVector<SourceDrainMono_Sensor_EncoderIMU_Order_InputData *> draindata; copyQVector(draindata,drainData);
    if(draindata.size()==0){return 0;}
    /*======Please Program below======*/
    /*
    Function: process draindata.
    */
    qint64 n = vars->serialport.write(draindata.front()->datagram.data(), draindata.front()->datagram.size());
    if(n < 0) {
        return 0;
    }
    return 1;
}

