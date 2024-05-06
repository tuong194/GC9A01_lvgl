//#ifndef _LCD_2IN8_H_
//#define _LCD_2IN8_H_
//
//#include "tl_common.h"
//#include "proj/mcu/watchdog_i.h"
//#include "vendor/common/user_config.h"
//#include "drivers.h"
//#include "proj_lib/ble/blt_config.h"
//#include "proj_lib/ble/ll/ll.h"
//#include "proj_lib/sig_mesh/app_mesh.h"
//
//#define RST_Pin  GPIO_PA1
//#define func  AS_GPIO
//#define DC_Pin  GPIO_PA3
//
//
//#define LCD2IN8_HEIGHT 240
//#define LCD2IN8_WIDTH 320
//
//#define HORIZONTAL 0 //ngang
//#define VERTICAL   1 //doc
//
//typedef struct{
//	u16 WIDTH;
//	u16 HEIGHT;
//	u16 SCAN_DIR;
//}LCD_2IN8_ATTRIBUTES;
//
//#define SPI_CLOCK 12000000
//
//
//#define WHITE 0xFFFF
//#define BLACK 0x0000
//#define RED   0xF800
//#define GREEN 0x07E0
//#define BLUE  0x001F
//
//void SPI_Config(void);
//void LCD_SendCmd(u8 cmd);
//void LCD_SendData8bit(u8 data);
//void LCD_SendData16bit(u16 data);
//void LCD_Init();
//void LCD_setAttribute(u8 scan_dir);
//void LCD_setWindow(u16 xStart, u16 yStart, u16 xEnd, u16 yEnd);
//void LCD_Clear(u16 color);
//void LCD_PutChar(u16 x,u16 y, u8 value);
//void LCD_PutStr(u16 x,u16 y, u8 *str);
//void LCD_FillRetangle(u16 xStart, u16 yStart, u16 width, u16 height, u16 color);
//#endif
