// You need to program this file.

#include "../NoEdit/ProcessorMulti_Algor_Mapping_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
// e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void *paramsPtr, void *varsPtr)
{
    XMLDomInterface xmlloader(qstrConfigName, qstrNodeType, qstrNodeClass, qstrNodeName);
    ProcessorMulti_Algor_Mapping_Params *params = (ProcessorMulti_Algor_Mapping_Params *)paramsPtr;
    ProcessorMulti_Algor_Mapping_Vars *vars = (ProcessorMulti_Algor_Mapping_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: open node.
    Procedure:
    1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
    2: initialize variables (vars).
    3: If everything is OK, return 1 for successful opening and vice versa.
    */
    vars->map = new double *[params->mapHeight];
    for (int i = 0; i < params->mapHeight; i++)
    {
        vars->map[i] = new double[params->mapWidth];
        for (int j = 0; j < params->mapWidth; j++)
        {
            vars->map[i][j] = 0;
        }
    }
    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void *paramsPtr, void *varsPtr)
{
    ProcessorMulti_Algor_Mapping_Params *params = (ProcessorMulti_Algor_Mapping_Params *)paramsPtr;
    ProcessorMulti_Algor_Mapping_Vars *vars = (ProcessorMulti_Algor_Mapping_Vars *)varsPtr;
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
    ProcessorMulti_Algor_Mapping_Params *params = (ProcessorMulti_Algor_Mapping_Params *)paramsPtr;
    ProcessorMulti_Algor_Mapping_Vars *vars = (ProcessorMulti_Algor_Mapping_Vars *)varsPtr;
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
    ProcessorMulti_Algor_Mapping_Params *params = (ProcessorMulti_Algor_Mapping_Params *)paramsPtr;
    ProcessorMulti_Algor_Mapping_Vars *vars = (ProcessorMulti_Algor_Mapping_Vars *)varsPtr;
    outputDataPtr = boost::shared_ptr<void>(new ProcessorMulti_Algor_Mapping_Data(params->mapWidth, params->mapHeight));
    /*======Occasionally Program below/above======*/
    /*
    Function: initial output data.
    You need to program here when you need to manually initialize output data.
    */
}

void DECOFUNC(getMultiInputDataSize)(void *paramsPtr, void *varsPtr, QList<int> &inputDataSize)
{
    ProcessorMulti_Algor_Mapping_Params *params = (ProcessorMulti_Algor_Mapping_Params *)paramsPtr;
    ProcessorMulti_Algor_Mapping_Vars *vars = (ProcessorMulti_Algor_Mapping_Vars *)varsPtr;
    inputDataSize = QList<int>() << 0 << 0;
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

// Input Port #0: Buffer_Size = 1, Params_Type = Simulator_Sensor_laser_Params, Data_Type = Simulator_Sensor_laser_Data
// Input Port #1: Buffer_Size = 5, Params_Type = Simulator_Sensor_GPS_Params, Data_Type = Simulator_Sensor_GPS_Data
bool DECOFUNC(processMultiInputData)(void *paramsPtr, void *varsPtr, QVector<QVector<void *>> inputParams, QVector<QVector<void *>> inputData, void *outputData, QList<int> &outputPortIndex)
{
    ProcessorMulti_Algor_Mapping_Params *params = (ProcessorMulti_Algor_Mapping_Params *)paramsPtr;
    ProcessorMulti_Algor_Mapping_Vars *vars = (ProcessorMulti_Algor_Mapping_Vars *)varsPtr;
    QVector<Simulator_Sensor_laser_Params *> inputparams_0;
    copyQVector(inputparams_0, inputParams[0]);
    QVector<Simulator_Sensor_GPS_Params *> inputparams_1;
    copyQVector(inputparams_1, inputParams[1]);
    QVector<Simulator_Sensor_laser_Data *> inputdata_0;
    copyQVector(inputdata_0, inputData[0]);
    QVector<Simulator_Sensor_GPS_Data *> inputdata_1;
    copyQVector(inputdata_1, inputData[1]);
    ProcessorMulti_Algor_Mapping_Data *outputdata = (ProcessorMulti_Algor_Mapping_Data *)outputData;
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

    for (int i = 0; i < inputparams_0.front()->rng / inputparams_0.front()->res; i++)
    {
        //==============================================================================
        //-----------------Please edit below--------------------------------------------
        //==============================================================================

        // 目标：对每条激光束更新全局地图（Occupency Gird Map）
        // 下列步骤中需要编程的有3，4，5，8

        // 1.分别定义激光点在全局坐标系（GPS），机器人坐标系，激光雷达坐标系中的坐标变量
        double gx, gy; // 激光点在全局坐标系中的位置 单位m
        double rx, ry; // 激光点在机器人坐标系中的位置 单位m
        double lx, ly; // 激光点在激光雷达坐标系中的位置 单位m

        // 2.若激光点返回测距值为0，则为无效数据，将其滤除。
        if (inputdata_0.front()->data[i] == 0)
            continue;

        // 3.计算激光点在激光雷达坐标系下的位置，并根据参数inputparams_0.front()->isReverse判断是否将lx取相反数。
        double dis = inputdata_0.front()->data[i] / inputparams_0.front()->unit; // 计算得到单个激光点的距离返回值
        double angle = i * inputparams_0.front()->res * 3.1415926 / 180.0;       // 计算得到当前处理激光束在激光雷达坐标系中角度
        lx = -dis * cos(angle);
        ly = dis * sin(angle);

        // 4.进行 激光雷达坐标系->机器人坐标系 变换
        // xL,yL,aL定义见课件，其在程序中对应变量为
        // inputparams_0.front()->xL，inputparams_0.front()->yL，inputparams_0.front()->aL
        double laser_aL_rad = inputparams_0.front()->aL * 3.1415926 / 180.0; // 转换为弧度
        rx = inputparams_0.front()->xL - (lx * cos(laser_aL_rad) - ly * sin(laser_aL_rad));
        ry = inputparams_0.front()->yL + (lx * sin(laser_aL_rad) + ly * cos(laser_aL_rad));

        // 5.进行 机器人坐标系->全局坐标系 变换
        // 机器人航向角ori定义见课件，对应变量为inputdata_1.front()->ori
        double orien = 3.1415926 - inputdata_1.front()->ori;
        gx = inputdata_1.front()->x - (ry * cos(orien) - rx * sin(orien));
        gy = inputdata_1.front()->y + (ry * sin(orien) + rx * cos(orien));

        // 6.计算激光点在地图中的位置 单位 pixel
        int mapx, mapy;
        mapx = (gx) / params->mapRes - params->ZeroX;
        mapy = (gy) / params->mapRes - params->ZeroY;

        // 7.调用函数计算当前激光束途经的栅格点坐标序列（地图中的像素坐标），存储在std::vector<Location> locationVec中，各栅格点坐标按照激光发射方向排列。
        int location_mapx, location_mapy;
        location_mapx = inputdata_1.front()->x / params->mapRes - params->ZeroX;
        location_mapy = inputdata_1.front()->y / params->mapRes - params->ZeroY;
        std::vector<Location> locationVec;
        Location startPos(location_mapx, location_mapy);
        Location endPos(mapx, mapy);
        CalcShortestDistance(startPos, endPos, locationVec);

        // 8.根据 Grid Counting 地图生成方法制图。
        // 地图存储在vars->map[][]中，坐标轴为vars->map[y][x]。
        // 定义每个栅格vars->map[y][x]取值上下界。
        double upthres = 300;
        double lowthres = -300;
        // 逐个更新当前激光束途经的栅格点坐标，params->logodd_free，params->logodd_occu为检测到当前坐标为无障碍/有障碍的更新值。
        // printf("mapWidth=%d, mapHeight=%d\n", params->mapWidth, params->mapHeight); // 640, 600
        static int hit[600][640] = {{0}};
        static int miss[600][640] = {{0}};
        for (std::vector<Location>::iterator c = locationVec.begin(); c != locationVec.end(); c++)
        {
            if ((*c).x >= 0 && (*c).x < params->mapWidth && (*c).y >= 0 && (*c).y < params->mapHeight)
            {
                if (c + 1 == locationVec.end())
                {
                    hit[(*c).y][(*c).x]++;
                }
                else
                {
                    miss[(*c).y][(*c).x]++;
                }
                vars->map[(*c).y][(*c).x] = -300 + 600 * hit[(*c).y][(*c).x] / (hit[(*c).y][(*c).x] + miss[(*c).y][(*c).x]);
            }
        }
        //==============================================================================
        //-----------------Please edit above--------------------------------------------
        //==============================================================================
    }

    outputdata->singlelaser = cv::Mat::zeros(600, 600, CV_8UC3);

    for (int i = 0; i < inputparams_0.front()->rng / inputparams_0.front()->res; i++)
    {
        double pi = 3.1415926;
        double theta = (0 + inputparams_0.front()->res * i) * pi / 180;
        double distance = inputdata_0.front()->data[i] / 20;
        // 在图像坐标系下，激光点位置与激光器位置距离在图像坐标轴方向上投影分别为x,y
        int x = int(distance * cos(theta));
        int y = int(distance * sin(theta));
        int centerx = 300;
        int centery = 300;

        // 绘制激光束或激光点
        if (distance > 1)
        {
            cv::line(outputdata->singlelaser, cv::Point2d(centerx, centery), cv::Point2d(x + centerx, y + centery), cv::Scalar(0, 255, 0), 1.5);
        }
        else
        {
            // cv::circle(outputdata->singlelaser,cv::Point2d(x+centerx,-y+centery),1,cv::Scalar(0,255,0),1);
        }
        cv::circle(outputdata->singlelaser, cv::Point2d(x + centerx, y + centery), 2, cv::Scalar(255, 255, 0), 1.5);
    }
    cv::circle(outputdata->singlelaser, cv::Point2d(300, 300), 3, cv::Scalar(255, 0, 0), 5);
    // 绘制时间戳
    char timestamp[50];
    sprintf(timestamp, "timestamp=%d", inputdata_1.front()->timestamp);
    cv::putText(outputdata->singlelaser, timestamp, cv::Point2d(20, 20), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 0.5);

    for (int i = 0; i < params->mapHeight; i++)
    {
        memcpy(outputdata->map[i], vars->map[i], sizeof(double) * params->mapWidth); // 拷贝给输出
    }

    outputdata->timestamp_GPS = inputdata_0.front()->timestamp;
    outputdata->timestamp_laser = inputdata_1.front()->timestamp;
    outputdata->mapPOSX = inputdata_1.front()->x;
    outputdata->mapPOSY = inputdata_1.front()->y;
    outputdata->mapPOSOri = inputdata_1.front()->ori;
    return 1;
}
