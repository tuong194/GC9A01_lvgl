

/*********************
 *      INCLUDES
 *********************/
#include "LCD_128.h"
#include "LCD_lvgl.h"



 #define MY_DISP_HOR_RES    240
 #define MY_DISP_VER_RES    240


static void disp_init(void);

static void disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);



void lv_port_disp_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();


    lv_display_t * disp = lv_display_create(MY_DISP_HOR_RES, MY_DISP_VER_RES);
    lv_display_set_flush_cb(disp, disp_flush);

    /* Example 1
     * One buffer for partial rendering*/
    static lv_color_t buf_1_1[MY_DISP_HOR_RES * 10];                          /*A buffer for 10 rows*/
    lv_display_set_buffers(disp, buf_1_1, NULL, sizeof(buf_1_1), LV_DISPLAY_RENDER_MODE_PARTIAL);

//    /* Example 2
//     * Two buffers for partial rendering
//     * In flush_cb DMA or similar hardware should be used to update the display in the background.*/
//    static lv_color_t buf_2_1[MY_DISP_HOR_RES * 10];
//    static lv_color_t buf_2_2[MY_DISP_HOR_RES * 10];
//    lv_display_set_buffers(disp, buf_2_1, buf_2_2, sizeof(buf_2_1), LV_DISPLAY_RENDER_MODE_PARTIAL);
//
//    /* Example 3
//     * Two buffers screen sized buffer for double buffering.
//     * Both LV_DISPLAY_RENDER_MODE_DIRECT and LV_DISPLAY_RENDER_MODE_FULL works, see their comments*/
//    static lv_color_t buf_3_1[MY_DISP_HOR_RES * MY_DISP_VER_RES];
//    static lv_color_t buf_3_2[MY_DISP_HOR_RES * MY_DISP_VER_RES];
//    lv_display_set_buffers(disp, buf_3_1, buf_3_2, sizeof(buf_3_1), LV_DISPLAY_RENDER_MODE_DIRECT);

}



/*Initialize your display and the required peripherals.*/
static void disp_init(void)
{
	LCD_RST();
	LCD_InitReg();
//	LCD_Init();
}

volatile bool disp_flush_enabled = true;


void disp_enable_update(void)
{
    disp_flush_enabled = true;
}

void disp_disable_update(void)
{
    disp_flush_enabled = false;
}


static void disp_flush(lv_display_t * disp_drv, const lv_area_t * area, uint8_t * px_map)
{
    if(disp_flush_enabled) {
        int32_t y;
        int32_t Width = area->x2 - area->x1 +1;
//        int32_t Height = area->y2 - area->y1 +1;
        LCD_setWindow(area->x1,area->y1,area->x2,area->y2);
        gpio_write(DC_Pin,1);
        for(y = area->y1; y <= area->y2; y++) {
			spi_master_write(PSPI_MODULE,px_map,2*Width);
			px_map+=2*Width;
			wd_clear();
        }
    }
    lv_display_flush_ready(disp_drv);
}

