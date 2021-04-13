/*
 * main.c
 *
 * Created: 3/25/2021 11:35:58 AM
 *  Author: lucas
 */ 

#include <xc.h>
#include <math.h>

static inline int FM_r2rEntrada(int deg, int fc, int fm);
static inline int AM_r2rEntrada(int deg, int fc, int fm);

int main(void)
{
	DDRD = 0xFF;
	while(1){
		for(int i = -180; i<= 180; i++){
			PORTD = AM_r2rEntrada(i, 16, 1);
		}
	}
}


static inline int FM_r2rEntrada(int deg, int fc, int fm){
	float s=0;
	s = cos((M_PI/180)*fc*deg + (1/fm)*sin((M_PI/180)*fm*deg));
	return  127 + (uint8_t)((127 * s));
}
static inline int AM_r2rEntrada(int deg, int fc, int fm){
	float s=0;
	s = cos((M_PI/180)*deg*fc)*cos((M_PI/180)*deg*fm);
	return  127 + (uint8_t)((127 * s));
}