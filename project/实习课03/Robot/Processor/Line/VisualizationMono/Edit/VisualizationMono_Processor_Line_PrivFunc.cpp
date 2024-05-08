//You need to program this file.

#include "../NoEdit/VisualizationMono_Processor_Line_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Processor_Line_Params * params=(VisualizationMono_Processor_Line_Params *)paramsPtr;
	VisualizationMono_Processor_Line_Vars * vars=(VisualizationMono_Processor_Line_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, scale);
    GetParamValue(xmlloader, params, width);
    GetParamValue(xmlloader, params, height);
    GetParamValue(xmlloader, params, offsetWidth);
    GetParamValue(xmlloader, params, offsetHeight);
    vars->ob->setText("Open");
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Processor_Line_Params * params=(VisualizationMono_Processor_Line_Params *)paramsPtr;
	VisualizationMono_Processor_Line_Vars * vars=(VisualizationMono_Processor_Line_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->ob->setText("Closed");
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Processor_Line_Params * params=(VisualizationMono_Processor_Line_Params *)paramsPtr;
	VisualizationMono_Processor_Line_Vars * vars=(VisualizationMono_Processor_Line_Vars *)varsPtr;
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
	VisualizationMono_Processor_Line_Params * params=(VisualizationMono_Processor_Line_Params *)paramsPtr;
	VisualizationMono_Processor_Line_Vars * vars=(VisualizationMono_Processor_Line_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 1, Params_Type = ProcessorMulti_Processor_Line_Params, Data_Type = ProcessorMulti_Processor_Line_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Processor_Line_Params * params=(VisualizationMono_Processor_Line_Params *)paramsPtr;
	VisualizationMono_Processor_Line_Vars * vars=(VisualizationMono_Processor_Line_Vars *)varsPtr;
	QVector<ProcessorMulti_Processor_Line_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMulti_Processor_Line_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    cv::Mat toShow;
    toShow = cv::Mat::zeros(params->height, params->width, CV_8UC3);

    ProcessorMulti_Processor_Line_Data *data = draindata.front();
    if (data->obPoints.size() == 0) {
        cv::putText(toShow, "Safe", cv::Point(40, 40), CV_FONT_NORMAL, 1.5, CV_RGB(0, 255, 0));
    }

    for (int i = 0; i < data->safeZone.size(); i++) {
        int x = data->safeZone[i].x * params->scale + params->offsetWidth;
        int y = data->safeZone[i].y * params->scale + params->offsetHeight;
        if (x >= 0 && x < params->width && y >= 0 && y < params->height)
            toShow.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 255, 255);
    }

    for (int i = 0; i < data->laserPoints.size(); i++) {
        int x = data->laserPoints[i].x * params->scale + params->offsetWidth;
        int y = data->laserPoints[i].y * params->scale + params->offsetHeight;
        if (x >= 0 && x < params->width && y >= 0 && y < params->height)
            toShow.at<cv::Vec3b>(y, x) = cv::Vec3b(255, 255, 255);
    }
    for (int i = 0; i < data->obPoints.size(); i++) {
        int x = data->obPoints[i].x * params->scale + params->offsetWidth;
        int y = data->obPoints[i].y * params->scale + params->offsetHeight;
        if (x >= 0 && x < params->width && y >= 0 && y < params->height)
            toShow.at<cv::Vec3b>(y, x) = cv::Vec3b(255, 0, 0);
    }
    cv::circle(toShow, cv::Point(params->offsetWidth, params->offsetHeight), 1, CV_RGB(255, 255, 0));

    QImage qColorImg((const uchar*)toShow.data, toShow.cols, toShow.rows,
                     toShow.step, QImage::Format_RGB888);
    vars->ob->setPixmap(QPixmap::fromImage(qColorImg));
	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Processor_Line_Params * params=(VisualizationMono_Processor_Line_Params *)paramsPtr;
	VisualizationMono_Processor_Line_Vars * vars=(VisualizationMono_Processor_Line_Vars *)varsPtr;
    widgets=QList<QWidget *>() << vars->ob;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

