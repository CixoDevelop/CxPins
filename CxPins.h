/*
 * This file is part of the CxFramework
 *
 * It contains the CxPin class, which allows you to 
 * manipulate a single pin of a microcontroller
 * It also contains two enumeration types used 
 * to record the pin's operating mode and pin state
 * 
 * For information on how to use this class in general, see CxPins/ReadMe.md
 *
 * Author: Cixo
 */


/* if uint8_t type is not defined, define it */
#ifndef uint8_t
	typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
#endif

/* include this file only once */
#pragma once

/* pin mode enum */
enum CxPinMode{
	OUT = true,
	IN = false
};

/* pin value enum */
enum CxPinValue{
	HIGH = true,
	LOW = false
};

/* CxPin class, main class in this file */
class CxPin{
	public:

		inline void setMode(CxPinMode new_mode){
			/*
			 * This function is used to 
			 * change operating mode
			 * of the pin
			 */
			 
			if(new_mode)
				*pin_ddr |= pin_mask;
			else
				*pin_ddr &= ~pin_mask;
		}
		
		inline void setValue(CxPinValue new_value){
			/*
			 * This function is used to 
			 * change value of the pin
			 */
			 
			if(new_value)
				*(pin_ddr + 1) |= pin_mask;
			else
				*(pin_ddr + 1) &= ~pin_mask;
		}
		
		inline CxPinValue getValue(){
			/*
			 * This function is used to 
			 * get value of the pin 
			 * is userful if pin is 
			 * in IN mode
			 */
			 
			return CxPinValue( *(pin_ddr - 1) & pin_mask );
		}
		
		CxPin(volatile uint8_t *pin_ddr_init, uint8_t pin_number) : 
			pin_ddr(pin_ddr_init)
		{
			/*
			 * This function is constructor, get
			 * DDR register of pin, and number 
			 * of this pin in IO register
			 *
			 * for example, for 3 attiny 13 pin
			 * it is DDRB, 4
			 */
			
			pin_mask = 1 << pin_number;
		}
		
		/* operators */
		bool operator ==(CxPinValue value_to_compare){
			return getValue() == value_to_compare;
		}
		
		bool operator !=(CxPinValue value_to_compare){
			return getValue() != value_to_compare;
		}
		
		CxPinValue operator !(){
			return CxPinValue( !getValue() );
		}
		
		CxPin &operator =(CxPin &pin_to_rewrite){
			setValue(pin_to_rewrite.getValue());
			return *this;
		}
		
		CxPin &operator =(CxPinValue value_to_set){
			setValue(value_to_set);
			return *this;
		}
		
		CxPin &operator =(CxPinMode mode_to_set){
			setMode(mode_to_set);
			return *this;
		}
				
	private:
	
		uint8_t pin_mask;			/* mask of pin in register */
		volatile uint8_t *pin_ddr;	/* DDRx address of pin */
};
