//s_add new sensor driver here
//export funtions
UINT32 MT9P017SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);
UINT32 MT9P017MIPISensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);
UINT32 OV5647SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);
UINT32 GC0329_YUV_SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);
UINT32 GT2005_YUV_SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);

//! Add Sensor Init function here
//! Note:
//! 1. Add by the resolution from ""large to small"", due to large sensor 
//!    will be possible to be main sensor. 
//!    This can avoid I2C error during searching sensor. 
//! 2. This file should be the same as mediatek\custom\common\hal\imgsensor\src\sensorlist.cpp 
ACDK_KD_SENSOR_INIT_FUNCTION_STRUCT kdSensorList[MAX_NUM_OF_SUPPORT_SENSOR+1] =
{
#if defined(OV5647_RAW)
	{OV5647_SENSOR_ID, SENSOR_DRVNAME_OV5647_RAW, OV5647SensorInit}, 
#endif
#if defined(MT9P017_RAW)
	{MT9P017_SENSOR_ID, SENSOR_DRVNAME_MT9P017_RAW,MT9P017SensorInit},
#endif
#if defined(MT9P017_MIPI_RAW)
	{MT9P017MIPI_SENSOR_ID, SENSOR_DRVNAME_MT9P017_MIPI_RAW,MT9P017MIPISensorInit},
#endif
#if defined(GC0329_YUV)
	{GC0329_SENSOR_ID, SENSOR_DRVNAME_GC0329_YUV, GC0329_YUV_SensorInit},
#endif
#if defined(GT2005_YUV)
	{GT2005_SENSOR_ID, SENSOR_DRVNAME_GT2005_YUV, GT2005_YUV_SensorInit},
#endif
/*  ADD sensor driver before this line */
	{0,{0},NULL}, //end of list
};
//e_add new sensor driver here


