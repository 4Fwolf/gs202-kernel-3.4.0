#include <cutils/xlog.h>
#include <utils/Errors.h>
#include <fcntl.h>
#include <math.h>

#include "MediaHal.h"
//#include "msdk_sensor_exp.h"
#include "camera_custom_sensor.h"
#if defined(IMX073_MIPI_RAW)
#include "camera_calibration_eeprom.h"
#endif
#include "kd_imgsensor.h"
//#include "image_sensor.h"

//TODO:remove once build system ready
//#include "camera_custom_cfg.h"

//#include "src/lib/inc/MediaLog.h"

//#define LOG_TAG "SENSORLIST"
//MUINT32 MT9P012_getCalData(PGET_SENSOR_CALIBRATION_DATA_STRUCT pGetCalData);

#define LOGE(fmt, arg...)    XLOGE(fmt, ##arg)


#define YUV_INFO(_id, name, getCalData)\
    {_id, name, \
    NSFeature::YUVSensorInfo<_id>::GetInstance, \
    NSFeature::YUVSensorInfo<_id>::GetDefaultData, \
    getCalData \
    }
#define RAW_INFO(_id, name, getCalData)\
    {_id, name, \
    NSFeature::RAWSensorInfo<_id>::GetInstance, \
    NSFeature::RAWSensorInfo<_id>::GetDefaultData, \
    getCalData \
    }


//MSDK_SENSOR_INIT_FUNCTION_STRUCT SensorList[MAX_NUM_OF_SUPPORT_SENSOR] =
MSDK_SENSOR_INIT_FUNCTION_STRUCT SensorList[] =
{
#if defined(OV5647_RAW)
    RAW_INFO(OV5647_SENSOR_ID, SENSOR_DRVNAME_OV5647_RAW, NULL), 
#endif
#if defined(MT9P017_RAW)
    RAW_INFO(MT9P017_SENSOR_ID, SENSOR_DRVNAME_MT9P017_RAW, NULL), 
#endif
#if defined(MT9P017_MIPI_RAW)
    RAW_INFO(MT9P017MIPI_SENSOR_ID, SENSOR_DRVNAME_MT9P017_MIPI_RAW, NULL), 
#endif
#if defined(GC0329_YUV)
    YUV_INFO(GC0329_SENSOR_ID, SENSOR_DRVNAME_GC0329_YUV,NULL), 
#endif
#if defined(GT2005_YUV)
    YUV_INFO(GT2005_SENSOR_ID, SENSOR_DRVNAME_GT2005_YUV,NULL), 
#endif

/*  ADD sensor driver before this line */
    {0,{0},NULL, NULL, NULL}//end of list
};

UINT32 GetSensorInitFuncList(MSDK_SENSOR_INIT_FUNCTION_STRUCT **ppSensorList)
{
    if (NULL == ppSensorList) {
        LOGE("ERROR: NULL pSensorList\n");
        return MHAL_UNKNOWN_ERROR;
    }
    *ppSensorList = &SensorList[0];
	return MHAL_NO_ERROR;
} // GetSensorInitFuncList()






