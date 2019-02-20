// aufg05
#include <stdio.h>
#include <math.h>

void main()
{
	// Teil 1
	/*
		0 = m {x''}
		mg - F_w = m {y''}

		0 = {x'}
		c = {y'}
	*/

	double A, rho, t, g, m;
	double cw1 = 0.2, cw2 = 5;

	double v, a;
	double dt = 0.001;

	v = 0;
	a = 0;
	g = 9.81;
	A = 1;
	m = 1;
	
	double H1 = 5000, H2 = 2000, H=5000;

	double v1, v2, v3, v4;
	double a1, a2, a3, a4;


	FILE *fin;
	fopen_s(&fin, "aufg05.dat", "w");
	int count = 0;
	do
	{
		v1 = v;
		a1 = g - ((cw1*rho / 2 * v1*v1*A) / m);
		
		v2 = v1 + a * dt / 2;
		a2 = g - ((cw1*rho / 2 * v2*v2*A) / m);

		v3 = v2 + a * dt / 2;
		a3 = g - ((cw1*rho / 2 * v3*v3*A) / m);

		v4 = v3 + a * dt;
		a4 = g - ((cw1*rho / 2 * v3*v3*A) / m);

		v = 1 / 6 * (v1 + 2 * v2 + 2 * v3 + v4);
		a = 1 / 6 * (a1 + 2 * a2 + 2 * a3 + a4);

		H = H - v * dt;

		fprintf_s(fin, "%lf %lf", v, H);
		
		count++;

	} while (H > H1);

	double t1 = count * dt;
	fprintf_s(fin, "The total time is %lf", t1);

	do
	{
		v1 = v;
		a1 = g - ((cw2*rho / 2 * v1*v1*A) / m);

		v2 = v1 + a * dt / 2;
		a2 = g - ((cw2*rho / 2 * v2*v2*A) / m);

		v3 = v2 + a * dt / 2;
		a3 = g - ((cw2*rho / 2 * v3*v3*A) / m);

		v4 = v3 + a * dt;
		a4 = g - ((cw2*rho / 2 * v3*v3*A) / m);

		v = 1 / 6 * (v1 + 2 * v2 + 2 * v3 + v4);
		a = 1 / 6 * (a1 + 2 * a2 + 2 * a3 + a4);

		H = H - v * dt;

		fprintf_s(fin, "%lf %lf", v, H);

		count++;

	} while (H > 0);

	double t2 = count * dt;
	fprintf_s(fin, "The total time is %lf", t2);


	fclose(fin);


}