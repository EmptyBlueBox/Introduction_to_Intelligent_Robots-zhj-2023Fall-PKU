//You need to modify this file.

#ifndef PROCESSORMULTI_ALGOR_MAPPING_VARS_H
#define PROCESSORMULTI_ALGOR_MAPPING_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algor_Mapping_Vars ProcessorMulti_Algor_Mapping_Vars
	\ingroup ProcessorMulti_Algor_Mapping
	\brief ProcessorMulti_Algor_Mapping_Vars defines the Vars in ProcessorMulti_Algor_Mapping.
*/

/*! \addtogroup ProcessorMulti_Algor_Mapping_Vars
	@{
*/

/*! \file ProcessorMulti_Algor_Mapping_Vars.h
	 Defines the Vars of ProcessorMulti_Algor_Mapping
*/

//*******************Please add other headers below*******************


#include "ProcessorMulti_Algor_Mapping_ParamsData.h"

//The Vars is defined as below
/*! \class ProcessorMulti_Algor_Mapping_Vars 
	\brief The Vars of ProcessorMulti_Algor_Mapping.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algor_Mapping_Vars 
{
public:
	/*! \fn ProcessorMulti_Algor_Mapping_Vars()
		\brief The constructor of ProcessorMulti_Algor_Mapping_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algor_Mapping_Vars() 
	{
        mapWidth = 640;
        mapHeight = 600;

        if(mapWidth > 0 && mapHeight > 0)
        {
            map = new double * [mapHeight];
            for(int i = 0 ; i < mapHeight ; i ++)
            {
                map[i] = new double [mapWidth];
            }
        }
        else
        {
            map = NULL;
        }
	}
	/*! \fn ~ProcessorMulti_Algor_Mapping_Vars()
		\brief The destructor of ProcessorMulti_Algor_Mapping_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algor_Mapping_Vars() 
	{
        if(map != NULL)
        {
            for(int i = 0 ; i < mapHeight ; i ++)
            {
                delete map[i];
            }
            delete [] map;
            map = NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    double ** map;
    int mapHeight;
    int mapWidth;
};

/*! @}*/ 

#endif
