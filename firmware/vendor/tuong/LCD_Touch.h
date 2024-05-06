#ifndef _LCD_TOUCH_H_
#define _LCD_TOUCH_H_

#include "tl_common.h"
#include "proj/mcu/watchdog_i.h"
#include "vendor/common/user_config.h"
#include "drivers.h"
#include "proj_lib/ble/blt_config.h"
#include "proj_lib/ble/ll/ll.h"
#include "proj_lib/sig_mesh/app_mesh.h"


#define CS_TOUCH_ON (gpio_write(PSPI_CSN_PC0,1))
#define CS_TOUCH_OFF (gpio_write(PSPI_CSN_PC0,0))

#define T_IRQ_Pin  GPIO_PB1
#define func  AS_GPIO

#define SPI_CLOCK 12000000

#define COMMAND_READ_X    0XD0
#define COMMAND_READ_Y    0X90

// calibrate

#ifndef OK
#define OK 0
#define NOT_OK -1
#endif

#define INT_32 long

typedef struct Point{
	INT_32 x,
		   y;
}POINT_T;

typedef struct Matrix{
	INT_32 An,
		   Bn,
		   Cn,
		   Dn,
		   En,
		   Fn,
		   Divider;
}MATRIX;

void SPI_ConfigTouch(void);
uint8_t TouchisTouched(void);
//int setCalibrationMatrix( POINT_T * displayPtr,
//						  POINT_T * screenPtr,
//                          MATRIX * matrixPtr);
bool TouchGetPoint(u16* x, u16* y);


#endif
