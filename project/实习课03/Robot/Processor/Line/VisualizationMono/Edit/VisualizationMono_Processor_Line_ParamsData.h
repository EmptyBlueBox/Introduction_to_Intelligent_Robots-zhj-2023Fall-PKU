//You need to modify this file.

#ifndef VISUALIZATIONMONO_PROCESSOR_LINE_PARAMSDATA_H
#define VISUALIZATIONMONO_PROCESSOR_LINE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Processor_Line_ParamsData VisualizationMono_Processor_Line_ParamsData
	\ingroup VisualizationMono_Processor_Line
	\brief VisualizationMono_Processor_Line_ParamsData defines the ParamsData in VisualizationMono_Processor_Line.
*/

/*! \addtogroup VisualizationMono_Processor_Line_ParamsData
	@{
*/

/*! \file VisualizationMono_Processor_Line_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Processor_Line
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMulti_Processor_Line_Params and Input Data ProcessorMulti_Processor_Line_Data
#include<Robot/Processor/Line/ProcessorMulti/Edit/ProcessorMulti_Processor_Line_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Processor_Line_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 1, Params_Type = ProcessorMulti_Processor_Line_Params, Data_Type = ProcessorMulti_Processor_Line_Data
*/
#define VisualizationMono_Processor_Line_INPUTPORTSSIZE QList<int>()<<1

//The Params is defined as below
/*! \class VisualizationMono_Processor_Line_Params 
	\brief The Params of VisualizationMono_Processor_Line.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Processor_Line_Params 
{
public:
	/*! \fn VisualizationMono_Processor_Line_Params()
		\brief The constructor of VisualizationMono_Processor_Line_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Processor_Line_Params() 
	{
        scale = 1.0;
        width = 640;
        height = 480;
        offsetWidth = 320;
        offsetHeight = 240;
	}
	/*! \fn ~VisualizationMono_Processor_Line_Params()
		\brief The destructor of VisualizationMono_Processor_Line_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Processor_Line_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    double scale;
    int width, height;
    int offsetWidth, offsetHeight;
};

//There is no Output Data.

/*! \def VisualizationMono_Processor_Line_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Processor_Line_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
