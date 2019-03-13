#include <stdio.h>
#include <math.h>

void main()
{
	FILE *fin;
	fopen_s(&fin, "review.dat", "r");
	double xx, yy;
	int count = 0;
	do
	{
		fscanf_s(fin, "%lf %lf \n", &xx, &yy);
	    count++;
	} while (!feof(fin));
	fclose(fin);

	double *x, *y;
	x = new double[count];
	y = new double[count];

	fopen_s(&fin, "review.dat", "r");
	for (int i = 0; i < count; i++)
	{
		fscanf_s(fin, "%lf %lf \n", &x[i], &y[i]);
	}
	fclose(fin);

	fopen_s(&fin, "_review.dat", "w");
	for (int i = 0; i < count; i++)
	{
		fprintf_s(fin, "%lf %lf \n", x[i], y[i]);
	}
	fclose(fin);

	// newton
	double v = 1.;
	double w = pow(v,2);
	
	do
	{
		double w_abl = 2.*v;
		v = v - w/w_abl;
		w = pow(v,2);
	}while(fabs(w)>1.e-8);
	printf_s("%lf \n", v);

	
	// Runge Kutta
	/*
	FILE *fin;
	fopen_s(&fin, "aufg05.dat", "w");
	int count = 0;
	v = 0;
	do
	{
		v1 = v; // not add deltaT
		a1 = g - ((cw1*rho / 2 * v1*v1*A) / m);
		
		v2 = v + a1 * dt / 2;
		a2 = g - ((cw1*rho / 2 * v2*v2*A) / m);

		v3 = v + a2 * dt / 2;
		a3 = g - ((cw1*rho / 2 * v3*v3*A) / m);

		v4 = v + a3 * dt;
		a4 = g - ((cw1*rho / 2 * v4*v4*A) / m);

		kz = 1. / 6. * (v1 + 2 * v2 + 2 * v3 + v4); // ./.
		kv = 1. / 6. * (a1 + 2 * a2 + 2 * a3 + a4);

		H = H - kz * dt; // need both H and v
		v = v + kv * dt;

		fprintf_s(fin, "%lf %lf \n", v, H);
		
		count++;

	} while (H > H2);

	*/
	
	
	
	
	scanf_s(" ");

	delete[] x;
	delete[] y;

}