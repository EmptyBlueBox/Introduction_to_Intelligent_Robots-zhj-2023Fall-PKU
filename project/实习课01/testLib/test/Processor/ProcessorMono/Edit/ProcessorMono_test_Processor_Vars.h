//You need to modify this file.

#ifndef PROCESSORMONO_TEST_PROCESSOR_VARS_H
#define PROCESSORMONO_TEST_PROCESSOR_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_test_Processor_Vars ProcessorMono_test_Processor_Vars
	\ingroup ProcessorMono_test_Processor
	\brief ProcessorMono_test_Processor_Vars defines the Vars in ProcessorMono_test_Processor.
*/

/*! \addtogroup ProcessorMono_test_Processor_Vars
	@{
*/

/*! \file ProcessorMono_test_Processor_Vars.h
	 Defines the Vars of ProcessorMono_test_Processor
*/

//*******************Please add other headers below*******************


#include "ProcessorMono_test_Processor_ParamsData.h"

//The Vars is defined as below
/*! \class ProcessorMono_test_Processor_Vars 
	\brief The Vars of ProcessorMono_test_Processor.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_test_Processor_Vars 
{
public:
	/*! \fn ProcessorMono_test_Processor_Vars()
		\brief The constructor of ProcessorMono_test_Processor_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_test_Processor_Vars() 
	{

	}
	/*! \fn ~ProcessorMono_test_Processor_Vars()
		\brief The destructor of ProcessorMono_test_Processor_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_test_Processor_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    const int dx[5] = {0, 0, -1, 1, 0};
    const int dy[5] = {-1, 1, 0, 0, 0};
    int currentx, currenty;
    int index;
    int tot;
};

/*! @}*/ 

#endif
