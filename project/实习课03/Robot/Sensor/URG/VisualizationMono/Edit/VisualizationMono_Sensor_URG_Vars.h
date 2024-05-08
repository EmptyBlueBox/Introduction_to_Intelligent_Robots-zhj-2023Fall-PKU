//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_URG_VARS_H
#define VISUALIZATIONMONO_SENSOR_URG_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_URG_Vars VisualizationMono_Sensor_URG_Vars
	\ingroup VisualizationMono_Sensor_URG
	\brief VisualizationMono_Sensor_URG_Vars defines the Vars in VisualizationMono_Sensor_URG.
*/

/*! \addtogroup VisualizationMono_Sensor_URG_Vars
	@{
*/

/*! \file VisualizationMono_Sensor_URG_Vars.h
	 Defines the Vars of VisualizationMono_Sensor_URG
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Sensor_URG_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Sensor_URG_Vars 
	\brief The Vars of VisualizationMono_Sensor_URG.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_URG_Vars 
{
public:
	/*! \fn VisualizationMono_Sensor_URG_Vars()
		\brief The constructor of VisualizationMono_Sensor_URG_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_URG_Vars() 
	{
        beams = new QLabel();
        beams->setAlignment(Qt::AlignCenter);
	}
	/*! \fn ~VisualizationMono_Sensor_URG_Vars()
		\brief The destructor of VisualizationMono_Sensor_URG_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_URG_Vars() 
	{
        delete beams;
	}
public:
	//*******************Please add variables below*******************
    QLabel *beams;
    QPainter painter;
    double startangle;
    double endtangle;
    double resolution;
};

/*! @}*/ 

#endif
