################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/src/misc/lv_anim.c \
../vendor/lvgl/src/misc/lv_anim_timeline.c \
../vendor/lvgl/src/misc/lv_area.c \
../vendor/lvgl/src/misc/lv_array.c \
../vendor/lvgl/src/misc/lv_async.c \
../vendor/lvgl/src/misc/lv_bidi.c \
../vendor/lvgl/src/misc/lv_color.c \
../vendor/lvgl/src/misc/lv_color_op.c \
../vendor/lvgl/src/misc/lv_event.c \
../vendor/lvgl/src/misc/lv_fs.c \
../vendor/lvgl/src/misc/lv_ll.c \
../vendor/lvgl/src/misc/lv_log.c \
../vendor/lvgl/src/misc/lv_lru.c \
../vendor/lvgl/src/misc/lv_math.c \
../vendor/lvgl/src/misc/lv_palette.c \
../vendor/lvgl/src/misc/lv_profiler_builtin.c \
../vendor/lvgl/src/misc/lv_rb.c \
../vendor/lvgl/src/misc/lv_style.c \
../vendor/lvgl/src/misc/lv_style_gen.c \
../vendor/lvgl/src/misc/lv_templ.c \
../vendor/lvgl/src/misc/lv_text.c \
../vendor/lvgl/src/misc/lv_text_ap.c \
../vendor/lvgl/src/misc/lv_timer.c \
../vendor/lvgl/src/misc/lv_utils.c 

OBJS += \
./vendor/lvgl/src/misc/lv_anim.o \
./vendor/lvgl/src/misc/lv_anim_timeline.o \
./vendor/lvgl/src/misc/lv_area.o \
./vendor/lvgl/src/misc/lv_array.o \
./vendor/lvgl/src/misc/lv_async.o \
./vendor/lvgl/src/misc/lv_bidi.o \
./vendor/lvgl/src/misc/lv_color.o \
./vendor/lvgl/src/misc/lv_color_op.o \
./vendor/lvgl/src/misc/lv_event.o \
./vendor/lvgl/src/misc/lv_fs.o \
./vendor/lvgl/src/misc/lv_ll.o \
./vendor/lvgl/src/misc/lv_log.o \
./vendor/lvgl/src/misc/lv_lru.o \
./vendor/lvgl/src/misc/lv_math.o \
./vendor/lvgl/src/misc/lv_palette.o \
./vendor/lvgl/src/misc/lv_profiler_builtin.o \
./vendor/lvgl/src/misc/lv_rb.o \
./vendor/lvgl/src/misc/lv_style.o \
./vendor/lvgl/src/misc/lv_style_gen.o \
./vendor/lvgl/src/misc/lv_templ.o \
./vendor/lvgl/src/misc/lv_text.o \
./vendor/lvgl/src/misc/lv_text_ap.o \
./vendor/lvgl/src/misc/lv_timer.o \
./vendor/lvgl/src/misc/lv_utils.o 

C_DEPS += \
./vendor/lvgl/src/misc/lv_anim.d \
./vendor/lvgl/src/misc/lv_anim_timeline.d \
./vendor/lvgl/src/misc/lv_area.d \
./vendor/lvgl/src/misc/lv_array.d \
./vendor/lvgl/src/misc/lv_async.d \
./vendor/lvgl/src/misc/lv_bidi.d \
./vendor/lvgl/src/misc/lv_color.d \
./vendor/lvgl/src/misc/lv_color_op.d \
./vendor/lvgl/src/misc/lv_event.d \
./vendor/lvgl/src/misc/lv_fs.d \
./vendor/lvgl/src/misc/lv_ll.d \
./vendor/lvgl/src/misc/lv_log.d \
./vendor/lvgl/src/misc/lv_lru.d \
./vendor/lvgl/src/misc/lv_math.d \
./vendor/lvgl/src/misc/lv_palette.d \
./vendor/lvgl/src/misc/lv_profiler_builtin.d \
./vendor/lvgl/src/misc/lv_rb.d \
./vendor/lvgl/src/misc/lv_style.d \
./vendor/lvgl/src/misc/lv_style_gen.d \
./vendor/lvgl/src/misc/lv_templ.d \
./vendor/lvgl/src/misc/lv_text.d \
./vendor/lvgl/src/misc/lv_text_ap.d \
./vendor/lvgl/src/misc/lv_timer.d \
./vendor/lvgl/src/misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/src/misc/%.o: ../vendor/lvgl/src/misc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


