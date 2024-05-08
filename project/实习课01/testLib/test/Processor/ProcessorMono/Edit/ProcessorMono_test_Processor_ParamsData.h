//You need to modify this file.

#ifndef PROCESSORMONO_TEST_PROCESSOR_PARAMSDATA_H
#define PROCESSORMONO_TEST_PROCESSOR_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_test_Processor_ParamsData ProcessorMono_test_Processor_ParamsData
	\ingroup ProcessorMono_test_Processor
	\brief ProcessorMono_test_Processor_ParamsData defines the ParamsData in ProcessorMono_test_Processor.
*/

/*! \addtogroup ProcessorMono_test_Processor_ParamsData
	@{
*/

/*! \file ProcessorMono_test_Processor_ParamsData.h
	 Defines the ParamsData of ProcessorMono_test_Processor
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorTimer_test_Source_Params and Input Data SensorTimer_test_Source_Data
#include<testLib/test/Source/SensorTimer/Edit/SensorTimer_test_Source_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMono_test_Processor_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SensorTimer_test_Source_Params, Data_Type = SensorTimer_test_Source_Data
*/
#define ProcessorMono_test_Processor_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class ProcessorMono_test_Processor_Params 
	\brief The Params of ProcessorMono_test_Processor.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_test_Processor_Params 
{
public:
	/*! \fn ProcessorMono_test_Processor_Params()
		\brief The constructor of ProcessorMono_test_Processor_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_test_Processor_Params() 
	{
        width = 640;
        height = 480;
        startx = 320;
        starty = 240;
        step = 10;
	}
	/*! \fn ~ProcessorMono_test_Processor_Params()
		\brief The destructor of ProcessorMono_test_Processor_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_test_Processor_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int width, height;
    int startx, starty;
    int step;
};

//The Output Data is defined as below
/*! \class ProcessorMono_test_Processor_Data 
	\brief The Data of ProcessorMono_test_Processor.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_test_Processor_Data 
{
public:
	/*! \fn ProcessorMono_test_Processor_Data()
		\brief The constructor of ProcessorMono_test_Processor_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_test_Processor_Data() 
    {

	}
	/*! \fn ~ProcessorMono_test_Processor_Data()
		\brief The destructor of ProcessorMono_test_Processor_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_test_Processor_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    enum Direction {UP, DOWN, LEFT, RIGHT, STOP};
    Direction direction;
    int x, y;
};

/*! \def ProcessorMono_test_Processor_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMono_test_Processor_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
