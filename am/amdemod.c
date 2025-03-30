/*
Kafus szerverrel:
./parancs.sh
Otthoni RTL-SDR-rel:
./parancs.sh rtl
"Konzerv" IQ fileal:
./parancs.sh iq

*/

#include <math.h>
#include <stdio.h>


/*
####################################################
# CNCO - complex numerically controlled oscillator #
####################################################

Since we have a "DC-spike" at the tuned frequency, it messes with AM demodulaion.
We could remove it by high-pass filtering the signal, but a better-ish way is "offset tuning"
I.e. tuning offset to the wanted frequency, the doing a complex mixing in software.

In this example, I tuned the receiver -50 kHz to the airband voice channel.
Transmitting station is at 127.4 MHz, but I tuned my receiver to 127.35 MHz.
This means we have to mix with a -50 kHz complex sinusoidal.
With the sampling rate of 300 ksps, this happens to make the period of the LO 6 samples.
We can pre-calculate the samples with init_cnco(), then just use a simple counter to get samples.

Sadly, TCC does NOT like complex numbers in C, so I had to separate the real and imaginary parts.
*/
#define SAMP_RATE 300000
#define CNCO_FREQ 50000
#define CNCO_LEN (SAMP_RATE/CNCO_FREQ)

double cnco_re[CNCO_LEN] = {0};
double cnco_im[CNCO_LEN] = {0};
int cnco_index = 0;

void init_cnco() {
    fprintf(stderr, "CNCO coeffs:\n");
    for (int i = 0; i<CNCO_LEN; i++) {
        cnco_re[i] = cos(-2*M_PI/CNCO_LEN * i);
        cnco_im[i] = sin(-2*M_PI/CNCO_LEN * i);
        fprintf(stderr, "   %+.04f %+.04f j \n", cnco_re[i], cnco_im[i]);
    }
}


/*
###########################################
# Filtering using a 5 pole lowpass filter #
###########################################

This function implements a 5-pole lowpass IIR filter.
It is a modified version of code from http://jaggedplanet.com/iir/iir-explorer.asp
Design parameters:
- type: Butterworth
- form: Low-pass
- order: 5
- samplerate: 300 000
- cutoff: 3000

Modified so it can use multiple buffers so we can implement multiple filters.
Also replaced the REAL macro with the type double.
*/

#define NPOLE 5
#define NZERO 5

// ARMA coefficientss
double acoeff[]={-0.5000770250434126,2.845930095518337,-6.505325969335695,7.468810211520886,-4.309016509484266,1};
double bcoeff[]={1,5,10,10,5,1};
double gain=99749.63594223674;

// buffers for the filers
double xv_i[NZERO+1]={0};
double yv_i[NPOLE+1]={0};
double xv_q[NZERO+1]={0};
double yv_q[NPOLE+1]={0};

double applyfilter(double v, double *xv, double *yv)
{
	int i;
	double out=0;
	for (i=0; i<NZERO; i++) {xv[i]=xv[i+1];}
	xv[NZERO] = v/gain;
	for (i=0; i<NPOLE; i++) {yv[i]=yv[i+1];}
	for (i=0; i<=NZERO; i++) {out+=xv[i]*bcoeff[i];}
	for (i=0; i<NPOLE; i++) {out-=yv[i]*acoeff[i];}
	yv[NPOLE]=out;
	return out;
}



int main()
{
    init_cnco();

	double i, q, s;
	for(;;)
	{
        // read I & Q samples from STDIN
		i=((unsigned char)getchar()-127); q=((unsigned char)getchar()-127);

		// get CNCO sample
        double cr = cnco_re[cnco_index];
        double ci = cnco_im[cnco_index];
        cnco_index = (cnco_index + 1) % CNCO_LEN;


        // multiply by cnco
        // (i+jq)*(cr+jci) = (i*cr-q*ci)+j(q*cr+i*ci)
        double mi = (i*cr-q*ci);
        double mq = (q*cr+i*ci);
        i = mi; q = mq;


        // filter them both
        i = applyfilter(i, xv_i, yv_i);
        q = applyfilter(q, xv_q, yv_q);

        // take absolute value & amplify
        s = sqrt(i*i + q*q)*20;

        // print result
        putchar((unsigned char)(s+127));
	}
}

