/*
 * Temperature_Meter.c
 *
 * Created: 24/05/2020 3:19:17 AM
 *  Author: M
 */ 


#include "ADC.h"
#include "LCD.h"

int main(void)
{
	uint16_t temp;
	ADC_init();
	LCD_init();
    while(1)
    {
        temp=ADC_read();
		temp=temp * 0.48828125;	//to get value in celisius as ( 10mv --> 1 C , 5v --> 1024)
		LCD_write_command(0x1);
		LCD_write_num(temp);
		LCD_write_string(" C");
		_delay_ms(200);
    }
}