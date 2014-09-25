################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../Visual\ Micro/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../cardreader.cpp \
../ConfigurationStore.cpp \
../Hysteresis2.cpp \
../LiquidCrystalRus.cpp \
../MarlinSerial.cpp \
../Marlin_main.cpp \
../motion_control.cpp \
../planner.cpp \
../Sd2Card.cpp \
../SdBaseFile.cpp \
../SdFatUtil.cpp \
../SdFile.cpp \
../SdVolume.cpp \
../Servo.cpp \
../stepper.cpp \
../temperature.cpp \
../ultralcd.cpp \
../watchdog.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
cardreader.o \
ConfigurationStore.o \
Hysteresis2.o \
LiquidCrystalRus.o \
MarlinSerial.o \
Marlin_main.o \
motion_control.o \
planner.o \
Sd2Card.o \
SdBaseFile.o \
SdFatUtil.o \
SdFile.o \
SdVolume.o \
Servo.o \
stepper.o \
temperature.o \
ultralcd.o \
watchdog.o

OBJS_AS_ARGS +=  \
cardreader.o \
ConfigurationStore.o \
Hysteresis2.o \
LiquidCrystalRus.o \
MarlinSerial.o \
Marlin_main.o \
motion_control.o \
planner.o \
Sd2Card.o \
SdBaseFile.o \
SdFatUtil.o \
SdFile.o \
SdVolume.o \
Servo.o \
stepper.o \
temperature.o \
ultralcd.o \
watchdog.o

C_DEPS +=  \
cardreader.d \
ConfigurationStore.d \
Hysteresis2.d \
LiquidCrystalRus.d \
MarlinSerial.d \
Marlin_main.d \
motion_control.d \
planner.d \
Sd2Card.d \
SdBaseFile.d \
SdFatUtil.d \
SdFile.d \
SdVolume.d \
Servo.d \
stepper.d \
temperature.d \
ultralcd.d \
watchdog.d

C_DEPS_AS_ARGS +=  \
cardreader.d \
ConfigurationStore.d \
Hysteresis2.d \
LiquidCrystalRus.d \
MarlinSerial.d \
Marlin_main.d \
motion_control.d \
planner.d \
Sd2Card.d \
SdBaseFile.d \
SdFatUtil.d \
SdFile.d \
SdVolume.d \
Servo.d \
stepper.d \
temperature.d \
ultralcd.d \
watchdog.d

OUTPUT_FILE_PATH +=BCN3D__Experimental.elf

OUTPUT_FILE_PATH_AS_ARGS +=BCN3D__Experimental.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

# AVR32/GNU C Compiler





































./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -D__AVR_ATmega2560__ -DARDUINO=101 -DARDUINO_MAIN -DF_CPU=16000000L -D__AVR__ -D__cplusplus  -I"C:\Program Files\Arduino\hardware\arduino\cores\arduino" -I"C:\Program Files\Arduino\hardware\arduino\variants\mega" -I"C:\Program Files\Arduino\libraries\Wire" -I"C:\Program Files\Arduino\libraries\Wire\utility" -I"C:\Users\reprap\Documents\libraries\U8glib" -I"C:\Users\reprap\Documents\libraries\U8glib\utility" -I"C:\Program Files\Arduino\libraries\LiquidCrystal" -I"C:\Program Files\Arduino\libraries\LiquidCrystal\utility" -I"C:\Program Files\Arduino\libraries\SPI" -I"C:\Program Files\Arduino\libraries\SPI\utility" -I"C:\Program Files\Arduino\libraries" -I"C:\Program Files\Arduino\hardware\arduino\libraries" -I"C:\Program Files\Visual Micro\Visual Micro for Arduino\Micro Platforms\default\debuggers" -I"C:\Users\reprap\Documents\libraries" -I"c:\program files\arduino\hardware\tools\avr\avr\include" -I"c:\program files\arduino\hardware\tools\avr\avr\include\avr" -I"c:\program files\arduino\hardware\tools\avr\avr" -I"c:\program files\arduino\hardware\tools\avr\lib\gcc\avr\4.3.2\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega2560 -c -include=arduino.h -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 4.8.1
	$(QUOTE)C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="BCN3D__Experimental.map" -Wl,--start-group  -Wl,--end-group -Wl,--gc-sections -mrelax -mmcu=atmega2560  
	@echo Finished building target: $@
	"C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "BCN3D__Experimental.elf" "BCN3D__Experimental.hex"
	"C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "BCN3D__Experimental.elf" "BCN3D__Experimental.eep" || exit 0
	"C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "BCN3D__Experimental.elf" > "BCN3D__Experimental.lss"
	"C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "BCN3D__Experimental.elf" "BCN3D__Experimental.srec"
	"C:\Program Files\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-size.exe" "BCN3D__Experimental.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "BCN3D__Experimental.elf" "BCN3D__Experimental.a" "BCN3D__Experimental.hex" "BCN3D__Experimental.lss" "BCN3D__Experimental.eep" "BCN3D__Experimental.map" "BCN3D__Experimental.srec" "BCN3D__Experimental.usersignatures"
	