################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/src/draw/lv_draw.c \
../vendor/lvgl/src/draw/lv_draw_arc.c \
../vendor/lvgl/src/draw/lv_draw_buf.c \
../vendor/lvgl/src/draw/lv_draw_image.c \
../vendor/lvgl/src/draw/lv_draw_label.c \
../vendor/lvgl/src/draw/lv_draw_line.c \
../vendor/lvgl/src/draw/lv_draw_mask.c \
../vendor/lvgl/src/draw/lv_draw_rect.c \
../vendor/lvgl/src/draw/lv_draw_triangle.c \
../vendor/lvgl/src/draw/lv_draw_vector.c \
../vendor/lvgl/src/draw/lv_image_decoder.c 

OBJS += \
./vendor/lvgl/src/draw/lv_draw.o \
./vendor/lvgl/src/draw/lv_draw_arc.o \
./vendor/lvgl/src/draw/lv_draw_buf.o \
./vendor/lvgl/src/draw/lv_draw_image.o \
./vendor/lvgl/src/draw/lv_draw_label.o \
./vendor/lvgl/src/draw/lv_draw_line.o \
./vendor/lvgl/src/draw/lv_draw_mask.o \
./vendor/lvgl/src/draw/lv_draw_rect.o \
./vendor/lvgl/src/draw/lv_draw_triangle.o \
./vendor/lvgl/src/draw/lv_draw_vector.o \
./vendor/lvgl/src/draw/lv_image_decoder.o 

C_DEPS += \
./vendor/lvgl/src/draw/lv_draw.d \
./vendor/lvgl/src/draw/lv_draw_arc.d \
./vendor/lvgl/src/draw/lv_draw_buf.d \
./vendor/lvgl/src/draw/lv_draw_image.d \
./vendor/lvgl/src/draw/lv_draw_label.d \
./vendor/lvgl/src/draw/lv_draw_line.d \
./vendor/lvgl/src/draw/lv_draw_mask.d \
./vendor/lvgl/src/draw/lv_draw_rect.d \
./vendor/lvgl/src/draw/lv_draw_triangle.d \
./vendor/lvgl/src/draw/lv_draw_vector.d \
./vendor/lvgl/src/draw/lv_image_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/src/draw/%.o: ../vendor/lvgl/src/draw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

