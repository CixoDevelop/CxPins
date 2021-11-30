# CxPins lib

## About it:
 * This library is part of the CxFramework for AVR.
 * It can be used without the rest of the framework.
 * It provides convenient holders for the pins of the microcontroller, so that they can
   be passed as, for example, a function parameter
 * Author: Cixo

## Instaling it (without CxFramework)
 * On linux run
 ```bash
 chmod +x InstallIt.sh
 sudo ./InstallIt.sh
 ```

## How to use it?

### Simple example
If the easiest way to learn from examples is, you will find one in Sample.cpp. This code
shows how to use a library to rewrite the negated value from output X to pin Y.

### Including it
```cpp
#include <CxFramework/CxPins.h> // CxPins library
#include <avr/io.h>	// standard library required for AVR operation
```

### Create handles
```cpp
CxPin my_name(DDRx, y);	// creates a handle to pin y number in the DDRx register
```

### Using handles (functions)
```cpp
/* pin mode seting */
my_name.setMode(IN);	// set pin mode to input
my_name.setMode(OUT);	// set pin mode to output

/* pin value seting */
my_name.setValue(LOW);	// if in output mode then set value to GND, if in input mode then off pullup
my_name.setValue(HIGH);	// if in output mode then set value to VCC, if in input mode then on pullup

/* pin value geting */
my_name.getValue();	// return LOW or HIGH
if (my_name.getValue() == HIGH) ;	// for example
```

### Using operators
```cpp
/* pin mode seting */
my_name = IN;	// set pin mode to input
my_name = OUT;	// set pin mode to output

/* pin value seting */
my_name = LOW;	// if in output mode then set value to GND, if in input mode then off pullup
my_name = HIGH;	// if in output mode then set value to VCC, if in input mode then on pullup

/* pin value get */
my_name;	// return LOW or HIGH
if(my_name == HIGH) ;	//for example
if(my_name != HIGH) ;	//for example

/* negative value */
!my_name;	// return negative value

/* rewrite pin value */
my_name = other_pin;	// same value
my_name = !other_pin;	// negative pin value
```
