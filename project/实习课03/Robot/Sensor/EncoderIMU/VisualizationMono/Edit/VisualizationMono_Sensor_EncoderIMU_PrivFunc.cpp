//You need to program this file.

#include "../NoEdit/VisualizationMono_Sensor_EncoderIMU_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
    XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
    VisualizationMono_Sensor_EncoderIMU_Params * params=(VisualizationMono_Sensor_EncoderIMU_Params *)paramsPtr;
    VisualizationMono_Sensor_EncoderIMU_Vars * vars=(VisualizationMono_Sensor_EncoderIMU_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: open node.
    Procedure:
    1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
    2: initialize variables (vars).
    3: If everything is OK, return 1 for successful opening and vice versa.
    */
    GetParamValue(xmlloader, params, mapSize);
    GetParamValue(xmlloader, params, pixelSize);
    GetParamValue(xmlloader, vars, showHeight);

    vars->mapZero.x = 0;
    vars->mapZero.y = 0;
    vars->map.create(cv::Size(params->mapSize, params->mapSize), CV_8UC3);
    vars->map.setTo(0);
    vars->qmap->setText("Opened");
    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
    VisualizationMono_Sensor_EncoderIMU_Params * params=(VisualizationMono_Sensor_EncoderIMU_Params *)paramsPtr;
    VisualizationMono_Sensor_EncoderIMU_Vars * vars=(VisualizationMono_Sensor_EncoderIMU_Vars *)varsPtr;
    /*======Please Program below======*/
    /*
    Function: close node.
    Procedure:
    1: handle/close variables (vars).
    2: If everything is OK, return 1 for successful closing and vice versa.
    */
    vars->qmap->setText("Closed");
    return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
    VisualizationMono_Sensor_EncoderIMU_Params * params=(VisualizationMono_Sensor_EncoderIMU_Params *)paramsPtr;
    VisualizationMono_Sensor_EncoderIMU_Vars * vars=(VisualizationMono_Sensor_EncoderIMU_Vars *)varsPtr;
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
    VisualizationMono_Sensor_EncoderIMU_Params * params=(VisualizationMono_Sensor_EncoderIMU_Params *)paramsPtr;
    VisualizationMono_Sensor_EncoderIMU_Vars * vars=(VisualizationMono_Sensor_EncoderIMU_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = SourceDrainMono_Sensor_EncoderIMU_Params, Data_Type = SourceDrainMono_Sensor_EncoderIMU_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
    VisualizationMono_Sensor_EncoderIMU_Params * params=(VisualizationMono_Sensor_EncoderIMU_Params *)paramsPtr;
    VisualizationMono_Sensor_EncoderIMU_Vars * vars=(VisualizationMono_Sensor_EncoderIMU_Vars *)varsPtr;
    QVector<SourceDrainMono_Sensor_EncoderIMU_Params *> drainparams; copyQVector(drainparams,drainParams);
    QVector<SourceDrainMono_Sensor_EncoderIMU_Data *> draindata; copyQVector(draindata,drainData);
    if(draindata.size()==0){return 0;}
    /*======Please Program below======*/
    /*
    Function: process draindata.
    */
    int minshiftx = 1, minshifty = 1;
    int dx,dy;
    cv::Point2d p;
    p.x = (int)(draindata.front()->x / params->pixelSize) * params->pixelSize;
    p.y = (int)(draindata.front()->y / params->pixelSize) * params->pixelSize;
    dx = p.x-vars->mapZero.x / params->pixelSize;
    dy = p.y-vars->mapZero.y / params->pixelSize;
//    if (abs(dx) > minshiftx ||  abs(dy) > minshifty) {
//        vars->mapZero = p;
//        if (abs(dx)>=vars->map.cols/2 || abs(dy)>=vars->map.rows/2) {
//            vars->map.setTo(0);
//        } else {
//            cv::Mat M(2,3,CV_32F);
//            M.at<float>(0,0)=1;M.at<float>(0,1)=0;M.at<float>(0,2)=-dx;
//            M.at<float>(1,0)=0;M.at<float>(1,1)=1;M.at<float>(1,2)=dy;
//            cv::warpAffine(vars->map,vars->map,M,vars->map.size());
//        }
//    }

    cv::Scalar c_red   = CV_RGB(0, 0, 255);
    cv::Scalar c_blue  = CV_RGB(255, 144, 30);
    cv::Scalar c_green = CV_RGB(37, 225, 132);
    cv::Scalar c_gold  = CV_RGB(1, 215, 255);
    cv::Scalar c_darkBlue = CV_RGB(186, 30, 13);


    cv::Point2d mapp = cv::Point2d(draindata.front()->x, draindata.front()->y);
    mapp -= vars->mapZero;
    mapp.x = mapp.x / params->pixelSize + params->mapSize / 2;
    mapp.y = mapp.y / params->pixelSize + params->mapSize / 2;
    mapp.y = vars->map.rows - mapp.y;
    circle(vars->map, mapp, 2, c_gold, -1);

    cv::Mat gridmap3(cv::Size(params->mapSize, params->mapSize), CV_8UC3);
    gridmap3.setTo(0);
    cv::Mat gridmap1(cv::Size(params->mapSize, params->mapSize), CV_8UC1);
    gridmap1.setTo(0);
    int grid = 10.0 / params->pixelSize;

    for(int i = params->mapSize % grid ; i < params->mapSize ; i+= grid) {
        cv::line(gridmap3, cv::Point(i,0), cv::Point(i, params->mapSize), c_darkBlue, 1);
        cv::line(gridmap1, cv::Point(i,0), cv::Point(i, params->mapSize), cv::Scalar(255), 1);
    }
    for(int i = params->mapSize - grid ; i > 0 ; i -= grid) {
        cv::line(gridmap3, cv::Point(0, i), cv::Point(params->mapSize, i), c_darkBlue, 1);
        cv::line(gridmap1, cv::Point(0, i), cv::Point(params->mapSize, i), cv::Scalar(255), 1);
    }
    cv::bitwise_not(gridmap1, gridmap1);
    vars->map.copyTo(gridmap3, gridmap1);
    cv::circle(gridmap3, cv::Point(params->mapSize / 2, params->mapSize / 2), 1, c_red);

    gridmap3(cv::Rect(params->mapSize - grid + 1, 0, grid - 1, grid - 1)).setTo(0);
    cv::Point composso = cv::Point(params->mapSize - grid / 2, grid / 2);
    cv::circle(gridmap3, composso, grid / 2 - 1, c_green, 1, CV_AA);
    cv::line(gridmap3, composso,
             cv::Point(composso.x + sin(-draindata.front()->orientation) * (grid - 1) / 2 - 1,
                       composso.y - cos(-draindata.front()->orientation) * (grid - 1) / 2 - 1),
             c_green, 1, CV_AA);

    gridmap3(cv::Rect(0, 0, 2 * grid - 1, grid - 1)).setTo(0);

    cv::putText(gridmap3, QString("(%1, %2)").arg(draindata.front()->x).arg(draindata.front()->y).toStdString(),
                cv::Point(0, 20), CV_FONT_BLACK, 0.8, c_red, 1, CV_AA);
    cv::putText(gridmap3,QString("%1 m/s").arg(draindata.front()->speed).toStdString(),
                cv::Point(0,40), CV_FONT_BLACK, 0.8, c_red, 1, CV_AA);
    cv::putText(gridmap3,QString("%1 m").arg(draindata.front()->odometry).toStdString(),
                cv::Point(0,60), CV_FONT_BLACK, 0.8, c_red, 1, CV_AA);
    long timestamp=((draindata.front()->qtimestamp.hour() * 60 + draindata.front()->qtimestamp.minute()) * 60 +
                    draindata.front()->qtimestamp.second()) * 1000 + draindata.front()->qtimestamp.msec();
    cv::putText(gridmap3,QString("%1 ms").arg(timestamp).toStdString(),
                cv::Point(0,80), CV_FONT_BLACK, 0.8, c_red, 1, CV_AA);

    int showWidth = vars->showHeight;
    cv::Mat showImage (cv::Size(showWidth, vars->showHeight), CV_8UC3);
    cv::resize(gridmap3, showImage, showImage.size());

    QImage img = QImage((const uchar*)(showImage.data), showImage.cols, showImage.rows, showImage.cols * showImage.channels(),
                        QImage::Format_RGB888);
    vars->qmap->setPixmap(QPixmap::fromImage(img));
    return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
    VisualizationMono_Sensor_EncoderIMU_Params * params=(VisualizationMono_Sensor_EncoderIMU_Params *)paramsPtr;
    VisualizationMono_Sensor_EncoderIMU_Vars * vars=(VisualizationMono_Sensor_EncoderIMU_Vars *)varsPtr;
    widgets=QList<QWidget *>() << vars->qmap;
    /*======Please Program above======*/
    /*
    Function: get visualization widgets [defined in vars].
    You need to program here when you need visualization widgets.
    E.g.
    widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
    */
}

