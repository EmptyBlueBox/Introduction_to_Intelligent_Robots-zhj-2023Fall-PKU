//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_ENCODERIMU_VARS_H
#define VISUALIZATIONMONO_SENSOR_ENCODERIMU_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_EncoderIMU_Vars VisualizationMono_Sensor_EncoderIMU_Vars
	\ingroup VisualizationMono_Sensor_EncoderIMU
	\brief VisualizationMono_Sensor_EncoderIMU_Vars defines the Vars in VisualizationMono_Sensor_EncoderIMU.
*/

/*! \addtogroup VisualizationMono_Sensor_EncoderIMU_Vars
	@{
*/

/*! \file VisualizationMono_Sensor_EncoderIMU_Vars.h
	 Defines the Vars of VisualizationMono_Sensor_EncoderIMU
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Sensor_EncoderIMU_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Sensor_EncoderIMU_Vars 
	\brief The Vars of VisualizationMono_Sensor_EncoderIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_EncoderIMU_Vars 
{
public:
	/*! \fn VisualizationMono_Sensor_EncoderIMU_Vars()
		\brief The constructor of VisualizationMono_Sensor_EncoderIMU_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_EncoderIMU_Vars() 
	{
        qmap = new QLabel();
        qmap->setAlignment(Qt::AlignCenter);
        showHeight = 350;
	}
	/*! \fn ~VisualizationMono_Sensor_EncoderIMU_Vars()
		\brief The destructor of VisualizationMono_Sensor_EncoderIMU_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_EncoderIMU_Vars() 
	{
        delete qmap;
	}
public:
	//*******************Please add variables below*******************
    cv::Point2d mapZero;
    cv::Mat map;
    QLabel *qmap;
    int showHeight;
};

/*! @}*/ 

#endif
