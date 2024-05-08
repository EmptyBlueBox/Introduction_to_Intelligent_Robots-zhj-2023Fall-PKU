//You need to program this file.

#include "../NoEdit/SensorTimer_Sensor_xtion_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorTimer_Sensor_xtion_Params * params=(SensorTimer_Sensor_xtion_Params *)paramsPtr;
	SensorTimer_Sensor_xtion_Vars * vars=(SensorTimer_Sensor_xtion_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader, params, fps);
    GetParamValue(xmlloader, params, width);
    GetParamValue(xmlloader, params, height);
    const char * deviceURL = openni::ANY_DEVICE;
    openni::Status rc;
    rc = openni::OpenNI::initialize();
    if (rc != openni::STATUS_OK) {
        return 0;
    }
    rc = vars->device.open(deviceURL);
    if (rc != openni::STATUS_OK) {
        qDebug() << openni::OpenNI::getExtendedError();
        return 0;
    }

    rc = vars->oniDepthStream.create(vars->device, openni::SENSOR_DEPTH);


    if(rc == openni::STATUS_OK) {
        openni::VideoMode modeDepth;
        modeDepth.setResolution(params->width, params->height);
        modeDepth.setFps(params->fps);
        modeDepth.setPixelFormat(openni::PIXEL_FORMAT_DEPTH_1_MM);
        vars->oniDepthStream.setVideoMode(modeDepth);
        rc = vars->oniDepthStream.start();
        if (rc != openni::STATUS_OK) {
            return 0;
        }
    } else {
        return 0;
    };

    rc = vars->oniColorStream.create(vars->device, openni::SENSOR_COLOR);
    if (rc == openni::STATUS_OK) {
        openni::VideoMode modeColor;
        modeColor.setResolution(params->width, params->height);
        modeColor.setFps(30);
        modeColor.setPixelFormat(openni::PIXEL_FORMAT_RGB888);
        vars->oniColorStream.setVideoMode(modeColor);
        rc = vars->oniColorStream.start();
        if(rc != openni::STATUS_OK) {
            return 0;
        }
    } else {
        return 0;
    }

    if (vars->device.isImageRegistrationModeSupported(openni::IMAGE_REGISTRATION_DEPTH_TO_COLOR)) {
        vars->device.setImageRegistrationMode(openni::IMAGE_REGISTRATION_DEPTH_TO_COLOR);
    }

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorTimer_Sensor_xtion_Params * params=(SensorTimer_Sensor_xtion_Params *)paramsPtr;
	SensorTimer_Sensor_xtion_Vars * vars=(SensorTimer_Sensor_xtion_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    if (vars->oniDepthStream.isValid()) {
        vars->oniDepthStream.destroy();
    }
    if (vars->oniColorStream.isValid()) {
        vars->oniColorStream.destroy();
    }
    if (vars->device.isValid()) {
        vars->device.close();
        openni::OpenNI::shutdown();
    }
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SensorTimer_Sensor_xtion_Params * params=(SensorTimer_Sensor_xtion_Params *)paramsPtr;
	SensorTimer_Sensor_xtion_Vars * vars=(SensorTimer_Sensor_xtion_Vars *)varsPtr;
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
	SensorTimer_Sensor_xtion_Params * params=(SensorTimer_Sensor_xtion_Params *)paramsPtr;
	SensorTimer_Sensor_xtion_Vars * vars=(SensorTimer_Sensor_xtion_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SensorTimer_Sensor_xtion_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorTimer_Sensor_xtion_Params * params=(SensorTimer_Sensor_xtion_Params *)paramsPtr;
	SensorTimer_Sensor_xtion_Vars * vars=(SensorTimer_Sensor_xtion_Vars *)varsPtr;
	SensorTimer_Sensor_xtion_Data * outputdata=(SensorTimer_Sensor_xtion_Data *)outputData;
	outputPortIndex=QList<int>();
    timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    if (vars->oniDepthStream.readFrame(&vars->oniDepthImg) == openni::STATUS_OK) {
        cv::Mat cvRawImg16U(vars->oniDepthImg.getHeight(), vars->oniDepthImg.getWidth(), CV_16UC1, (void*)vars->oniDepthImg.getData());
        // TODO save 16bit image
        outputdata->cvDepthImg = cvRawImg16U;
//        cvRawImg16U.convertTo(outputdata->cvDepthImg, CV_8U, 255.0 / 4096.0);
    } else {
        return 0;
    }
    if (vars->oniColorStream.readFrame(&vars->oniColorImg) == openni::STATUS_OK) {
        cv::Mat cvRGBImg(vars->oniColorImg.getHeight(), vars->oniColorImg.getWidth(), CV_8UC3, (void*)vars->oniColorImg.getData());
        cv::cvtColor(cvRGBImg, outputdata->cvColorImg, CV_RGB2BGR);
    } else {
        return 0;
    }
    outputdata->qtimestamp = QTime::currentTime();
	return 1;
}

