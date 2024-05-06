################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.c \
../vendor/lvgl/src/draw/nxp/pxp/lv_draw_pxp.c \
../vendor/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.c \
../vendor/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.c \
../vendor/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.c \
../vendor/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.c \
../vendor/lvgl/src/draw/nxp/pxp/lv_pxp_osa.c \
../vendor/lvgl/src/draw/nxp/pxp/lv_pxp_utils.c 

OBJS += \
./vendor/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.o \
./vendor/lvgl/src/draw/nxp/pxp/lv_draw_pxp.o \
./vendor/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.o \
./vendor/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.o \
./vendor/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.o \
./vendor/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.o \
./vendor/lvgl/src/draw/nxp/pxp/lv_pxp_osa.o \
./vendor/lvgl/src/draw/nxp/pxp/lv_pxp_utils.o 

C_DEPS += \
./vendor/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.d \
./vendor/lvgl/src/draw/nxp/pxp/lv_draw_pxp.d \
./vendor/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.d \
./vendor/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.d \
./vendor/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.d \
./vendor/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.d \
./vendor/lvgl/src/draw/nxp/pxp/lv_pxp_osa.d \
./vendor/lvgl/src/draw/nxp/pxp/lv_pxp_utils.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/src/draw/nxp/pxp/%.o: ../vendor/lvgl/src/draw/nxp/pxp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


