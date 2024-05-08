//You need to program this file.

#include "../NoEdit/VisualizationMono_Sensor_URG_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Sensor_URG_Params * params=(VisualizationMono_Sensor_URG_Params *)paramsPtr;
	VisualizationMono_Sensor_URG_Vars * vars=(VisualizationMono_Sensor_URG_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, range);
    GetParamValue(xmlloader, params, interval);
    GetParamValue(xmlloader, params, imageRadius);
    GetParamValue(xmlloader, params, frontOnly);
    GetParamValue(xmlloader, params, laserBeam);
    vars->beams->setText("Opened");
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Sensor_URG_Params * params=(VisualizationMono_Sensor_URG_Params *)paramsPtr;
	VisualizationMono_Sensor_URG_Vars * vars=(VisualizationMono_Sensor_URG_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->beams->setText("Closed");
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Sensor_URG_Params * params=(VisualizationMono_Sensor_URG_Params *)paramsPtr;
	VisualizationMono_Sensor_URG_Vars * vars=(VisualizationMono_Sensor_URG_Vars *)varsPtr;
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
	VisualizationMono_Sensor_URG_Params * params=(VisualizationMono_Sensor_URG_Params *)paramsPtr;
	VisualizationMono_Sensor_URG_Vars * vars=(VisualizationMono_Sensor_URG_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 1, Params_Type = SensorTimer_Sensor_URG_Params, Data_Type = SensorTimer_Sensor_URG_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Sensor_URG_Params * params=(VisualizationMono_Sensor_URG_Params *)paramsPtr;
	VisualizationMono_Sensor_URG_Vars * vars=(VisualizationMono_Sensor_URG_Vars *)varsPtr;
	QVector<SensorTimer_Sensor_URG_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<SensorTimer_Sensor_URG_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    vars->startangle = 90 + drainparams.front()->first_step * 0.25;
    vars->endtangle  = 90 + drainparams.front()->last_step * 0.25;
    vars->resolution = drainparams.front()->skip_step * 0.25;

    QImage image;
    if (params->frontOnly) {
        image = QImage(params->imageRadius * 2, params->imageRadius,     QImage::Format_RGBA8888);
    } else {
        image = QImage(params->imageRadius * 2, params->imageRadius * 2, QImage::Format_RGBA8888);
    }
    image.fill(32);
    vars->painter.begin(&image);

    QPen centerPen(QColor(255,0,0,255));
    QPen gridPen(QColor(0,255,0,128));
    QPen beamPen(QColor(0,0,255,196));
    QPen textPen(Qt::black);

    int centerx = params->imageRadius;
    int centery = params->imageRadius;

    vars->painter.setPen(gridPen);
    vars->painter.setBrush(Qt::NoBrush);
    int count;
    count = params->range / params->interval;
    int radiusStep = params->imageRadius / count;
    for(int i = 1; i <= count; i++) {
        int radius = i * radiusStep;
        vars->painter.drawEllipse(QPoint(centerx, centery), radius, radius);
    }

    vars->painter.setPen(beamPen);
    double ratio = double(params->imageRadius) / double(params->range);
    count = draindata.front()->datasize;
    for(int i = 0; i < count; i++) {
        double theta = (vars->startangle + vars->resolution * i) / 180.0 * M_PI;
        double distance = 3 * ratio * (draindata.front()->data[i]);
        int x = cvRound( distance * cos(theta));
        int y = cvRound(-distance * sin(theta));
        if(params->laserBeam) {
            vars->painter.drawLine(centerx, centery, x + centerx, y + centery);
        } else {
            vars->painter.drawEllipse(x + centerx, y + centery, 2, 2);
        }
    }

    QFontMetrics fm = vars->painter.fontMetrics();
    int height = fm.ascent() + fm.descent();
    vars->painter.setPen(textPen);
    vars->painter.drawText(0, height,     QString("Interval = %1 cm").arg(params->interval));
    vars->painter.drawText(0, height * 2, QString("System Time: %1").arg(draindata.front()->qtimestamp.toString("HH:mm:ss:zzz")));
//    vars->painter.drawText(0, height * 3, QString("URG Time: %1").arg(draindata.front()->qtimestamp));

    vars->painter.setPen(centerPen);
    vars->painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    vars->painter.drawEllipse(QPoint(centerx, centery), 2, 2);

    vars->painter.end();
    vars->beams->setPixmap(QPixmap::fromImage(image));
	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Sensor_URG_Params * params=(VisualizationMono_Sensor_URG_Params *)paramsPtr;
	VisualizationMono_Sensor_URG_Vars * vars=(VisualizationMono_Sensor_URG_Vars *)varsPtr;
    widgets=QList<QWidget *>() << vars->beams;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

