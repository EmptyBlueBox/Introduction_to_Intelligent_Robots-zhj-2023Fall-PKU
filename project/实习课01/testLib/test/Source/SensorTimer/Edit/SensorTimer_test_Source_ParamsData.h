//You need to modify this file.

#ifndef SENSORTIMER_TEST_SOURCE_PARAMSDATA_H
#define SENSORTIMER_TEST_SOURCE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorTimer_test_Source_ParamsData SensorTimer_test_Source_ParamsData
	\ingroup SensorTimer_test_Source
	\brief SensorTimer_test_Source_ParamsData defines the ParamsData in SensorTimer_test_Source.
*/

/*! \addtogroup SensorTimer_test_Source_ParamsData
	@{
*/

/*! \file SensorTimer_test_Source_ParamsData.h
	 Defines the ParamsData of SensorTimer_test_Source
*/

//*******************Please add other headers below*******************
#include <cstdlib>
#include <ctime>

//There is no input data headers.

/*! \def SensorTimer_test_Source_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorTimer_test_Source_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorTimer_test_Source_Params 
	\brief The Params of SensorTimer_test_Source.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_test_Source_Params 
{
public:
	/*! \fn SensorTimer_test_Source_Params()
		\brief The constructor of SensorTimer_test_Source_Params. [required]
		\details ****Please add details below****

	*/
	SensorTimer_test_Source_Params() 
	{

	}
	/*! \fn ~SensorTimer_test_Source_Params()
		\brief The destructor of SensorTimer_test_Source_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_test_Source_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class SensorTimer_test_Source_Data 
	\brief The Data of SensorTimer_test_Source.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorTimer_test_Source_Data 
{
public:
	/*! \fn SensorTimer_test_Source_Data()
		\brief The constructor of SensorTimer_test_Source_Data. [required]
		\details ****Please add details below****

	*/
	SensorTimer_test_Source_Data() 
	{
		
	}
	/*! \fn ~SensorTimer_test_Source_Data()
		\brief The destructor of SensorTimer_test_Source_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorTimer_test_Source_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int keyPoint[50][2];
    int tot;
};

/*! \def SensorTimer_test_Source_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorTimer_test_Source_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
