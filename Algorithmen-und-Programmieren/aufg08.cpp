// aufg08

#include <stdio.h>
#include <math.h>

void Gauss_seid(double *b, double *d, double *a, double*u, double *RHS, int n);

void main()
{
	// Teil 1
	/*
		u_{i+1} - 2u_{i} +u_{i-1} = -\delte y^2

		[ -2 1     ][u_0    ]   [-\delte y^2]
		[ 1 -2 1   ][u_1    ] = [-\delte y^2]
		[ 0 1 -2 1 ][...    ] = [-\delte y^2]
		[ .........][u_{n-1}]   [-\delte y^2]
	*/

	// Teil 2
	// [b d a]//
	int n = 100;
	double *a, *b, *d, *u, *RHS;
	a = new double[n];
	b = new double[n];
	d = new double[n];
	u = new double[n];
	RHS = new double[n];

	double delta_y = 0.1;

	for (int i = 0; i < n; i++)
	{
		b[i] = 1; // b[0] loeschen
		d[i] = -2;
		a[i] = 1; // a[n] loeschen
		RHS[i] = -pow(delta_y, 2);
	}
	b[0] = 0;
	a[n-1] = 0;

	FILE *fin;

	fopen_s(&fin, "aufg08.dat", "w");

	Gauss_seid(b, d, a, u, RHS, n);

	for (int i = 0; i < n; i++)
	{
		fprintf_s(fin, "%lf \n", u[i]);
	}
	fclose(fin);

	delete[] a;
	delete[] b;
	delete[] d;
	delete[] u;
	delete[] RHS;
}

void Gauss_seid(double *b, double *d, double *a, double*u, double *RHS, int n)
{
	double *r;
	r = new double[n];

	// initialize
	for (int i = 0; i < n; i++)
	{
		u[i] = RHS[i];
	}
	double R;
	do
	{ 
		u[0] = (RHS[0] - a[0] * u[1]) / d[0];
		for (int i = 1; i < n-1; i++)
		{
			u[i] = (RHS[i] - (a[i] * u[i + 1] + b[i] * u[i - 1])) / d[i];
		}
		u[n-1] = (RHS[n-1] - b[n-1] * u[n-2]) / d[n-1];

		// Residuum
		r[0] = (a[0] * u[1] + d[0] * u[0]) - RHS[0];
		for (int i = 1; i < n-1; i++)
		{
			r[i] = (a[i] * u[i + 1] + d[i] * u[i] + b[i] * u[i - 1]) - RHS[i];
		}
		r[n-1] = (d[n-1] * u[n-1] + b[n-1] * u[n - 2]) - RHS[n-1];

		R = 0;
		for (int i=0; i < n; i++)
		{
			R = R + r[i]* r[i];
		}
		R = sqrt(R);

	} while (R > 0.01);

	delete[] r;
}

