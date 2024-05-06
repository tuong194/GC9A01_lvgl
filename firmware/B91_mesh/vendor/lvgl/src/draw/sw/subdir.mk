################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/src/draw/sw/lv_draw_sw.c \
../vendor/lvgl/src/draw/sw/lv_draw_sw_arc.c \
../vendor/lvgl/src/draw/sw/lv_draw_sw_border.c \
../vendor/lvgl/src/draw/sw/lv_draw_sw_box_shadow.c \
../vendor/lvgl/src/draw/sw/lv_draw_sw_fill.c \
../vendor/lvgl/src/draw/sw/lv_draw_sw_gradient.c \
../vendor/lvgl/src/draw/sw/lv_draw_sw_img.c \
../vendor/lvgl/src/draw/sw/lv_draw_sw_letter.c \
../vendor/lvgl/src/draw/sw/lv_draw_sw_line.c \
../vendor/lvgl/src/draw/sw/lv_draw_sw_mask.c \
../vendor/lvgl/src/draw/sw/lv_draw_sw_mask_rect.c \
../vendor/lvgl/src/draw/sw/lv_draw_sw_transform.c \
../vendor/lvgl/src/draw/sw/lv_draw_sw_triangle.c \
../vendor/lvgl/src/draw/sw/lv_draw_sw_vector.c 

OBJS += \
./vendor/lvgl/src/draw/sw/lv_draw_sw.o \
./vendor/lvgl/src/draw/sw/lv_draw_sw_arc.o \
./vendor/lvgl/src/draw/sw/lv_draw_sw_border.o \
./vendor/lvgl/src/draw/sw/lv_draw_sw_box_shadow.o \
./vendor/lvgl/src/draw/sw/lv_draw_sw_fill.o \
./vendor/lvgl/src/draw/sw/lv_draw_sw_gradient.o \
./vendor/lvgl/src/draw/sw/lv_draw_sw_img.o \
./vendor/lvgl/src/draw/sw/lv_draw_sw_letter.o \
./vendor/lvgl/src/draw/sw/lv_draw_sw_line.o \
./vendor/lvgl/src/draw/sw/lv_draw_sw_mask.o \
./vendor/lvgl/src/draw/sw/lv_draw_sw_mask_rect.o \
./vendor/lvgl/src/draw/sw/lv_draw_sw_transform.o \
./vendor/lvgl/src/draw/sw/lv_draw_sw_triangle.o \
./vendor/lvgl/src/draw/sw/lv_draw_sw_vector.o 

C_DEPS += \
./vendor/lvgl/src/draw/sw/lv_draw_sw.d \
./vendor/lvgl/src/draw/sw/lv_draw_sw_arc.d \
./vendor/lvgl/src/draw/sw/lv_draw_sw_border.d \
./vendor/lvgl/src/draw/sw/lv_draw_sw_box_shadow.d \
./vendor/lvgl/src/draw/sw/lv_draw_sw_fill.d \
./vendor/lvgl/src/draw/sw/lv_draw_sw_gradient.d \
./vendor/lvgl/src/draw/sw/lv_draw_sw_img.d \
./vendor/lvgl/src/draw/sw/lv_draw_sw_letter.d \
./vendor/lvgl/src/draw/sw/lv_draw_sw_line.d \
./vendor/lvgl/src/draw/sw/lv_draw_sw_mask.d \
./vendor/lvgl/src/draw/sw/lv_draw_sw_mask_rect.d \
./vendor/lvgl/src/draw/sw/lv_draw_sw_transform.d \
./vendor/lvgl/src/draw/sw/lv_draw_sw_triangle.d \
./vendor/lvgl/src/draw/sw/lv_draw_sw_vector.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/src/draw/sw/%.o: ../vendor/lvgl/src/draw/sw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


