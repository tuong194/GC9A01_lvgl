#include"LCD_Touch.h"

static MATRIX matrix;

void SPI_ConfigTouch(void){
	gpio_set_func(T_IRQ_Pin, func);
	gpio_input_en(T_IRQ_Pin);
	gpio_set_up_down_res(T_IRQ_Pin,GPIO_PIN_PULLUP_10K);

	pspi_pin_config_t config_pinTouch;
	config_pinTouch.pspi_clk_pin = PSPI_CLK_PB5;
	config_pinTouch.pspi_csn_pin = PSPI_CSN_PC0;
	config_pinTouch.pspi_miso_io1_pin = PSPI_MISO_IO1_PB6;
	config_pinTouch.pspi_mosi_io0_pin = PSPI_MOSI_IO0_PB7;
	pspi_set_pin(&config_pinTouch);
	spi_master_init(PSPI_MODULE,sys_clk.hclk*1000000/(2*SPI_CLOCK)-1,SPI_MODE0);//f=12 MHz
	spi_master_config(PSPI_MODULE,SPI_3LINE);
}
uint8_t TouchisTouched(void){
	uint8_t state;
	if(gpio_read(T_IRQ_Pin) != 0){
		state = 0;
	}else{
		state = 1;
	}
	return state ;
}

static uint8_t SPI_Transfer(uint8_t byte){
	 uint8_t result;
	// uint8_t dataRX, dataTX[2];
	 spi_master_write_read(PSPI_MODULE,&byte,1,&result,1);
	 return result;
 }


static bool getPointRaw(u16 *x, u16*y){
	 uint8_t i;
	 u16 xRaw, yRaw;
	 bool sorted;
	 u16 swap_value;
	 u8 touch_count;
	 u16 dataBuffer[2][10];
	 if(!TouchisTouched()) return false;

	 CS_TOUCH_ON;
	 touch_count = 0;
	 do{
		 SPI_Transfer(COMMAND_READ_X);
		 xRaw = (u16)SPI_Transfer(0)<<8;
		 xRaw |= (u16)SPI_Transfer(0);
		 xRaw >>= 3;

		 SPI_Transfer(COMMAND_READ_Y);
		 yRaw = (u16)SPI_Transfer(0)<<8;
		 yRaw |= (u16)SPI_Transfer(0);
		 yRaw >>= 3;

		 dataBuffer[0][touch_count] = xRaw;
		 dataBuffer[1][touch_count] = yRaw;
		 touch_count++;
	 }while(TouchisTouched() == 1 && touch_count<10);
	 CS_TOUCH_OFF;

	 if(touch_count != 10) return false;

	 do{
		 sorted = true;
		 for(i=0;i<touch_count-1; i++){
			 if(dataBuffer[0][i] > dataBuffer[0][i+1]){
				 //swap
				 swap_value = dataBuffer[0][i+1];
				 dataBuffer[0][i+1] = dataBuffer[0][i];
				 dataBuffer[0][i] = swap_value;
				 sorted = false;
			 }
		 }
	 }while(!sorted);

	 do{
		 sorted = true;
		 for(i=0; i<touch_count - 1; i++){
			 if(dataBuffer[1][i] > dataBuffer[1][i+1]){
				 swap_value = dataBuffer[1][1+i];
				 dataBuffer[1][1+i] = dataBuffer[1][i];
				 dataBuffer[1][i] = swap_value;
				 sorted = false;
			 }
		 }
	 }while(!sorted);

	 *x = (dataBuffer[0][4] + dataBuffer[0][5]) / 2;
	 *y = (dataBuffer[1][4] + dataBuffer[1][5]) / 2;
	 return true;
 }

int getDisplayPoint(POINT_T* displayPtr, POINT_T* screenPtr, MATRIX* matrixPtr){
	int retvalue = OK;
	if(matrixPtr -> Divider != 0){
		displayPtr -> x = ( matrixPtr->An * screenPtr->x + matrixPtr->Bn * screenPtr->y + matrixPtr->Cn ) / matrixPtr->Divider;
		displayPtr -> y = ( matrixPtr->Dn * screenPtr->x + matrixPtr->En * screenPtr->y + matrixPtr->Fn ) / matrixPtr->Divider;
	}else{
		retvalue = NOT_OK;
	}
	return retvalue;
}

int setCalibrationMatrix( POINT_T * displayPtr,
						  POINT_T * screenPtr,
                          MATRIX * matrixPtr)
{
    int  retValue = OK ;
    matrixPtr->Divider = ((screenPtr[0].x - screenPtr[2].x) * (screenPtr[1].y - screenPtr[2].y)) -
                         ((screenPtr[1].x - screenPtr[2].x) * (screenPtr[0].y - screenPtr[2].y)) ;

    if( matrixPtr->Divider == 0 )
    {
        retValue = NOT_OK ;
    }
    else
    {
        matrixPtr->An = ((displayPtr[0].x - displayPtr[2].x) * (screenPtr[1].y - screenPtr[2].y)) -
                        ((displayPtr[1].x - displayPtr[2].x) * (screenPtr[0].y - screenPtr[2].y)) ;

        matrixPtr->Bn = ((screenPtr[0].x - screenPtr[2].x) * (displayPtr[1].x - displayPtr[2].x)) -
                        ((displayPtr[0].x - displayPtr[2].x) * (screenPtr[1].x - screenPtr[2].x)) ;

        matrixPtr->Cn = (screenPtr[2].x * displayPtr[1].x - screenPtr[1].x * displayPtr[2].x) * screenPtr[0].y +
                        (screenPtr[0].x * displayPtr[2].x - screenPtr[2].x * displayPtr[0].x) * screenPtr[1].y +
                        (screenPtr[1].x * displayPtr[0].x - screenPtr[0].x * displayPtr[1].x) * screenPtr[2].y ;

        matrixPtr->Dn = ((displayPtr[0].y - displayPtr[2].y) * (screenPtr[1].y - screenPtr[2].y)) -
                        ((displayPtr[1].y - displayPtr[2].y) * (screenPtr[0].y - screenPtr[2].y)) ;

        matrixPtr->En = ((screenPtr[0].x - screenPtr[2].x) * (displayPtr[1].y - displayPtr[2].y)) -
                        ((displayPtr[0].y - displayPtr[2].y) * (screenPtr[1].x - screenPtr[2].x)) ;

        matrixPtr->Fn = (screenPtr[2].x * displayPtr[1].y - screenPtr[1].x * displayPtr[2].y) * screenPtr[0].y +
                        (screenPtr[0].x * displayPtr[2].y - screenPtr[2].x * displayPtr[0].y) * screenPtr[1].y +
                        (screenPtr[1].x * displayPtr[0].y - screenPtr[0].x * displayPtr[1].y) * screenPtr[2].y ;
    }

    return( retValue ) ;

}

bool TouchGetPoint(u16* x, u16* y){
	POINT_T raw_point;
	POINT_T display_point;
	u16 raw_x,raw_y;

	//(void)setCalibrationMatrix(&display_point,&raw_point,&matrix);

	// get raw
	if(getPointRaw(&raw_x, &raw_y) == false){
		return false;
	}
	raw_point.x = (INT_32)raw_x;
	raw_point.y = (INT_32)raw_y;

	(void) getDisplayPoint(&display_point,&raw_point,&matrix);
	if(display_point.x > 239) display_point.x=239;
	if(display_point.x < 0) display_point.x = 0;
	if(display_point.y < 0) display_point.y=0;
	if(display_point.y > 319) display_point.y=319;
	*x = (u16)display_point.x;
	*y = (u16)display_point.y;
	return true;
}


















