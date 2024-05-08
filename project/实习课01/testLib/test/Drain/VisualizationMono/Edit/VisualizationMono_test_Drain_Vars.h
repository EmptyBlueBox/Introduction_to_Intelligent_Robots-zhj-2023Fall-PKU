//You need to modify this file.

#ifndef VISUALIZATIONMONO_TEST_DRAIN_VARS_H
#define VISUALIZATIONMONO_TEST_DRAIN_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_test_Drain_Vars VisualizationMono_test_Drain_Vars
	\ingroup VisualizationMono_test_Drain
	\brief VisualizationMono_test_Drain_Vars defines the Vars in VisualizationMono_test_Drain.
*/

/*! \addtogroup VisualizationMono_test_Drain_Vars
	@{
*/

/*! \file VisualizationMono_test_Drain_Vars.h
	 Defines the Vars of VisualizationMono_test_Drain
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_test_Drain_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_test_Drain_Vars 
	\brief The Vars of VisualizationMono_test_Drain.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_test_Drain_Vars 
{
public:
	/*! \fn VisualizationMono_test_Drain_Vars()
		\brief The constructor of VisualizationMono_test_Drain_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_test_Drain_Vars() 
	{
        map = new QLabel;
        map->setText("Closed");
        initial = true;
	}
	/*! \fn ~VisualizationMono_test_Drain_Vars()
		\brief The destructor of VisualizationMono_test_Drain_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_test_Drain_Vars() 
	{
        delete map;
	}
public:
	//*******************Please add variables below*******************
    int x, y;
    bool initial;
    QLabel *map;
    cv::Mat cvMap;
    cv::Mat cvMap2Show;
    cv::Mat imgCar;
    cv::Mat mask;
    const QString directions[5] = {"Up", "Down", "Left", "Right", "Stop"};

    static QImage Mat2QImage(const cv::Mat mat)
    {
        const uchar *qImageBuffer = (const uchar*)mat.data;
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }

    static QPixmap Mat2QPixmap(const cv::Mat mat)
    {
        return QPixmap::fromImage(Mat2QImage(mat));
    }
};

/*! @}*/ 

#endif
