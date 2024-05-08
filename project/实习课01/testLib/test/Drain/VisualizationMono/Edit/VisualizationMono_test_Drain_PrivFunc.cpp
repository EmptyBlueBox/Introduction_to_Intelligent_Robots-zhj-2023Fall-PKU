//You need to program this file.

#include "../NoEdit/VisualizationMono_test_Drain_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_test_Drain_Params * params=(VisualizationMono_test_Drain_Params *)paramsPtr;
	VisualizationMono_test_Drain_Vars * vars=(VisualizationMono_test_Drain_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    //---------------------------------------------------Key Code---------------------------------------------------------------------------------------
    GetParamValue(xmlloader, params, width);
    GetParamValue(xmlloader, params, height);
    vars->imgCar = cv::imread("/home/rsys/SDK/RobotSDK/ModuleDev/testLib/car.png");
    vars->mask   = cv::imread("/home/rsys/SDK/RobotSDK/ModuleDev/testLib/car.png", 0);
    vars->cvMap.create(params->height, params->width, CV_8UC3);
    vars->map->setAlignment(Qt::AlignCenter);
    vars->map->setPixmap(VisualizationMono_test_Drain_Vars::Mat2QPixmap(vars->cvMap));
    //---------------------------------------------------Key Code---------------------------------------------------------------------------------------

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_test_Drain_Params * params=(VisualizationMono_test_Drain_Params *)paramsPtr;
	VisualizationMono_test_Drain_Vars * vars=(VisualizationMono_test_Drain_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->map->setText("Closed");
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_test_Drain_Params * params=(VisualizationMono_test_Drain_Params *)paramsPtr;
	VisualizationMono_test_Drain_Vars * vars=(VisualizationMono_test_Drain_Vars *)varsPtr;
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
	VisualizationMono_test_Drain_Params * params=(VisualizationMono_test_Drain_Params *)paramsPtr;
	VisualizationMono_test_Drain_Vars * vars=(VisualizationMono_test_Drain_Vars *)varsPtr;
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

//---------------------------------------------------Key Code---------------------------------------------------------------------------------------

void RotateImg(cv::Mat &rotatedImgCar, cv::Mat &rotatedMask, int direction)
{
    if (direction == 0) {   // up
        cv::transpose(rotatedImgCar, rotatedImgCar);
        cv::flip(rotatedImgCar, rotatedImgCar, 0);
        cv::transpose(rotatedMask, rotatedMask);
        cv::flip(rotatedMask, rotatedMask, 0);
    }
    if (direction == 1) {   // down
        cv::transpose(rotatedImgCar, rotatedImgCar);
        cv::flip(rotatedImgCar, rotatedImgCar, 1);
        cv::transpose(rotatedMask, rotatedMask);
        cv::flip(rotatedMask, rotatedMask, 1);
    }
    if (direction == 2) {   // left
        cv::flip(rotatedImgCar, rotatedImgCar, 1);
        cv::flip(rotatedMask, rotatedMask, 1);
    }
    if (direction == 3) {   // right
        // do nothing
    }
}

//---------------------------------------------------Key Code---------------------------------------------------------------------------------------

//Input Port #0: Buffer_Size = 1, Params_Type = ProcessorMono_test_Processor_Params, Data_Type = ProcessorMono_test_Processor_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_test_Drain_Params * params=(VisualizationMono_test_Drain_Params *)paramsPtr;
	VisualizationMono_test_Drain_Vars * vars=(VisualizationMono_test_Drain_Vars *)varsPtr;
	QVector<ProcessorMono_test_Processor_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMono_test_Processor_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
    */

    //---------------------------------------------------Key Code---------------------------------------------------------------------------------------

    int direction = draindata.front()->direction;

    int x = draindata.front()->x, y = draindata.front()->y;
    vars->cvMap.copyTo(vars->cvMap2Show);
    cv::Mat rotatedImgCar;
    vars->imgCar.copyTo(rotatedImgCar);
    cv::Mat rotatedMask;
    vars->mask.copyTo(rotatedMask);
    RotateImg(rotatedImgCar, rotatedMask, direction);
    cv::Mat imgROI = vars->cvMap2Show(cv::Rect(x - rotatedImgCar.cols / 2.0,
                                               y - rotatedImgCar.rows / 2.0,
                                               rotatedImgCar.cols,
                                               rotatedImgCar.rows));
    cv::circle(vars->cvMap2Show, cv::Point(x, y), 2, CV_RGB(255, 0, 0));
    rotatedImgCar.copyTo(imgROI, rotatedMask);
    if (!vars->initial) {
        cv::line(vars->cvMap, cv::Point(x, y), cv::Point(vars->x, vars->y), CV_RGB(0, 255, 0));
    } else {
        vars->initial = false;
    }
    vars->x = x;
    vars->y = y;

    cv::putText(vars->cvMap2Show, QString("(%1,%2):%3").arg(vars->x).arg(vars->y).arg(vars->directions[direction]).toStdString(),
                cv::Point(10, 20), CV_FONT_HERSHEY_COMPLEX, 0.6, CV_RGB(255, 0, 0));
    vars->map->setPixmap(VisualizationMono_test_Drain_Vars::Mat2QPixmap(vars->cvMap2Show));

    //---------------------------------------------------Key Code---------------------------------------------------------------------------------------

	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_test_Drain_Params * params=(VisualizationMono_test_Drain_Params *)paramsPtr;
	VisualizationMono_test_Drain_Vars * vars=(VisualizationMono_test_Drain_Vars *)varsPtr;
    widgets=QList<QWidget *>() << vars->map;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

