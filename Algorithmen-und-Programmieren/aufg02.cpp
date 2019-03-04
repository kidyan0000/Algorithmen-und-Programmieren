// Augfgabe 02
#include <stdio.h>
#include <math.h>
#include <cmath>

void main()
{
	int    n = 10000; // set to 10000
	double a = 1.0;
	double b = 1.5;
	double dx = (b - a)/(n - 1);
	double pi = acos(0) * 2.;

	double x0;
	double y;
	
	x0 = 1.5;
	/*
	do
	{
		y = sin(pow(x0, 2) / 2.*pi);
		x0 = x0 - dx;

	} while (y < 0.); // stop until y<0
	*/

	double ds;
	double s = x0;
	
	FILE *fin;
	fopen_s(&fin, "aufg02.dat", "w");
	int i = 0;
	do
	{
		do
		{
			ds = -((sin(pow(s, 2) / 2.*pi)) / (s*pi*cos(pow(s, 2) / 2. * pi))); // pi
			s = s + ds;
			y = sin(pow(s, 2) / 2.*pi);
			fprintf_s(fin, "%10.5lf %5.2f \n", y, s);
			i++;
		} while (abs(y) > 0.000000001); // use bigger than
	} while (s > 1.5 || s < 1.0); // when not statisfied -> STOP
								  // in our case should 1.0<s<1.5

	fclose(fin);

	printf("%10.5lf %5.2f %i", y, s,i);
	scanf_s("%5.2lf",&y);
	
}