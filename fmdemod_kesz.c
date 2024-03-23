#include <math.h>
#include <stdio.h>


int main ()
{
    double i, q, s, ip, qp;
    // ip, qp az elozo i es q ertekek
    for (;;) // vegtelen ciklus
    {
        // beolvassuk az I mintat , az offszetet levonjuk , hogy a 0 tenyleg 0 legyen
        i =(( unsigned char ) getchar () -127) ;
        // Q- val ugyan ez
        q =(( unsigned char ) getchar () -127) ; // beolvassuk


        // di, dq a derivaltat kozeliti
        // diszkret idoben "igy kell derivalni"
        // csak egy konstans szorzo maradt le
        double di = i - ip;
        double dq = q - qp;

        // arctan derivaltja szerint, a szorzo az elejen kiserlezetes alapjan lett ennyi
        s = 20 * (di*q - dq*i)/(i*i+q*q);

        // elozo mintak beallitasa
        qp = q;
        ip = i;

        // s-t visszaalakitjuk offszetese majd kiirjuk
        putchar (( unsigned char ) ( s +127) ) ;
    }
}
