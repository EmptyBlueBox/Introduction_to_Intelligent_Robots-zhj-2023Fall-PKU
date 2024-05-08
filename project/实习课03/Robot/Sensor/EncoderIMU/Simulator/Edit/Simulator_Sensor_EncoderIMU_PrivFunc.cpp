//You need to program this file.

#include "../NoEdit/Simulator_Sensor_EncoderIMU_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	Simulator_Sensor_EncoderIMU_Params * params=(Simulator_Sensor_EncoderIMU_Params *)paramsPtr;
	Simulator_Sensor_EncoderIMU_Vars * vars=(Simulator_Sensor_EncoderIMU_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, path);
    GetParamValue(xmlloader, params, filename);

    GetParamValue(xmlloader, params, distancePerPulse);
    GetParamValue(xmlloader, params, maxPulse);
    GetParamValue(xmlloader, vars, initx);
    GetParamValue(xmlloader, vars, inity);
    GetParamValue(xmlloader, vars, initori);
    QString filename = QString("%1/%2").arg(params->path).arg(params->filename);

    QFile odomsimu;
    QTextStream textstream;
    odomsimu.setFileName(filename);
    if (!odomsimu.open(QFile::ReadOnly | QFile::Text)) {
        return 0;
    }
    textstream.setDevice(&(odomsimu));

    vars->ComDataIndex = 0;
    vars->AllComData.clear();
    SourceDrainMono_Sensor_EncoderIMU_Data OneComData;
    if (filename.endsWith(".odom")) {
        double lastEncoderRawData = 0.1;
        double odometry = 0;
        double lastori = 0;
        double lastx = 0;
        double lasty = 0;
        double lastspeed = 0;
        long lastTimestamp = -1;
        while (!textstream.atEnd()) {
            long ltimestamp;
            textstream >> ltimestamp
                >> OneComData.x
                >> OneComData.y
                >> OneComData.orientation
                >> OneComData.speed
                >> OneComData.encoderRawData
                >> OneComData.backDis;
            // calculate odometry
            if (lastEncoderRawData == 0.1) {
                lastEncoderRawData = OneComData.encoderRawData;
                lastTimestamp = ltimestamp;
                lastori = OneComData.orientation;
            }
            double deltaPulse = OneComData.encoderRawData - lastEncoderRawData;
            if (deltaPulse < - params->maxPulse / 2.0)
                deltaPulse += params->maxPulse;
            else if (deltaPulse > params->maxPulse / 2.0)
                deltaPulse -= params->maxPulse;
            double distance = deltaPulse * params->distancePerPulse;
            odometry += distance;
            // calculate x,y
            double sAngle = OneComData.orientation;
            double PI = 3.1415926535897932384626433832795;
            double tmpori = PI * sAngle / 180.0 + PI / 2;
            double aveori = fabs(lastori - tmpori) > PI ? (lastori + tmpori) / 2.0 + PI : (lastori + tmpori) / 2.0;
            lastori = tmpori;
            lastx += cos(aveori) * distance;
            lasty += sin(aveori) * distance;
            OneComData.x = lastx;
            OneComData.y = lasty;
            // calculate speed
            double deltaTime = (ltimestamp - lastTimestamp) / 1000.0;
            OneComData.speed = deltaTime < 1e-5 ? lastspeed : distance / deltaTime;
            lastTimestamp = ltimestamp;
            lastspeed = OneComData.speed;
            lastEncoderRawData = OneComData.encoderRawData;
            OneComData.odometry = odometry;
            OneComData.qtimestamp = QTime::fromMSecsSinceStartOfDay(ltimestamp);
            vars->AllComData.push_back(OneComData);
        }
    } else if (filename.endsWith(".txt")) {
        double lastx = vars->initx;
        double lasty = vars->inity;
        double lastori = vars->initori;
        short lastpulsenum = -1;
        double lastspeed = 0;
        QTime qlasttimestamp = QTime();
        double odometry = 0;
        while (!textstream.atEnd()) {
            int ltimestamp;
            short sAngle;
            short sPulseNum;
            QStringList tmplist = textstream.readLine().split(" ");
            ltimestamp = tmplist.at(1).toInt();
            sAngle = tmplist.at(2).toShort();
            sAngle = -sAngle;
            sPulseNum = tmplist.at(3).toShort();

            if (qlasttimestamp.isNull()) {
                qlasttimestamp = QTime::fromMSecsSinceStartOfDay(ltimestamp);
            }
            QTime tmptimestamp = QTime::fromMSecsSinceStartOfDay(ltimestamp);
            double deltaTime = qlasttimestamp.msecsTo(tmptimestamp) / 1000.0;
            qlasttimestamp = tmptimestamp;
            double PI = 3.1415926535897932384626433832795;
            double tmpori = PI * sAngle / 1800.0 + PI / 2;
            double aveori = fabs(lastori - tmpori) > PI ? (lastori + tmpori) / 2.0 + PI : (lastori + tmpori) / 2.0;
            lastori = tmpori;
            if (lastpulsenum == -1) {
                lastpulsenum = sPulseNum;
            }
            short deltaP = sPulseNum - lastpulsenum;
            if (abs(deltaP) > params->maxPulse / 2) {
                deltaP += params->maxPulse;
            }
            double distance = (deltaP)* params->distancePerPulse;
            lastpulsenum = sPulseNum;
            odometry = distance + odometry;
            lastx += cos(aveori)*distance;
            lasty += sin(aveori)*distance;
            OneComData.qtimestamp = qlasttimestamp;
            OneComData.speed = deltaTime < 1e-5 ? lastspeed : distance / deltaTime;
            lastspeed = OneComData.speed;
            OneComData.odometry = odometry;
            OneComData.orientation = lastori;
            OneComData.x = lastx;
            OneComData.y = lasty;
            vars->AllComData.push_back(OneComData);
        }
    }
    odomsimu.close();
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	Simulator_Sensor_EncoderIMU_Params * params=(Simulator_Sensor_EncoderIMU_Params *)paramsPtr;
	Simulator_Sensor_EncoderIMU_Vars * vars=(Simulator_Sensor_EncoderIMU_Vars *)varsPtr;
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
	Simulator_Sensor_EncoderIMU_Params * params=(Simulator_Sensor_EncoderIMU_Params *)paramsPtr;
	Simulator_Sensor_EncoderIMU_Vars * vars=(Simulator_Sensor_EncoderIMU_Vars *)varsPtr;
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
	Simulator_Sensor_EncoderIMU_Params * params=(Simulator_Sensor_EncoderIMU_Params *)paramsPtr;
	Simulator_Sensor_EncoderIMU_Vars * vars=(Simulator_Sensor_EncoderIMU_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SourceDrainMono_Sensor_EncoderIMU_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	Simulator_Sensor_EncoderIMU_Params * params=(Simulator_Sensor_EncoderIMU_Params *)paramsPtr;
	Simulator_Sensor_EncoderIMU_Vars * vars=(Simulator_Sensor_EncoderIMU_Vars *)varsPtr;
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
    if (vars->ComDataIndex >= vars->AllComData.size()) {
        timeStamp = QTime();
        return 0;
    }
    *outputdata = vars->AllComData[vars->ComDataIndex];
    timeStamp = outputdata->qtimestamp;
    vars->ComDataIndex++;

    double OnePeriod = params->maxPulse * params->distancePerPulse;
    double LeftDist = fmod(outputdata->odometry, OnePeriod);
    vars->pulse = LeftDist / params->distancePerPulse;
    outputdata->encoderRawData = vars->pulse;
    vars->lastlength = outputdata->odometry;
	return 1;
}

