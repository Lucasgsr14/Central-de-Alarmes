/*
 * LCD.c
 *
 * Created: 09/04/2021 18:35:54
 * Author : lucas
 */ 
#include <avr/io.h>

static inline void delay(uint8_t t);
static inline void simulaClock(uint8_t qntPulsos, uint8_t porta);
static inline void tremPulso(char funcao[], char palavra[], uint8_t posicao, uint8_t mode);
static inline void instrucaoLCD(char funcao[]);
static inline void enviaLetra(char letra);

int main(void)
{
	DDRC = 0x7F;
	DDRD = 0x01;
	PORTD = 0x00;
    while (1) 
    {
		PORTD = 0x01;
		delay(2); //t = 21 = 50us (Clk = 8MHz)
		PORTD = 0x00;
    }
}
/*
static inline void delay(uint8_t t, uint8_t p){
	for (uint8_t i = 0; i < p; i++){
		for(uint8_t j = 0; j < t; j++){
			GPIOR0--;
		}
	}
}
*/
static inline void delay(uint8_t t){
	for (uint8_t i = 0; i < t; i++){
		for(uint8_t j = 0; j < 21; j++){
			GPIOR0--;
		}
	}
}

static inline void simulaClock(uint8_t qntPulsos, uint8_t PORTBx){
	for(uint8_t = 0; i < qntPulsos; i++){
		PORTB |=  (1 << PORTBx);
		PORTB &= ~(1 << PORTBx);
	}
}

static inline void tremPulso(char funcao[], char palavra[], uint8_t posicao, uint8_t mode){
	PORTC = ((reg<<1)|(mode==1?(1<<5):(0<<5)));
	delay(1);
	PORTC |= (1<<6);
	delay(1);
	PORTC &= ~(1<<6);
	
}

static inline void instrucaoLCD(char funcao[], uint8_t nibble){
	if(funcao == "functionSetModo"){
		GPIOR1 = 0x02;
	}
	if(funcao == "functionSetTela"){
		if(nibble == 0){
			GPIOR1 = 0x02;
		}
		else{
			GPIOR1 = 0x08;
		}
	if(funcao == "displayOnOff"){
		if(nibble == 0){
			GPIOR1 = 0x00;
		}
		else{
		GPIOR1 = 0x0E;
		}
	}
	if(funcao == "entryModeSet"){
		if(nibble == 0){
			GPIOR1 = 0x00;
		}
		else{
			GPIOR1 = 0x06;
		}
	}
	if(funcao == "writeDataDR"){
		if(nibble == 0){
			GPIOR1 = 0x00;
		}
		else{
			GPIOR1 = 0x06;
		}
	}
	if(funcao == "writeDataIR"){
		if(nibble == 0){
		GPIOR1 = 0x00;
		}
		else{
		GPIOR1 = 0x06;
		}
	}
}

static inline void enviaLetra(char letra){
	
}