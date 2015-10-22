################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../lnk_msp430fr5739.cmd 

CFG_SRCS += \
../main.cfg 

C_SRCS += \
../adc_proxy.c \
../main.c \
../sensor_proxy.c 

OBJS += \
./adc_proxy.obj \
./main.obj \
./sensor_proxy.obj 

C_DEPS += \
./adc_proxy.pp \
./main.pp \
./sensor_proxy.pp 

GEN_MISC_DIRS += \
./configPkg/ 

GEN_CMDS += \
./configPkg/linker.cmd 

GEN_OPTS += \
./configPkg/compiler.opt 

GEN_FILES += \
./configPkg/linker.cmd \
./configPkg/compiler.opt 

GEN_FILES__QUOTED += \
"configPkg\linker.cmd" \
"configPkg\compiler.opt" 

GEN_MISC_DIRS__QUOTED += \
"configPkg\" 

C_DEPS__QUOTED += \
"adc_proxy.pp" \
"main.pp" \
"sensor_proxy.pp" 

OBJS__QUOTED += \
"adc_proxy.obj" \
"main.obj" \
"sensor_proxy.obj" 

C_SRCS__QUOTED += \
"../adc_proxy.c" \
"../main.c" \
"../sensor_proxy.c" 

GEN_CMDS__FLAG += \
-l"./configPkg/linker.cmd" 

GEN_OPTS__FLAG += \
--cmd_file="./configPkg/compiler.opt" 


