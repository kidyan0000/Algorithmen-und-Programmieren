// DIESES IST EIN PROGRAM ZUM BERECHNEN DES KREIS

/*Commentar*/

#include<math.h>
#include<stdio.h> //Eingabe der Datei

double kreis( double x1, double y1, double x2, double y2, double x3, double y3, int what); //PROTOTYP//

void main()
{
	double x1, y1, x2, y2, x3, y3;
	double xm, ym, R;
	
	printf("Gebe x1 ein:\n");
	scanf_s("%lf", &x1);
	printf("Gebe y1 ein:\n");
	scanf_s("%lf", &y1);
	printf("Gebe x2 ein:\n");
	scanf_s("%lf", &x2);
	printf("Gebe y2 ein:\n");
	scanf_s("%lf", &y2);
	printf("Gebe x3 ein:\n");
	scanf_s("%lf", &x3);
	printf("Gebe y3 ein:\n");
	scanf_s("%lf", &y3);
	
	xm = kreis( x1, y1, x2, y2, x3, y3, 1);
	ym = kreis( x1, y1, x2, y2, x3, y3, 2);
	R = kreis( x1, y1, x2, y2, x3, y3, 3);
	
	printf("xm = %5.2lf, ym = %5.2lf, R = %5.2lf\n", xm, ym, R); /*xx,xx z.B 06.22*/
	scanf_s("%lf", &R);
}	
	
double kreis( double x1, double y1, double x2, double y2, double x3, double y3, int what)
{
    //double 16Byte
	double xm, ym, R;
	double a, b, x12q, x13q, y12q, y13q;
	double x12, x13, y12, y13;

	x12q = (x1*x1 - x2*x2);
	x12 = (x1 - x2);

	x13q = (x1*x1 - x3*x3);
	x13 = (x1 - x3);

	y12q = (y1*y1 - y2*y2);
	y12 = (y1 - y2);

	y13q = (y1*y1 - y3*y3);
	y13 = (y1 - y3);

	/* Berechnung der Lösung*/

	b = (x12q + y12q) / (2. * y12)
		-
		(x13q + y13q) / (2. * y13);

	a = x12 / y12 - x13 / y13;
	
	xm = b / a;
	ym = (-x12q + 2. * x12 * xm - y12q) / (-2. * y12);
	R = sqrt(pow(x1-xm,2) + pow(y1-ym,2));

    if( what == 1 ) return( xm );
	if( what == 2 ) return( ym );
	if( what == 3 ) return( R );
}