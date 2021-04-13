/*
 * Canais_ADC.c
 *
 * Created: 09/04/2021 21:31:54
 * Author : lucas
 */ 

#include <avr/io.h>

static inline void delay(uint8_t t);
static inline void teste(uint8_t sample);

int main(void)
{
    uint16_t sample;
	DDRD = 0xFF;
	ADMUX |= ((0<<REFS1) | (1<<REFS0) | (1<<ADLAR));
	ADCSRA |= ((1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0));
    while(1){
		ADCSRA |= ((1<<ADEN) | (1<<ADSC));
		while(ADIF==0);
		ADCSRA |= ((0<<ADIF) | (0<<ADEN));
		sample = ADCH;
		teste(sample);
		delay(100);
		PORTD = 0x00;
    }
}
static inline void teste(uint8_t sample){
	PORTD |= ((int)(sample/128)<<PORTD7);
	if(sample >= 128){
		sample %= 128;
	}
	PORTD |= ((int)(sample/64)<<PORTD6);
	if(sample >= 64){
		sample %= 64;
	}
	PORTD |= ((int)(sample/32)<<PORTD5);
	if(sample >= 32){
		sample %= 32;
	}
	PORTD |= ((int)(sample/16)<<PORTD4);
	if(sample >= 16){
		sample %= 16;
	}
	PORTD |= ((int)(sample/8)<<PORTD3);
	if(sample >= 8){
		sample %= 8;
	}
	PORTD |= ((int)(sample/4)<<PORTD2);
	if(sample >= 4){
		sample %= 4;
	}
	PORTD |= ((int)(sample/2)<<PORTD1);
	if(sample >= 2){
		sample %= 2;
	}
	PORTD |= ((int)(sample)<<PORTD0);
}
static inline void delay(uint8_t t){
	for (uint8_t i = 0; i < t; i++){
		GPIOR0 = t;
		for(uint8_t j = 0; j < 204; j++){
			GPIOR0--;
		}
	}
}
