//You need to modify this file.

#ifndef VISUALIZATIONMONO_PROCESSOR_LINE_VARS_H
#define VISUALIZATIONMONO_PROCESSOR_LINE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_Line_Vars VisualizationMono_Processor_Line_Vars
	\ingroup VisualizationMono_Processor_Line
	\brief VisualizationMono_Processor_Line_Vars defines the Vars in VisualizationMono_Processor_Line.
*/

/*! \addtogroup VisualizationMono_Processor_Line_Vars
	@{
*/

/*! \file VisualizationMono_Processor_Line_Vars.h
	 Defines the Vars of VisualizationMono_Processor_Line
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Processor_Line_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Processor_Line_Vars 
	\brief The Vars of VisualizationMono_Processor_Line.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Processor_Line_Vars 
{
public:
	/*! \fn VisualizationMono_Processor_Line_Vars()
		\brief The constructor of VisualizationMono_Processor_Line_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Processor_Line_Vars() 
	{
        ob = new QLabel();
        ob->setAlignment(Qt::AlignCenter);
	}
	/*! \fn ~VisualizationMono_Processor_Line_Vars()
		\brief The destructor of VisualizationMono_Processor_Line_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Processor_Line_Vars() 
	{
        delete ob;
	}
public:
	//*******************Please add variables below*******************
    QLabel *ob;
};

/*! @}*/ 

#endif
