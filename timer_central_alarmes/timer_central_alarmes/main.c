/*
 * timer_central_alarmes.c
 *
 * Created: 12/04/2021 12:36:46
 * Author : lucas
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

void setupClock(){
	TCCR1B |= (1<<CS12);
	OCR1A = 31250;
	TCCR1B |= (1<<WGM12);
	TIMSK1 |= (1<<OCIE1A);
}

int main(void){
	
	//cli();
	DDRD = 0xFF;
	PORTD = 0;
	setupClock();
	sei();

	
	while(1) {
		
	}
}

ISR(TIMER1_COMPA_vect){
	PORTD += 1;
}
