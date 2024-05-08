//You need to modify this file.

#ifndef VISUALIZATIONMONO_TEST_DRAIN_PARAMSDATA_H
#define VISUALIZATIONMONO_TEST_DRAIN_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_test_Drain_ParamsData VisualizationMono_test_Drain_ParamsData
	\ingroup VisualizationMono_test_Drain
	\brief VisualizationMono_test_Drain_ParamsData defines the ParamsData in VisualizationMono_test_Drain.
*/

/*! \addtogroup VisualizationMono_test_Drain_ParamsData
	@{
*/

/*! \file VisualizationMono_test_Drain_ParamsData.h
	 Defines the ParamsData of VisualizationMono_test_Drain
*/

//*******************Please add other headers below*******************
#include <opencv2/opencv.hpp>

//1 input data header(s) refered

//Defines Params ProcessorMono_test_Processor_Params and Input Data ProcessorMono_test_Processor_Data
#include<testLib/test/Processor/ProcessorMono/Edit/ProcessorMono_test_Processor_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_test_Drain_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 1, Params_Type = ProcessorMono_test_Processor_Params, Data_Type = ProcessorMono_test_Processor_Data
*/
#define VisualizationMono_test_Drain_INPUTPORTSSIZE QList<int>()<<1

//The Params is defined as below
/*! \class VisualizationMono_test_Drain_Params 
	\brief The Params of VisualizationMono_test_Drain.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_test_Drain_Params 
{
public:
	/*! \fn VisualizationMono_test_Drain_Params()
		\brief The constructor of VisualizationMono_test_Drain_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_test_Drain_Params() 
	{
        width = 640;
        height = 480;
	}
	/*! \fn ~VisualizationMono_test_Drain_Params()
		\brief The destructor of VisualizationMono_test_Drain_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_test_Drain_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int width, height;
};

//There is no Output Data.

/*! \def VisualizationMono_test_Drain_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_test_Drain_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
