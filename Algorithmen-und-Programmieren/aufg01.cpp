// Aufgabe 01
#include <stdio.h>
#include <math.h>
double kreis(double x1, double y1, double x2, double y2, double x3, double y3, int what); // Prototyp

void main()
{
	// Teil 1
	FILE *fin; // don't forget pointer
	double x, y;
	int count = 0;
	fopen_s(&fin,"kreis.dat", "r");
	do
	{
		fscanf_s(fin, "%lf %lf \n", &x, &y);
		printf("%lf \n", x);
		count++;
	} while (!feof(fin));

	fclose(fin); // don't forget close

	double *xx, *yy;
	xx = new double[count];
	yy = new double[count];

	fopen_s(&fin, "kreis.dat", "r"); // here "r"; fopen_s -> &fin
	for (int i = 0; i < count; i++)
	{
		fscanf_s(fin, "%lf %lf \n", &xx[i], &yy[i]); // fscanf_s read data -> &x
		printf("%lf %lf \n", xx[i], yy[i]);
	}
	fclose(fin);

	fopen_s(&fin, "aufg01.dat", "w"); 
	for (int i = 0; i < count; i++)
	{
		fprintf_s(fin, "%10.5lf %10.5lf \n", xx[i], yy[i]);  // fprintf_s write data -> x
	}
	fclose(fin); // fclose -> fin

	// Teil 2
	
	double *R, *xm, *ym;
	R =  new double [count/3.];
	xm = new double [count/3.];
	ym = new double [count/3.];
	
	int index=0;
	for (int i = 0; i <= count/3 -1 ; i++)
	{
		xm[i] = kreis(xx[index], yy[index], xx[index + 1], yy[index + 1], xx[index + 2], yy[index + 2], 1);
		ym[i] = kreis(xx[index], yy[index], xx[index + 1], yy[index + 1], xx[index + 2], yy[index + 2], 2);
		R[i]  = kreis(xx[index], yy[index], xx[index + 1], yy[index + 1], xx[index + 2], yy[index + 2], 3);
		
		printf("%5.2lf %5.2lf %5.2lf %5.2lf %5.2lf %5.2lf \n", xx[index], yy[index], xx[index +1], yy[index +1], xx[index +2], yy[index +2]);
		printf("%5.2lf %5.2lf %5.2lf \n", xm[i], ym[i], R[i]);

		index = index + 3;
	}
	

	// Teil 3
	fopen_s(&fin, "RMP.dat", "w");
	for (int i = 0; i <= count/3 - 1; i++)
	{
		fprintf_s(fin, "%5.2lf %5.2lf %5.2lf \n", R[i], xm[i], ym[i]);
	}
	fclose(fin);

	delete[] R;
	delete[] xm;
	delete[] ym;

	delete[] xx;
	delete[] yy;

	scanf_s("finish");
}
double kreis(double x1, double y1, double x2, double y2, double x3, double y3, int what)
{
	double xm, ym, R;
	double a, b, x12q, x13q, y12q, y13q;
	double x12, x13, y12, y13;

	x12q = (x1 * x1 - x2 * x2);
	x12 = (x1 - x2);
	x13q = (x1 * x1 - x3 * x3);
	x13 = (x1 - x3);

	y12q = (y1 * y1 - y2 * y2);
	y12 = (y1 - y2);
	y13q = (y1 * y1 - y3 * y3);
	y13 = (y1 - y3);

	b = (x12q + y12q) / (2. * y12) -
		(x13q + y13q) / (2. * y13);
	a = x12 / y12 - x13 / y13;

	xm = b / a;    ym = (-x12q + 2. * x12 * xm - y12q) /
		(-2. * y12);
	R = sqrt(pow(x1 - xm, 2) + pow(y1 - ym, 2));

	if (what == 1) return(xm);
	if (what == 2) return(ym);
	if (what == 3) return(R);
}
