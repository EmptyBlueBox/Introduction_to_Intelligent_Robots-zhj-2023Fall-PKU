//You need to modify this file.

#ifndef VISUALIZATIONMULTI_SHOW_LOCATIONANDMAP_VARS_H
#define VISUALIZATIONMULTI_SHOW_LOCATIONANDMAP_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Show_LocationAndMap_Vars VisualizationMulti_Show_LocationAndMap_Vars
	\ingroup VisualizationMulti_Show_LocationAndMap
	\brief VisualizationMulti_Show_LocationAndMap_Vars defines the Vars in VisualizationMulti_Show_LocationAndMap.
*/

/*! \addtogroup VisualizationMulti_Show_LocationAndMap_Vars
	@{
*/

/*! \file VisualizationMulti_Show_LocationAndMap_Vars.h
	 Defines the Vars of VisualizationMulti_Show_LocationAndMap
*/

//*******************Please add other headers below*******************


#include "VisualizationMulti_Show_LocationAndMap_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMulti_Show_LocationAndMap_Vars 
	\brief The Vars of VisualizationMulti_Show_LocationAndMap.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_Show_LocationAndMap_Vars 
{
public:
	/*! \fn VisualizationMulti_Show_LocationAndMap_Vars()
		\brief The constructor of VisualizationMulti_Show_LocationAndMap_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_Show_LocationAndMap_Vars() 
	{
        mapview = new QLabel();
        mapview->setAlignment(Qt::AlignCenter);
        laserview = new QLabel();
        laserview->setAlignment(Qt::AlignCenter);
	}
	/*! \fn ~VisualizationMulti_Show_LocationAndMap_Vars()
		\brief The destructor of VisualizationMulti_Show_LocationAndMap_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_Show_LocationAndMap_Vars() 
	{
        if(mapview->parent() == NULL)
        {
            delete mapview;
        }
        if(laserview->parent() == NULL)
        {
            delete laserview;
        }
	}
public:
	//*******************Please add variables below*******************
    QLabel *mapview;
    QLabel *laserview;
    //累计地图
    cv::Mat accumap;
    //实时显示的地图
    cv::Mat premap;
    bool init;
    int lastX;
    int lastY;
};

/*! @}*/ 

#endif
