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
	fopen_s(&fin,"xy.dat", "r");
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

	fopen_s(&fin, "xy.dat", "r"); // here "r"; fopen_s -> &fin
	for (int i = 0; i < count; i++)
	{
		fscanf_s(fin, "%lf %lf \n", &xx[i], &yy[i]); // fscanf_s read data -> &x
		printf("%lf \n", xx[i]);
	}
	fclose(fin);

	fopen_s(&fin, "aufg01.dat", "w"); 
	for (int i = 0; i < count; i++)
	{
		fprintf_s(fin, "%10.5lf %10.5lf \n", xx[i], yy[i]);  // fprintf_s write data -> x
	}
	fclose(fin); // fclose -> fin

	delete [] xx;
	delete [] yy;

	scanf_s("finish");

	// Teil 2
	/*
	double *R, *xm, *ym;
	R = new double [n];
	xm = new double [n];
	ym = new double [n];
	
	int index=0;
	for(int i=0; i<=n-1; i++)
	{
		xm[i] = kreis(xx[index], yy[index], xx[index+1], yy[index+1], xx[index+1], yy[index+1], 1);
		ym[i] = kreis(xx[index], yy[index], xx[index+1], yy[index+1], xx[index+1], yy[index+1], 2);
		R[i]  = kreis(xx[index], yy[index], xx[index+1], yy[index+1], xx[index+1], yy[index+1], 3);
	]

	delete[] R;
	delete[] xm;
	delete[] ym;
	*/

	// Teil 3
	int n = 10;
	fopen_s(&fin, "RMP.dat", "w");
	for (int i = 0; i <= n - 1; i++)
	{
		// fprintf_s(fin, "%5.2lf %5.2lf %5.2lf \n", R[i], xm[i], ym[i]);
	}
	fclose(fin);
}
