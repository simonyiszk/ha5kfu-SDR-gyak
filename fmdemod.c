/*

Kafus szerverrel:
./parancs.sh
Otthoni RTL-SDR-rel:
./parancs_rtlsdr.sh
"Konzerv" IQ fileal:
./parancs_konzerviq.sh

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

