/*

Kafus szerverrel:

nc teto.sch.bme.hu 7373 | tcc -lm -run fmdemod.c | sox -t raw -r 240000 -e unsigned -b 8 -c 1 - -t raw - rate 48000 | aplay -f U8 -c1 -r 48000 --buffer-size=200000

Otthoni RTL-SDR-rel:

rtl_sdr -s 240000 -f 89500000 -g 20 - | tcc -lm -run fmdemod.c | sox -t raw -r 240000 -e unsigned -b 8 -c 1 - -t raw - rate 48000 | aplay -f U8 -c1 -r 48000 --buffer-size=200000

*/

#include <math.h>
#include <stdio.h>

int main()
{
	double i, q, s;
	for(;;)
	{
		i=((unsigned char)getchar()-127); q=((unsigned char)getchar()-127);
		
		// TODO ide írd a kódot
		
		putchar((unsigned char)(s+127));
	}
}

