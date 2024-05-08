//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_XTION_VARS_H
#define VISUALIZATIONMONO_SENSOR_XTION_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_xtion_Vars VisualizationMono_Sensor_xtion_Vars
	\ingroup VisualizationMono_Sensor_xtion
	\brief VisualizationMono_Sensor_xtion_Vars defines the Vars in VisualizationMono_Sensor_xtion.
*/

/*! \addtogroup VisualizationMono_Sensor_xtion_Vars
	@{
*/

/*! \file VisualizationMono_Sensor_xtion_Vars.h
	 Defines the Vars of VisualizationMono_Sensor_xtion
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Sensor_xtion_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Sensor_xtion_Vars 
	\brief The Vars of VisualizationMono_Sensor_xtion.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_xtion_Vars 
{
public:
	/*! \fn VisualizationMono_Sensor_xtion_Vars()
		\brief The constructor of VisualizationMono_Sensor_xtion_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_xtion_Vars() 
	{
        color = new QLabel();
        depth = new QLabel();
        color->setAlignment(Qt::AlignCenter);
        depth->setAlignment(Qt::AlignCenter);
	}
	/*! \fn ~VisualizationMono_Sensor_xtion_Vars()
		\brief The destructor of VisualizationMono_Sensor_xtion_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_xtion_Vars() 
	{
        delete color;
        delete depth;
	}
public:
	//*******************Please add variables below*******************
    QLabel *color, *depth;
};

/*! @}*/ 

#endif
