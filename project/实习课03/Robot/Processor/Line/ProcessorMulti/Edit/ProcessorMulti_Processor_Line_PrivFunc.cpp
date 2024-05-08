//You need to program this file.

#include "../NoEdit/ProcessorMulti_Processor_Line_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Processor_Line_Params * params=(ProcessorMulti_Processor_Line_Params *)paramsPtr;
	ProcessorMulti_Processor_Line_Vars * vars=(ProcessorMulti_Processor_Line_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMulti_Processor_Line_Params * params=(ProcessorMulti_Processor_Line_Params *)paramsPtr;
	ProcessorMulti_Processor_Line_Vars * vars=(ProcessorMulti_Processor_Line_Vars *)varsPtr;
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
	ProcessorMulti_Processor_Line_Params * params=(ProcessorMulti_Processor_Line_Params *)paramsPtr;
	ProcessorMulti_Processor_Line_Vars * vars=(ProcessorMulti_Processor_Line_Vars *)varsPtr;
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
	ProcessorMulti_Processor_Line_Params * params=(ProcessorMulti_Processor_Line_Params *)paramsPtr;
	ProcessorMulti_Processor_Line_Vars * vars=(ProcessorMulti_Processor_Line_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Processor_Line_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Processor_Line_Params * params=(ProcessorMulti_Processor_Line_Params *)paramsPtr;
	ProcessorMulti_Processor_Line_Vars * vars=(ProcessorMulti_Processor_Line_Vars *)varsPtr;
	inputDataSize=QList<int>();
	/*======Please Program above======*/
	/*
	Function: get input data size to be grabbed from buffer.
	Rules:
	inputDataSize=0: grab and remove all data from buffer.
	inputDataSize>0: grab inputDataSize latest data from buffer.
	inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
	E.g.
	inputDataSize=QList<int>()<<0<<1<<-1...;
	*/
}

//Input Port #0: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_EncoderIMU_Params, Data_Type = SourceDrainMono_Sensor_EncoderIMU_Data
//Input Port #1: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_URG_Params, Data_Type = SensorTimer_Sensor_URG_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Processor_Line_Params * params=(ProcessorMulti_Processor_Line_Params *)paramsPtr;
	ProcessorMulti_Processor_Line_Vars * vars=(ProcessorMulti_Processor_Line_Vars *)varsPtr;
	QVector<SourceDrainMono_Sensor_EncoderIMU_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<SensorTimer_Sensor_URG_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
	QVector<SourceDrainMono_Sensor_EncoderIMU_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<SensorTimer_Sensor_URG_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
	ProcessorMulti_Processor_Line_Data * outputdata=(ProcessorMulti_Processor_Line_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
	if(inputdata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    SourceDrainMono_Sensor_EncoderIMU_Data *odom = inputdata_0.front();
    SensorTimer_Sensor_URG_Data *laser = inputdata_1.front();
    outputdata->x = odom->x;
    outputdata->y = odom->y;
    outputdata->theta = odom->orientation;

    outputdata->obPoints.clear();
    for (int i = 0; i < laser->datasize; i++) {
        double theta = (90 - i * 0.5) / 180.0 * M_PI;
        double length = laser->data[i] * 0.01;
        if (length > 0 && length < 5.0) {
            // 相对车体的坐标
            double x = length * cos(theta);
            double y = length * sin(theta);
            if (length < 0.5) {
                outputdata->obPoints.append(cv::Point2d(x, y));
            }
            outputdata->laserPoints.append(cv::Point2d(x, y));
        }
    }
    for (int i = 0; i <= 360; i++) {
        double theta = (i * 0.5 - 90) / 180.0 * M_PI;
        double x = 0.5 * cos(theta);
        double y = 0.5 * sin(theta);
        outputdata->safeZone.append(cv::Point2d(x, y));
    }

    char dataput[10];
    dataput[0] = 0xF8;
    dataput[1] = 4;
    *(short*)&dataput[2] = (short)0;
    *(short*)&dataput[4] = (short)outputdata->obPoints.size() > 0 ? 0 : 60;
    dataput[6] = 0x8F;
    outputdata->datagram.append(dataput, 7);
	return 1;
}

