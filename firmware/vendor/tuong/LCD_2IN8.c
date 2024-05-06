//#include "LCD_2IN8.h"
//#include "font.h"
//
//
//void SPI_Config2IN8(void){
//	// config Pin
//	gpio_set_func(RST_Pin,func);
//	gpio_output_en(RST_Pin);
//	gpio_write(RST_Pin,1);
//	gpio_set_func(DC_Pin,func);
//	gpio_output_en(DC_Pin);
//	//config spi
//	pspi_pin_config_t config_pin;
//	config_pin.pspi_clk_pin = PSPI_CLK_PC5;
//	config_pin.pspi_csn_pin = PSPI_CSN_PC4;
//	config_pin.pspi_miso_io1_pin = PSPI_MISO_IO1_PC6;
//	config_pin.pspi_mosi_io0_pin = PSPI_MOSI_IO0_PC7;
//	pspi_set_pin(&config_pin);
//	spi_master_init(PSPI_MODULE,sys_clk.hclk*1000000/(2*SPI_CLOCK)-1,SPI_MODE0);//f=12 MHz
//	spi_master_config(PSPI_MODULE,SPI_3LINE);
//
//}
//
//
//
//void LCD_SendCmd(u8 cmd){
//	gpio_write(DC_Pin,0);
//	spi_master_write(PSPI_MODULE,&cmd,1);
//}
//void LCD_SendData8bit(u8 data){
//	gpio_write(DC_Pin,1);
//	spi_master_write(PSPI_MODULE,&data,1);
//}
//void LCD_SendData16bit(u16 data){
//	u8 datax[5];
//	datax[0]=data>>8;
//	datax[1]=data;
//	gpio_write(DC_Pin,1);
//	spi_master_write(PSPI_MODULE,datax,2);
//
//}
//void LCD_Init2IN8(){
//	LCD_SendCmd(0x01);  // software reset
//	sleep_ms(100);
//
//	LCD_SendCmd(0x28);  // display OFF
//
//	/* power control*/
//	LCD_SendCmd(0xC0); // power control 1
//	LCD_SendData8bit(0x26); // GVDD = 4.75V
//	LCD_SendCmd(0xC1); // power control 2
//	LCD_SendData8bit(0x11);
//
//	/* VCOM */
//	LCD_SendCmd(0xC5);
//	LCD_SendData8bit(0x35); // set VCOMH = 4.025V
//	LCD_SendData8bit(0x3E); // set VCOML
//	LCD_SendCmd(0xC7);
//	LCD_SendData8bit(0xBE);
//
//	/*Memory access control*/
//	LCD_SendCmd(0x36); // memory
//	LCD_SendData8bit(0x40);// MX =1, BGR =0
//	LCD_SendCmd(0x3A); // pixel format
//	LCD_SendData8bit(0x55); // 16bit/ pixel
//
//	/*Frame rate control*/
//	LCD_SendCmd(0xB1);
//	LCD_SendData8bit(0x00);
//	LCD_SendData8bit(0x1F); // frame rate = 61Hz
//
//	LCD_SendCmd(0x2A); // column address
//	LCD_SendData8bit(0x00);
//	LCD_SendData8bit(0x00);
//	LCD_SendData8bit(0x00);
//	LCD_SendData8bit(0xEF); // start 0x0000 -> end 0x00EF (239)
//	LCD_SendCmd(0x2B); // page address
//	LCD_SendData8bit(0x00);
//	LCD_SendData8bit(0x00);
//	LCD_SendData8bit(0x01);
//	LCD_SendData8bit(0x3F); //0x0000 -> 0x013F (319)
//
//	LCD_SendCmd(0x34); // Tearing Effect Line OFF
//
//	LCD_SendCmd(0xB7); // Entry Mode Set
//	LCD_SendData8bit(0x07); // gas disable, normal display
//
//	LCD_SendCmd(0xB6); //Display func Control
//	LCD_SendData8bit(0x0A);
//	LCD_SendData8bit(0x82);
//	LCD_SendData8bit(0x07);
//	LCD_SendData8bit(0x00);
//
//	LCD_SendCmd(0x11); // Sleep out
//	sleep_ms(100);
//	wd_clear();
//	LCD_SendCmd(0x29); // display ON;
//	sleep_ms(5);
//	wd_clear();
//	LCD_SendCmd(0x2C); // memory write
//	sleep_ms(5);
//}
//
//LCD_2IN8_ATTRIBUTES LCD_2INCH8;
//void LCD_setAttribute(u8 scan_dir){
//
//	LCD_2INCH8.SCAN_DIR = scan_dir;
//	u8 memoryaccess = 0x00;
//
//	if(scan_dir == HORIZONTAL){
//		LCD_2INCH8.HEIGHT = LCD2IN8_HEIGHT;
//		LCD_2INCH8.WIDTH = LCD2IN8_WIDTH;
//		memoryaccess = 0xC0;
//	}else{
//		LCD_2INCH8.WIDTH = LCD2IN8_HEIGHT;
//		LCD_2INCH8.HEIGHT = LCD2IN8_WIDTH;
//		memoryaccess = 0x60;
//	}
//	LCD_SendCmd(0x36); //truy cap memory
//	LCD_SendData8bit(memoryaccess);
//}
//
//void LCD_setWindow(u16 xStart, u16 yStart, u16 xEnd, u16 yEnd){
//	LCD_SendCmd(0x2A);
//	LCD_SendData8bit(xStart >>8);
//	LCD_SendData8bit(xStart);
//	LCD_SendData8bit(xEnd>>8);
//	LCD_SendData8bit(xEnd);
//
//	LCD_SendCmd(0x2B);
//	LCD_SendData8bit(yStart>>8);
//	LCD_SendData8bit(yStart);
//	LCD_SendData8bit(yEnd>>8);
//	LCD_SendData8bit(yEnd);
//
//	LCD_SendCmd(0x2C);
//}
//
//void LCD_Clear(u16 color){
//	uint32_t i;
//	LCD_setWindow(0,0,239,319);
//	uint32_t n= 240*320;
//	u8 data[5];
//	data[0]= color>>8;
//	data[1] = color;
//	gpio_write(DC_Pin,1);
//	for( i=0;i<n;i++){
//			spi_master_write(PSPI_MODULE,data,2);
//			wd_clear();
//	}
//}
//
//void LCD_PutChar(u16 x,u16 y, u8 value){
//	u8 i,j,k;
//	u8 *p = charr24;
//	LCD_setWindow(x,y,x+23,y+23);
//	p+= (value-32)*24*3;
//	for(j=0;j<24;j++){  // nen trang chu do   //duyet hang
//		k=0;
//		for(i=0;i<24;i++){
//			if((*p & (1<<(7-k))) != 0){
//				LCD_SendData16bit(RED);
//			}else{
//				LCD_SendData16bit(WHITE);
//			}
//			k++;
//			if(k == 8){
//				k=0;
//				p++;
//			}
//		}
//	}
//}
//// show string
//void LCD_PutStr(u16 x,u16 y, u8 *str){
//	while(*str != '\0'){
//		LCD_PutChar(x,y,*str);
//		x+=23;
//		str++;
//	}
//}
//
//void LCD_FillRetangle(u16 xStart, u16 yStart, u16 width, u16 height, u16 color){
//	LCD_setWindow(xStart, yStart,width -1 , height -1);
//	for(uint32_t i =0; i< width*height; i++){
//		LCD_SendData16bit(color);
//	}
//}
