#ifndef _KD_IMGSENSOR_H
#define _KD_IMGSENSOR_H

#include <linux/ioctl.h>

#ifndef ASSERT
	#define ASSERT(expr)        BUG_ON(!(expr))
#endif

#define IMGSENSORMAGIC 'i'
//IOCTRL(inode * ,file * ,cmd ,arg )
//S means "set through a ptr"
//T means "tell by a arg value"
//G means "get by a ptr"
//Q means "get by return a value"
//X means "switch G and S atomically"
//H means "switch T and Q atomically"

/*******************************************************************************
*
********************************************************************************/

/*******************************************************************************
*
********************************************************************************/

#define KDIMGSENSORIOC_T_OPEN						_IO(IMGSENSORMAGIC,0)										//sensorOpen
#define KDIMGSENSORIOC_X_GETINFO					_IOWR(IMGSENSORMAGIC,5,ACDK_SENSOR_GETINFO_STRUCT)			//sensorGetInfo
#define KDIMGSENSORIOC_X_GETRESOLUTION				_IOWR(IMGSENSORMAGIC,10,ACDK_SENSOR_RESOLUTION_INFO_STRUCT)	//sensorGetResolution
#define KDIMGSENSORIOC_X_FEATURECONCTROL			_IOWR(IMGSENSORMAGIC,15,ACDK_SENSOR_FEATURECONTROL_STRUCT)	//sensorFeatureControl
#define KDIMGSENSORIOC_X_CONTROL					_IOWR(IMGSENSORMAGIC,20,ACDK_SENSOR_CONTROL_STRUCT)			//sensorControl
#define KDIMGSENSORIOC_T_CLOSE						_IO(IMGSENSORMAGIC,25)										//sensorClose
#define KDIMGSENSORIOC_T_CHECK_IS_ALIVE				_IO(IMGSENSORMAGIC, 30)										//sensorSearch 
#define KDIMGSENSORIOC_X_SET_DRIVER					_IOWR(IMGSENSORMAGIC,35,SENSOR_DRIVER_INDEX_STRUCT)			//set sensor driver
#define KDIMGSENSORIOC_X_GET_SOCKET_POS				_IOWR(IMGSENSORMAGIC,40,u32)								//get socket postion
#define KDIMGSENSORIOC_X_SET_SHUTTER_GAIN_WAIT_DONE	_IOWR(IMGSENSORMAGIC,50,u32)								//Set Shutter Gain Wait Done


/*******************************************************************************
*
********************************************************************************/
/* SENSOR CHIP VERSION */
#define OV5647_SENSOR_ID		0x5647
#define MT9P017_SENSOR_ID		0x4800
#define MT9P017MIPI_SENSOR_ID	0x4800
#define GC0329_SENSOR_ID		0x00C0
#define GT2005_SENSOR_ID            0x5138

/* CAMERA DRIVER NAME */
#define CAMERA_HW_DEVNAME					"kd_camera_hw"

/* SENSOR DEVICE DRIVER NAME */
#define SENSOR_DRVNAME_MT9P017_RAW			"mt9p017"
#define SENSOR_DRVNAME_MT9P017_MIPI_RAW               "mt9p017mipi"
#define SENSOR_DRVNAME_GC0329_YUV			"gc0329yuv"
#define SENSOR_DRVNAME_GT2005_YUV    	         "gt2005yuv"
#define SENSOR_DRVNAME_OV5647_RAW			"ov5647"
/*******************************************************************************
*
********************************************************************************/

void KD_IMGSENSOR_PROFILE_INIT(void); 
void KD_IMGSENSOR_PROFILE(char *tag); 

#define mDELAY(ms)		mdelay(ms) 
#define uDELAY(us)		udelay(us) 
#endif //_KD_IMGSENSOR_H


