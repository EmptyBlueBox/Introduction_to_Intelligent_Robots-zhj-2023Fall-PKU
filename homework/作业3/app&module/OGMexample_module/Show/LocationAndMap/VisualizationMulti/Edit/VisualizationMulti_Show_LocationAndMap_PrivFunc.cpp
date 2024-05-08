//You need to program this file.

#include "../NoEdit/VisualizationMulti_Show_LocationAndMap_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
    XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
    VisualizationMulti_Show_LocationAndMap_Params * params=(VisualizationMulti_Show_LocationAndMap_Params *)paramsPtr;
    VisualizationMulti_Show_LocationAndMap_Vars * vars=(VisualizationMulti_Show_LocationAndMap_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: open node.
    Procedure:
    1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
    2: initialize variables (vars).
    3: If everything is OK, return 1 for successful opening and vice versa.
    */
    GetParamValue(xmlloader,params,mapWidth);//从xml读取
    GetParamValue(xmlloader,params,mapHeight);
    GetParamValue(xmlloader,params,ZeroX);
    GetParamValue(xmlloader,params,ZeroY);
    GetParamValue(xmlloader,params,mapRes);
    GetParamValue(xmlloader,params,mapGrid);

    vars->accumap=cv::Mat::zeros(abs(params->mapHeight),abs(params->mapWidth),CV_8UC3);
    vars->init=true;
    vars->mapview->setText("Opened");

    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
    VisualizationMulti_Show_LocationAndMap_Params * params=(VisualizationMulti_Show_LocationAndMap_Params *)paramsPtr;
    VisualizationMulti_Show_LocationAndMap_Vars * vars=(VisualizationMulti_Show_LocationAndMap_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: close node.
    Procedure:
    1: handle/close variables (vars).
    2: If everything is OK, return 1 for successful closing and vice versa.
    */
    vars->mapview->setText("Closed");
    return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
    VisualizationMulti_Show_LocationAndMap_Params * params=(VisualizationMulti_Show_LocationAndMap_Params *)paramsPtr;
    VisualizationMulti_Show_LocationAndMap_Vars * vars=(VisualizationMulti_Show_LocationAndMap_Vars *)varsPtr;
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

void DECOFUNC(getMultiDrainDataSize)(void * paramsPtr, void * varsPtr, QList<int> & drainDataSize)
{
    VisualizationMulti_Show_LocationAndMap_Params * params=(VisualizationMulti_Show_LocationAndMap_Params *)paramsPtr;
    VisualizationMulti_Show_LocationAndMap_Vars * vars=(VisualizationMulti_Show_LocationAndMap_Vars *)varsPtr;
    drainDataSize=QList<int>()<<0<<0;
    /*======Please Program above======*/
    /*
    Function: get drain data size to be grabbed from buffer.
    Rules:
    drainDataSize=0: grab and remove all data from buffer.
    drainDataSize>0: grab drainDataSize latest data from buffer.
    drainDataSize<0: grab and remove drainDataSize ancient data from buffer.
    E.g.
    drainDataSize=QList<int>()<<0<<1<<-1...;
    */
}

//Input Port #0: Buffer_Size = 1, Params_Type = ProcessorMulti_Algor_Mapping_Params, Data_Type = ProcessorMulti_Algor_Mapping_Data
//Input Port #1: Buffer_Size = 5, Params_Type = Simulator_Sensor_GPS_Params, Data_Type = Simulator_Sensor_GPS_Data
bool DECOFUNC(processMultiDrainData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > drainParams, QVector<QVector<void *> > drainData)
{
    VisualizationMulti_Show_LocationAndMap_Params * params=(VisualizationMulti_Show_LocationAndMap_Params *)paramsPtr;
    VisualizationMulti_Show_LocationAndMap_Vars * vars=(VisualizationMulti_Show_LocationAndMap_Vars *)varsPtr;
    QVector<ProcessorMulti_Algor_Mapping_Params *> drainparams_0; copyQVector(drainparams_0,drainParams[0]);
    QVector<Simulator_Sensor_GPS_Params *> drainparams_1; copyQVector(drainparams_1,drainParams[1]);
    QVector<ProcessorMulti_Algor_Mapping_Data *> draindata_0; copyQVector(draindata_0,drainData[0]);
    QVector<Simulator_Sensor_GPS_Data *> draindata_1; copyQVector(draindata_1,drainData[1]);
    if(draindata_0.size()==0||draindata_1.size()==0){
        vars->mapview->setText("No Data");
        return 0;
    }
    /*======Please Program below======*/
    /*
    Function: process draindata_index.
    */
    int currentX=draindata_1.front()->x/ params->mapRes-params->ZeroX;
    int currentY=draindata_1.front()->y/ params->mapRes-params->ZeroY;

    for(int i = 0 ; i <params->mapHeight ; i ++)
    {
        for(int j = 0 ; j < params->mapWidth ; j ++)
        {
            if (vars->accumap.at<cv::Vec3b>(i,j)[0]==0&&
                    vars->accumap.at<cv::Vec3b>(i,j)[1]==255&&
                    vars->accumap.at<cv::Vec3b>(i,j)[2]==0)
                continue;

            double tmp=100-draindata_0.front()->map[i][j];
            tmp=tmp>255?255:tmp;
            tmp=tmp<0?0:tmp;
            vars->accumap.at<cv::Vec3b>(i,j)[0]=tmp;
            vars->accumap.at<cv::Vec3b>(i,j)[1]=tmp;
            vars->accumap.at<cv::Vec3b>(i,j)[2]=tmp;

        }
    }
    //draw traj
    if(vars->init){
        vars->lastX=currentX;
        vars->lastY=currentY;
        vars->init=false;

    }
    else{
        cv::line(vars->accumap,cv::Point2d(vars->lastX,vars->lastY),cv::Point2d(currentX,currentY),cv::Scalar(0,255,0),2);
        vars->lastX=currentX;
        vars->lastY=currentY;
    }
    //绘制网格
    //网格宽（像素数
    int interval = params->mapGrid /params->mapRes;
    for(int i=interval;i<params->mapWidth;i+=interval)
    {
        cv::Point2d start=cv::Point2d(i,0);
        cv::Point2d end=cv::Point2d(i,abs(params->mapHeight));
        cv::line(vars->accumap,start,end,cv::Scalar(255,0,0));
        int a=3;
    }
    for(int i=interval;i<abs(params->mapHeight);i+=interval)
    {
        cv::Point2d start=cv::Point2d(0,i);
        cv::Point2d end=cv::Point2d(abs(params->mapWidth),i);
        cv::line(vars->accumap,start,end,cv::Scalar(255,0,0));
    }
    char timestamp[50];char gridwidth[50];

    vars->premap=vars->accumap.clone();
    //绘制实时位置
    cv::circle(vars->premap,cv::Point2d(currentX,currentY),1,cv::Scalar(0,0,255),2);
    //绘制数据源的时间戳
    sprintf(timestamp,"timestamp_GPS=%d",draindata_0.front()->timestamp_GPS);
    cv::putText(vars->premap,timestamp,cv::Point2d(20,20),cv::FONT_HERSHEY_SIMPLEX,0.5,cv::Scalar(0,0,255),0.5);
    sprintf(timestamp,"timestamp_laser=%d",draindata_0.front()->timestamp_laser);
    cv::putText(vars->premap,timestamp,cv::Point2d(20,40),cv::FONT_HERSHEY_SIMPLEX,0.5,cv::Scalar(0,0,255),0.5);
    sprintf(gridwidth,"Grid Width=%dm",params->mapGrid);
    cv::putText(vars->premap,gridwidth,cv::Point2d(params->mapWidth-160,20),cv::FONT_HERSHEY_SIMPLEX,0.5,cv::Scalar(0,0,255),0.5);
    QImage img((const uchar*)vars->premap.data,vars->premap.cols,vars->premap.rows,vars->premap.step,QImage::Format_RGB888);
    cv::cvtColor(vars->premap,vars->premap,CV_RGB2BGR);
    vars->mapview->setPixmap(QPixmap::fromImage(img));
    cv::Mat a=draindata_0.front()->singlelaser.clone();
    QImage img2((const uchar*)a.data,a.cols,a.rows,a.step,QImage::Format_RGB888);

    vars->mapview->setPixmap(QPixmap::fromImage(img));
    vars->laserview->setPixmap(QPixmap::fromImage(img2));
    return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
    VisualizationMulti_Show_LocationAndMap_Params * params=(VisualizationMulti_Show_LocationAndMap_Params *)paramsPtr;
    VisualizationMulti_Show_LocationAndMap_Vars * vars=(VisualizationMulti_Show_LocationAndMap_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<(vars->mapview)<<(vars->laserview);
    /*======Please Program above======*/
    /*
    Function: get visualization widgets [defined in vars].
    You need to program here when you need visualization widgets.
    E.g.
    widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
    */
}

