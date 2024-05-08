//You need to modify this file.

#ifndef SENSORTIMER_TEST_SOURCE_VARS_H
#define SENSORTIMER_TEST_SOURCE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_test_Source_Vars SensorTimer_test_Source_Vars
	\ingroup SensorTimer_test_Source
	\brief SensorTimer_test_Source_Vars defines the Vars in SensorTimer_test_Source.
*/

/*! \addtogroup SensorTimer_test_Source_Vars
	@{
*/

/*! \file SensorTimer_test_Source_Vars.h
	 Defines the Vars of SensorTimer_test_Source
*/

//*******************Please add other headers below*******************


#include "SensorTimer_test_Source_ParamsData.h"

//The Vars is defined as below
/*! \class SensorTimer_test_Source_Vars 
	\brief The Vars of SensorTimer_test_Source.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_test_Source_Vars 
{
public:
	/*! \fn SensorTimer_test_Source_Vars()
		\brief The constructor of SensorTimer_test_Source_Vars. [required]
		\details ****Please add details below****

	*/
	SensorTimer_test_Source_Vars() 
    {
        tot = 0;
	}
	/*! \fn ~SensorTimer_test_Source_Vars()
		\brief The destructor of SensorTimer_test_Source_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_test_Source_Vars() 
	{
		
	}
public:
    //*******************Please add variables below*******************
    int tot;
    int keyPoint[50][2];

};

/*! @}*/ 

#endif
