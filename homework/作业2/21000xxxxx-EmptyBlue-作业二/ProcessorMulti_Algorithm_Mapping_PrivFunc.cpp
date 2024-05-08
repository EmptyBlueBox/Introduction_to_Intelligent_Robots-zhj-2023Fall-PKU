
// You need to program this file.

#include "../NoEdit/ProcessorMulti_Algorithm_Mapping_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
// e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void *paramsPtr, void *varsPtr)
{
    XMLDomInterface xmlloader(qstrConfigName, qstrNodeType, qstrNodeClass, qstrNodeName);
    ProcessorMulti_Algorithm_Mapping_Params *params = (ProcessorMulti_Algorithm_Mapping_Params *)paramsPtr;
    ProcessorMulti_Algorithm_Mapping_Vars *vars = (ProcessorMulti_Algorithm_Mapping_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: open node.
    Procedure:
    1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
    2: initialize variables (vars).
    3: If everything is OK, return 1 for successful opening and vice versa.
    */
    GetParamValue(xmlloader, params, mapWidth); // 从xml读取
    GetParamValue(xmlloader, params, mapHeight);
    GetParamValue(xmlloader, params, zeroX);
    GetParamValue(xmlloader, params, zeroY);
    GetParamValue(xmlloader, params, mapRes);

    vars->map = new unsigned char *[params->mapHeight];
    for (int i = 0; i < params->mapHeight; i++)
    {
        vars->map[i] = new unsigned char[params->mapWidth];
        for (int j = 0; j < params->mapWidth; j++)
        {
            vars->map[i][j] = 0;
        }
    }
    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void *paramsPtr, void *varsPtr)
{
    ProcessorMulti_Algorithm_Mapping_Params *params = (ProcessorMulti_Algorithm_Mapping_Params *)paramsPtr;
    ProcessorMulti_Algorithm_Mapping_Vars *vars = (ProcessorMulti_Algorithm_Mapping_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: close node.
    Procedure:
    1: handle/close variables (vars).
    2: If everything is OK, return 1 for successful closing and vice versa.
    */
    if (vars->map != NULL)
    {
        for (int i = 0; i < params->mapHeight; i++)
        {
            delete[] vars->map[i];
        }
        delete[] vars->map;
        vars->map = NULL;
    }
    return 1;
}

void DECOFUNC(getInternalTrigger)(void *paramsPtr, void *varsPtr, QObject *&internalTrigger, QString &internalTriggerSignal)
{
    ProcessorMulti_Algorithm_Mapping_Params *params = (ProcessorMulti_Algorithm_Mapping_Params *)paramsPtr;
    ProcessorMulti_Algorithm_Mapping_Vars *vars = (ProcessorMulti_Algorithm_Mapping_Vars *)varsPtr;
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
    ProcessorMulti_Algorithm_Mapping_Params *params = (ProcessorMulti_Algorithm_Mapping_Params *)paramsPtr;
    ProcessorMulti_Algorithm_Mapping_Vars *vars = (ProcessorMulti_Algorithm_Mapping_Vars *)varsPtr;
    outputDataPtr = boost::shared_ptr<void>(new ProcessorMulti_Algorithm_Mapping_Data(params->mapWidth, params->mapHeight));
    /*======Occasionally Program below/above======*/
    /*
    Function: initial output data.
    You need to program here when you need to manually initialize output data.
    */
}

void DECOFUNC(getMultiInputDataSize)(void *paramsPtr, void *varsPtr, QList<int> &inputDataSize)
{
    ProcessorMulti_Algorithm_Mapping_Params *params = (ProcessorMulti_Algorithm_Mapping_Params *)paramsPtr;
    ProcessorMulti_Algorithm_Mapping_Vars *vars = (ProcessorMulti_Algorithm_Mapping_Vars *)varsPtr;
    inputDataSize = QList<int>() << 10 << 10;
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

// Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMulti_Algorithm_Deadreckoning_Params, Data_Type = ProcessorMulti_Algorithm_Deadreckoning_Data
// Input Port #1: Buffer_Size = 10, Params_Type = Simulator_Sensor_Lidar_URG_Params, Data_Type = Simulator_Sensor_Lidar_URG_Data
bool DECOFUNC(processMultiInputData)(void *paramsPtr, void *varsPtr, QVector<QVector<void *>> inputParams, QVector<QVector<void *>> inputData, void *outputData, QList<int> &outputPortIndex)
{
    ProcessorMulti_Algorithm_Mapping_Params *params = (ProcessorMulti_Algorithm_Mapping_Params *)paramsPtr;
    ProcessorMulti_Algorithm_Mapping_Vars *vars = (ProcessorMulti_Algorithm_Mapping_Vars *)varsPtr;
    QVector<ProcessorMulti_Algorithm_Deadreckoning_Params *> inputparams_0;
    copyQVector(inputparams_0, inputParams[0]);
    QVector<Simulator_Sensor_Lidar_URG_Params *> inputparams_1;
    copyQVector(inputparams_1, inputParams[1]);
    QVector<ProcessorMulti_Algorithm_Deadreckoning_Data *> inputdata_0;
    copyQVector(inputdata_0, inputData[0]);
    QVector<Simulator_Sensor_Lidar_URG_Data *> inputdata_1;
    copyQVector(inputdata_1, inputData[1]);
    ProcessorMulti_Algorithm_Mapping_Data *outputdata = (ProcessorMulti_Algorithm_Mapping_Data *)outputData;
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

    // inputdata_0即Deadreckoning模块输出，数据结构参见该模块outputdata
    // inputdata_1->timestamp激光数据时间戳
    // inputdata_1->datasize 激光数据大小，即数组inputdata_1->data的大小，
    // 激光数据角度范围为机器人前向0-180度，角度分辨率位0.5度，即datasize=361
    // inputdata_1->data[0]即角度为0的激光束的测距值，inputdata_1->data[361]即为角度为180度的激光束的测距值
    // inputparams_1->res 激光数据分辨率，单位为弧度，即0.5度对应的弧度值

    // 传感器激光坐标系
    //            机器人面朝方向
    //                  y
    //                  |
    //                  |
    //                  |
    //                  |
    //                  |
    //                  |
    // 激光0度 x--------------------- 激光180度

    // 由于在航向推模块的输出中x轴取反，因此机器人采用激光坐标系为
    //            机器人面朝方向
    //                  y
    //                  |
    //                  |
    //                  |
    //                  |
    //                  |
    //                  |
    // 激光180度 --------------------- x激光0度
    // 即：设传感器激光坐标系中激光束与原本x轴的夹角为angle，则计算时应当取angle = 180 - angle

    // 全局地图坐标系
    //          |---------------------x
    //          |
    //          |
    //          |
    //          |
    //          |
    //          |
    //          |
    //          |
    //          |
    //          y

    // 将地图存在私有变量vars->map中，vars->map[y][x]表示坐标（x，y）位置，令其取值为范围为[0，255]，
    // 表示该处存在障碍物的得票数，参见课件简易投票法

    // ========================== 请完成以下程序段! ==========================
    // 遍历所有激光点，计算它们在全局坐标系中的位置
    for (int i = 0; i < inputdata_1.front()->datasize; i++)
    {

        // 计算得到单个激光点的距离(m)和角度(rad)
        double pi = 3.1415926535897934384626;
        double dis = inputdata_1.front()->data[i] / 10; // 0.1m
        double angle = i / 2;                           // in degrees
        double angle_rad = pi * angle / 180;            // in rad

        // 激光点在全局坐标系中的位置 单位m
        double angle_relative = pi / 2 - angle_rad - inputdata_0.front()->orientation;
        double gx = inputdata_0.front()->x * 10 + dis * cos(pi - angle_relative); // 设传感器激光坐标系中激光束与原本x轴的夹角为angle，则计算时应当取angle = 180 - angle
        double gy = inputdata_0.front()->y * 10 - dis * sin(angle_relative);
        printf(" x, y: (%lf, %lf) ", inputdata_0.front()->x, inputdata_0.front()->y);
        printf(" dis, angle: (%lf, %lf) ", dis, angle_relative);

        // 激光点在栅格地图中的位置 单位 pixel
        //       int carx=inputdata_0.front()->x*10+100;
        //       int cary=inputdata_0.front()->y*10+500;
        int mapx = gx + 100;
        int mapy = gy + 500;
        printf(" w, h: (%d, %d) ", params->mapWidth, params->mapHeight);
        printf(" pixel: (%d, %d) \n", mapx, mapy);

        // 更新地图
        if (mapx >= 0 && mapx < params->mapWidth && mapy >= 0 && mapy < params->mapHeight)
        {
            if (vars->map[mapy][mapx] + 3 <= 255)
            {
                vars->map[mapy][mapx] += 3;
            }
            else
            {
                vars->map[mapy][mapx] = 255;
            }
        }
    }

    outputdata->width = params->mapWidth;
    outputdata->height = params->mapHeight;

    // ========================== 请完成以上程序段! ==========================

    // output 拷贝给输出
    for (int i = 0; i < params->mapHeight; i++)
    {
        memcpy(outputdata->map[i], vars->map[i], sizeof(char) * params->mapWidth);
    }

    outputdata->timestamp_deadreconing = inputdata_0.front()->timestamp;
    outputdata->timestamp_laser = inputdata_1.front()->timestamp;
    outputdata->mapX = inputdata_0.front()->x;
    outputdata->mapY = inputdata_0.front()->y;
    // qDebug()<<"MapX "<<inputdata_0.front()->x<<" "<<endl;

    return 1;
}
