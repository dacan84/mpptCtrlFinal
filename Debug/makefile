################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3

ORDERED_OBJS += \
"./adc_proxy.obj" \
"./ann_proxy.obj" \
"./main.obj" \
"./mppt_ctrl.obj" \
"./sensor_proxy.obj" \
"./temperature_tmp112/TMP112_I2C_temperature_sensor.obj" \
"./light_MAX44009/light_sensor_MAX44009.obj" \
"./ann_PV/ANN_implementation.obj" \
"./adc/averaged_adc.obj" \
"../lnk_msp430fr5739.cmd" \
$(GEN_CMDS__FLAG) \
-l"libmath.a" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include temperature_tmp112/subdir_vars.mk
-include light_MAX44009/subdir_vars.mk
-include ann_PV/subdir_vars.mk
-include adc/subdir_vars.mk
-include subdir_rules.mk
-include temperature_tmp112/subdir_rules.mk
-include light_MAX44009/subdir_rules.mk
-include ann_PV/subdir_rules.mk
-include adc/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
mpptCtrlFinal.out \

EXE_OUTPUTS__QUOTED += \
"mpptCtrlFinal.out" \

BIN_OUTPUTS += \
mpptCtrlFinal.hex \

BIN_OUTPUTS__QUOTED += \
"mpptCtrlFinal.hex" \


# All Target
all: mpptCtrlFinal.out

# Tool invocations
mpptCtrlFinal.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/cl430" -vmspx --abi=eabi --opt_for_speed=5 --use_hw_mpy=F5 --advice:power=all -g --float_operations_allowed=all --define=__MSP430FR5739__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal -z -m"mpptCtrlFinal.map" --heap_size=160 --stack_size=160 --cinit_hold_wdt=on -i"C:/ti/ccsv6/ccs_base/msp430/include" -i"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/lib" -i"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/include" -i"C:/ti/ccsv6/ccs_base/msp430/lib/5xx_6xx_FRxx" --reread_libs --warn_sections --display_error_number --diag_wrap=off --xml_link_info="mpptCtrlFinal_linkInfo.xml" --use_hw_mpy=F5 --rom_model -o "mpptCtrlFinal.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

mpptCtrlFinal.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP430 Hex Utility'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.3/bin/hex430" --memwidth=8 --romwidth=8 -o "mpptCtrlFinal.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_OPTS__QUOTED)$(GEN_CMDS__QUOTED)
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-$(RM) "adc_proxy.pp" "ann_proxy.pp" "main.pp" "mppt_ctrl.pp" "sensor_proxy.pp" "temperature_tmp112\TMP112_I2C_temperature_sensor.pp" "light_MAX44009\light_sensor_MAX44009.pp" "ann_PV\ANN_implementation.pp" "adc\averaged_adc.pp" 
	-$(RM) "adc_proxy.obj" "ann_proxy.obj" "main.obj" "mppt_ctrl.obj" "sensor_proxy.obj" "temperature_tmp112\TMP112_I2C_temperature_sensor.obj" "light_MAX44009\light_sensor_MAX44009.obj" "ann_PV\ANN_implementation.obj" "adc\averaged_adc.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

