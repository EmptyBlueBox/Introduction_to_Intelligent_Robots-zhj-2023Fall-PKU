//You need to modify this file.

#ifndef STORAGEMONO_SENSOR_URG_VARS_H
#define STORAGEMONO_SENSOR_URG_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup StorageMono_Sensor_URG_Vars StorageMono_Sensor_URG_Vars
	\ingroup StorageMono_Sensor_URG
	\brief StorageMono_Sensor_URG_Vars defines the Vars in StorageMono_Sensor_URG.
*/

/*! \addtogroup StorageMono_Sensor_URG_Vars
	@{
*/

/*! \file StorageMono_Sensor_URG_Vars.h
	 Defines the Vars of StorageMono_Sensor_URG
*/

//*******************Please add other headers below*******************


#include "StorageMono_Sensor_URG_ParamsData.h"

//The Vars is defined as below
/*! \class StorageMono_Sensor_URG_Vars 
	\brief The Vars of StorageMono_Sensor_URG.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT StorageMono_Sensor_URG_Vars 
{
public:
	/*! \fn StorageMono_Sensor_URG_Vars()
		\brief The constructor of StorageMono_Sensor_URG_Vars. [required]
		\details ****Please add details below****

	*/
	StorageMono_Sensor_URG_Vars() 
	{
		
	}
	/*! \fn ~StorageMono_Sensor_URG_Vars()
		\brief The destructor of StorageMono_Sensor_URG_Vars. [required]
		\details *****Please add details below*****

	*/
	~StorageMono_Sensor_URG_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QFile file;
    bool writehead;
};

/*! @}*/ 

#endif
