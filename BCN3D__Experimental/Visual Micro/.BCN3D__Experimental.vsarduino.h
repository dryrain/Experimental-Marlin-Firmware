/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Mega 2560 or Mega ADK, Platform=avr, Package=arduino
*/

#define __AVR_ATmega2560__
#define ARDUINO 101
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
#define __cplusplus
extern "C" void __cxa_pure_virtual() {;}


#include "C:\Program Files\Arduino\hardware\arduino\variants\mega\pins_arduino.h" 
#include "C:\Program Files\Arduino\hardware\arduino\cores\arduino\arduino.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\BCN3D__Experimental.ino"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\Configuration.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\ConfigurationStore.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\ConfigurationStore.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\Configuration_adv.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\DOGMbitmaps.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\Hysteresis2.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\Hysteresis2.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\LiquidCrystalRus.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\LiquidCrystalRus.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\Marlin.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\MarlinSerial.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\MarlinSerial.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\Marlin_main.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\Sd2Card.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\Sd2Card.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\Sd2PinMap.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\SdBaseFile.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\SdBaseFile.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\SdFatConfig.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\SdFatStructs.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\SdFatUtil.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\SdFatUtil.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\SdFile.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\SdFile.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\SdInfo.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\SdVolume.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\SdVolume.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\Servo.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\Servo.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\cardreader.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\cardreader.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\dogm_font_data_marlin.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\dogm_lcd_implementation.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\fastio.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\language.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\motion_control.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\motion_control.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\pins.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\planner.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\planner.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\speed_lookuptable.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\stepper.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\stepper.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\temperature.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\temperature.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\thermistortables.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\ultralcd.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\ultralcd.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\ultralcd_implementation_hitachi_HD44780.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\ultralcd_st7920_u8glib_rrd.h"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\watchdog.cpp"
#include "C:\Users\reprap\Documents\GitHub\Experimental-Marlin-Firmware\BCN3D__Experimental\watchdog.h"
