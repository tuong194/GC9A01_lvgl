################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/tests/src/test_cases/_test_template.c \
../vendor/lvgl/tests/src/test_cases/test_align_flex.c \
../vendor/lvgl/tests/src/test_cases/test_anim.c \
../vendor/lvgl/tests/src/test_cases/test_anim_timeline.c \
../vendor/lvgl/tests/src/test_cases/test_area.c \
../vendor/lvgl/tests/src/test_cases/test_array.c \
../vendor/lvgl/tests/src/test_cases/test_bindings.c \
../vendor/lvgl/tests/src/test_cases/test_config.c \
../vendor/lvgl/tests/src/test_cases/test_demo_stress.c \
../vendor/lvgl/tests/src/test_cases/test_demo_widgets.c \
../vendor/lvgl/tests/src/test_cases/test_draw_buf_stride.c \
../vendor/lvgl/tests/src/test_cases/test_event.c \
../vendor/lvgl/tests/src/test_cases/test_font_loader.c \
../vendor/lvgl/tests/src/test_cases/test_fs.c \
../vendor/lvgl/tests/src/test_cases/test_grid.c \
../vendor/lvgl/tests/src/test_cases/test_group.c \
../vendor/lvgl/tests/src/test_cases/test_margin_align.c \
../vendor/lvgl/tests/src/test_cases/test_margin_flex.c \
../vendor/lvgl/tests/src/test_cases/test_margin_grid.c \
../vendor/lvgl/tests/src/test_cases/test_math.c \
../vendor/lvgl/tests/src/test_cases/test_mem.c \
../vendor/lvgl/tests/src/test_cases/test_observer.c \
../vendor/lvgl/tests/src/test_cases/test_profiler.c \
../vendor/lvgl/tests/src/test_cases/test_screen_load.c \
../vendor/lvgl/tests/src/test_cases/test_snapshot.c \
../vendor/lvgl/tests/src/test_cases/test_style.c \
../vendor/lvgl/tests/src/test_cases/test_txt.c 

OBJS += \
./vendor/lvgl/tests/src/test_cases/_test_template.o \
./vendor/lvgl/tests/src/test_cases/test_align_flex.o \
./vendor/lvgl/tests/src/test_cases/test_anim.o \
./vendor/lvgl/tests/src/test_cases/test_anim_timeline.o \
./vendor/lvgl/tests/src/test_cases/test_area.o \
./vendor/lvgl/tests/src/test_cases/test_array.o \
./vendor/lvgl/tests/src/test_cases/test_bindings.o \
./vendor/lvgl/tests/src/test_cases/test_config.o \
./vendor/lvgl/tests/src/test_cases/test_demo_stress.o \
./vendor/lvgl/tests/src/test_cases/test_demo_widgets.o \
./vendor/lvgl/tests/src/test_cases/test_draw_buf_stride.o \
./vendor/lvgl/tests/src/test_cases/test_event.o \
./vendor/lvgl/tests/src/test_cases/test_font_loader.o \
./vendor/lvgl/tests/src/test_cases/test_fs.o \
./vendor/lvgl/tests/src/test_cases/test_grid.o \
./vendor/lvgl/tests/src/test_cases/test_group.o \
./vendor/lvgl/tests/src/test_cases/test_margin_align.o \
./vendor/lvgl/tests/src/test_cases/test_margin_flex.o \
./vendor/lvgl/tests/src/test_cases/test_margin_grid.o \
./vendor/lvgl/tests/src/test_cases/test_math.o \
./vendor/lvgl/tests/src/test_cases/test_mem.o \
./vendor/lvgl/tests/src/test_cases/test_observer.o \
./vendor/lvgl/tests/src/test_cases/test_profiler.o \
./vendor/lvgl/tests/src/test_cases/test_screen_load.o \
./vendor/lvgl/tests/src/test_cases/test_snapshot.o \
./vendor/lvgl/tests/src/test_cases/test_style.o \
./vendor/lvgl/tests/src/test_cases/test_txt.o 

C_DEPS += \
./vendor/lvgl/tests/src/test_cases/_test_template.d \
./vendor/lvgl/tests/src/test_cases/test_align_flex.d \
./vendor/lvgl/tests/src/test_cases/test_anim.d \
./vendor/lvgl/tests/src/test_cases/test_anim_timeline.d \
./vendor/lvgl/tests/src/test_cases/test_area.d \
./vendor/lvgl/tests/src/test_cases/test_array.d \
./vendor/lvgl/tests/src/test_cases/test_bindings.d \
./vendor/lvgl/tests/src/test_cases/test_config.d \
./vendor/lvgl/tests/src/test_cases/test_demo_stress.d \
./vendor/lvgl/tests/src/test_cases/test_demo_widgets.d \
./vendor/lvgl/tests/src/test_cases/test_draw_buf_stride.d \
./vendor/lvgl/tests/src/test_cases/test_event.d \
./vendor/lvgl/tests/src/test_cases/test_font_loader.d \
./vendor/lvgl/tests/src/test_cases/test_fs.d \
./vendor/lvgl/tests/src/test_cases/test_grid.d \
./vendor/lvgl/tests/src/test_cases/test_group.d \
./vendor/lvgl/tests/src/test_cases/test_margin_align.d \
./vendor/lvgl/tests/src/test_cases/test_margin_flex.d \
./vendor/lvgl/tests/src/test_cases/test_margin_grid.d \
./vendor/lvgl/tests/src/test_cases/test_math.d \
./vendor/lvgl/tests/src/test_cases/test_mem.d \
./vendor/lvgl/tests/src/test_cases/test_observer.d \
./vendor/lvgl/tests/src/test_cases/test_profiler.d \
./vendor/lvgl/tests/src/test_cases/test_screen_load.d \
./vendor/lvgl/tests/src/test_cases/test_snapshot.d \
./vendor/lvgl/tests/src/test_cases/test_style.d \
./vendor/lvgl/tests/src/test_cases/test_txt.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/tests/src/test_cases/%.o: ../vendor/lvgl/tests/src/test_cases/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


