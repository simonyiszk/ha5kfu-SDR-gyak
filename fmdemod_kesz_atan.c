#include <math.h>
#include <stdio.h>


int main ()
{
    double i, q, s, phi, pphi;
    // pphi az elozo mintak szoge
    for (;;) // vegtelen ciklus
    {
        // beolvassuk az I mintat , az offszetet levonjuk , hogy a 0 tenyleg 0 legyen
        i =(( unsigned char ) getchar () -127) ;
        // Q- val ugyan ez
        q =(( unsigned char ) getchar () -127) ; // beolvassuk

        // atan2 olyan mint az atan(q/i), megmondja a szoget
        // de minden siknegyedben helyes eredmenyt ad, akarcsak ha 0 valamelyik minta
        phi = atan2(q, i);
        double dphi = phi - pphi;
        pphi = phi;

        s = 50*dphi;

        // s-t visszaalakitjuk offszetese majd kiirjuk
        putchar (( unsigned char ) ( s +127) ) ;
    }
}
