// You need to program this file.

#include "../NoEdit/ProcessorMulti_Algorithm_Deadreckoning_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
// e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void *paramsPtr, void *varsPtr)
{
    XMLDomInterface xmlloader(qstrConfigName, qstrNodeType, qstrNodeClass, qstrNodeName);
    ProcessorMulti_Algorithm_Deadreckoning_Params *params = (ProcessorMulti_Algorithm_Deadreckoning_Params *)paramsPtr;
    ProcessorMulti_Algorithm_Deadreckoning_Vars *vars = (ProcessorMulti_Algorithm_Deadreckoning_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: open node.
    Procedure:
    1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
    2: initialize variables (vars).
    3: If everything is OK, return 1 for successful opening and vice versa.
    */

    // 读入设定的机器人在地图中初始位置
    GetParamValue(xmlloader, vars, initx);
    GetParamValue(xmlloader, vars, inity);
    GetParamValue(xmlloader, vars, initori);

    vars->lastx = vars->initx;
    vars->lasty = vars->inity;
    vars->lastori = vars->initori;
    vars->lastpulsenum = -1;
    vars->initOriValue = 0;
    vars->isInit = false;

    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void *paramsPtr, void *varsPtr)
{
    ProcessorMulti_Algorithm_Deadreckoning_Params *params = (ProcessorMulti_Algorithm_Deadreckoning_Params *)paramsPtr;
    ProcessorMulti_Algorithm_Deadreckoning_Vars *vars = (ProcessorMulti_Algorithm_Deadreckoning_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: close node.
    Procedure:
    1: handle/close variables (vars).
    2: If everything is OK, return 1 for successful closing and vice versa.
    */

    return 1;
}

void DECOFUNC(getInternalTrigger)(void *paramsPtr, void *varsPtr, QObject *&internalTrigger, QString &internalTriggerSignal)
{
    ProcessorMulti_Algorithm_Deadreckoning_Params *params = (ProcessorMulti_Algorithm_Deadreckoning_Params *)paramsPtr;
    ProcessorMulti_Algorithm_Deadreckoning_Vars *vars = (ProcessorMulti_Algorithm_Deadreckoning_Vars *)varsPtr;
    internalTrigger = NULL;
    internalTriggerSignal = QString();
    /*======Occasionally Program above======*/
    /*
    Function: get internal trigger [defined in vars] for node.
    You need to program here when you need internal trigger (internalTrigger + internalTriggerSignal) for node.
    E.g.
    internalTrigger=&(vars->trigger);
    internalTriggerSignal=QString(SIGNAL(triggerSignal()));
    */
}

void DECOFUNC(initializeOutputData)(void *paramsPtr, void *varsPtr, boost::shared_ptr<void> &outputDataPtr)
{
    ProcessorMulti_Algorithm_Deadreckoning_Params *params = (ProcessorMulti_Algorithm_Deadreckoning_Params *)paramsPtr;
    ProcessorMulti_Algorithm_Deadreckoning_Vars *vars = (ProcessorMulti_Algorithm_Deadreckoning_Vars *)varsPtr;
    outputDataPtr = boost::shared_ptr<void>(new ProcessorMulti_Algorithm_Deadreckoning_Data());
    /*======Occasionally Program below/above======*/
    /*
    Function: initial output data.
    You need to program here when you need to manually initialize output data.
    */
}

void DECOFUNC(getMultiInputDataSize)(void *paramsPtr, void *varsPtr, QList<int> &inputDataSize)
{
    ProcessorMulti_Algorithm_Deadreckoning_Params *params = (ProcessorMulti_Algorithm_Deadreckoning_Params *)paramsPtr;
    ProcessorMulti_Algorithm_Deadreckoning_Vars *vars = (ProcessorMulti_Algorithm_Deadreckoning_Vars *)varsPtr;
    inputDataSize = QList<int>();
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

// Input Port #0: Buffer_Size = 10, Params_Type = Simulator_Sensor_Encoder_Params, Data_Type = Simulator_Sensor_Encoder_Data
// Input Port #1: Buffer_Size = 10, Params_Type = Simulator_Sensor_IMU_Params, Data_Type = Simulator_Sensor_IMU_Data
bool DECOFUNC(processMultiInputData)(void *paramsPtr, void *varsPtr, QVector<QVector<void *>> inputParams, QVector<QVector<void *>> inputData, void *outputData, QList<int> &outputPortIndex)
{
    ProcessorMulti_Algorithm_Deadreckoning_Params *params = (ProcessorMulti_Algorithm_Deadreckoning_Params *)paramsPtr;
    ProcessorMulti_Algorithm_Deadreckoning_Vars *vars = (ProcessorMulti_Algorithm_Deadreckoning_Vars *)varsPtr;
    QVector<Simulator_Sensor_Encoder_Params *> inputparams_0;
    copyQVector(inputparams_0, inputParams[0]);
    QVector<Simulator_Sensor_IMU_Params *> inputparams_1;
    copyQVector(inputparams_1, inputParams[1]);
    QVector<Simulator_Sensor_Encoder_Data *> inputdata_0;
    copyQVector(inputdata_0, inputData[0]);
    QVector<Simulator_Sensor_IMU_Data *> inputdata_1;
    copyQVector(inputdata_1, inputData[1]);
    ProcessorMulti_Algorithm_Deadreckoning_Data *outputdata = (ProcessorMulti_Algorithm_Deadreckoning_Data *)outputData;
    outputPortIndex = QList<int>();
    if (inputdata_0.size() == 0)
    {
        return 0;
    }
    if (inputdata_1.size() == 0)
    {
        return 0;
    }
    /*======Please Program below======*/
    /*
    Step 1: process inputdata_index, then store it into outputdata.
    Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
    E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
    */
    // 输入数据
    // inputdata_0.front()->pulse           （int）为编码器最近帧脉冲数据，增加即小车向前走
    // inputdata_1.front()->yaw             （double）为IMU最近帧航向角数据，单位为度，顺时针为正方向
    // inputdata_0.front()->timestamp；
    // inputdata_1.front()->timestamp;      为两传感器传回最近帧的时间戳,已同步
    // 输入数据对应的外部参数
    // inputparams_0.front()->disPerPulse    (double)编码器单脉冲对应的距离 单位为m
    // inputparams_0.front()->pulseMax       (int)编码器脉冲数最大数据
    // 记录上一帧数据
    // vars->lastx;
    // vars->lasty;
    // vars->lastori;
    // vars->lastpulsenum;                    用来判断溢出
    // vars->isInit;                          判断是否初始化过(是否为首帧数据)，
    // vars->initOriValue;                    航向角数据初始值
    // vars->initori                          可视化界面中小车初始朝向偏置
    // vars->PI = 3.1415926535;

    // 读入编码器数据和IMU的航向角,并转为弧度制
    int pluseNum = inputdata_0.front()->pulse;               // 编码器最近帧脉冲数据，增加即小车向前走
    int pluseMax = inputparams_0.front()->pulseMax;          // 编码器脉冲数最大数据
    double disPerPluse = inputparams_0.front()->disPerPulse; // 编码器单脉冲对应的距离 单位为m
    int angle = inputdata_1.front()->yaw;                    // IMU最近帧航向角数据，单位为度，顺时针为正方向
    int timeStamp = inputdata_0.front()->timestamp;          // 传感器传回最近帧的时间戳,已同步
    double currentOri = angle * vars->PI / 180.0;            // 转为弧度制

    // 判断是否为第一帧数据，初始化
    if (!vars->isInit)
    {
        vars->isInit = true;
        vars->initOriValue = currentOri;
        vars->lastpulsenum = pluseNum;
    }
    // 计算小车当前时刻的角度，减去初始偏置
    currentOri += vars->initori - vars->initOriValue;

    // 计算小车行驶的距离,注意处理编码器数据溢出
    int deltaPluse = pluseNum - vars->lastpulsenum;

    /**************************************************填写以下部分***************************************************************/

    // --------------------处理编码器数据溢出,并将单位转换为m-----------------------------------------------

    deltaPluse = (deltaPluse + pluseMax) % pluseMax;
    double distance = deltaPluse * disPerPluse;

    // --------------------处理编码器数据溢出,并将单位转换为m-----------------------------------------------

    // --------------------计算小车当前时刻的位置，并更新last数据--------------------
    double averageOri = (vars->lastori + currentOri) / 2;
    vars->lastx = vars->lastx + distance * cos(averageOri);
    vars->lasty = vars->lasty + distance * sin(averageOri);
    vars->lastori = currentOri;
    vars->lastpulsenum = pluseNum;

    // --------------------计算小车当前时刻的位置，并更新last数据--------------------

    // 填充outputdata
    // 角度为弧度，顺时针为正方向，机器人初始位置在全局坐标系下的航向角为-90度(地图中向上)
    // 位置单位为m，设初始位置在全局坐标系下为（0，0，pi/2）
    // ----------------------填充outputdata---------------------------------------------
    outputdata->orientation = vars->lastori;
    outputdata->timestamp = timeStamp;
    // 可视化坐标系和全局坐标系x轴相反，赋值时需要取相反数
    outputdata->x = -vars->lastx;
    outputdata->y = vars->lasty;
    // ----------------------填充outputdata---------------------------------------------

    /**************************************************填写以上部分***************************************************************/
    return 1;
}
