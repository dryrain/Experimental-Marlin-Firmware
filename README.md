Experimental-Marlin-Firmware
============================

Experiments and implementations of new features for the RepRapBCN 3D printer

Done:
--
* Selectable Hysteresis correction via LCD menu, by [dryrain]

Working on:
--
* Pause with Z axis elevation, by [agusCim]
* Touching display implementation, by [dryrain]



##Reminder:
#####Printer versions and configuration.h changes

* For BCN3D+ version x00
```cpp
#define X_MAX_POS 242.5
#define Y_MAX_POS 210
```

* For BCN3D+ version x01
```cpp
#define X_MAX_POS 252
#define Y_MAX_POS 200
```

####Sound disabled




[dryrain]:https://github.com/dryrain
[agusCim]:https://github.com/agusCim
