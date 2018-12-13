#include<math.h>
#include<stdio.h>

void tomy(int il, int iu, double *b, double *d, double *a, double *c, double *l);

void main()
{
	double qo = 200., l = 1., J = 5.4e-7;
	double E = 2.1e-5 * 1e6, dx;
	int n = 10; //Anzahl der Aufpunkte

	dx = 1 / (n - 1);

	// Speicherplatz anfordern
	double *d, *b, *a, *RHS, *x, *w;
	d = new double[n];
	b = new double[n];
	a = new double[n];
	RHS = new double[n];
	x = new double[n];
	w = new double[n];

	for (int i = 0; i <= n - 1; i++)
	{
		d[i] = -2.;
		a[i] = 1.;
		b[i] = 1.;

		x[i] = i * dx;

		RHS[i] = (qo * 1 * x[i] * dx*dx) / (E*J*6)*(pow(x[i] / l, 2) - 1.);
	}

	tomy(1, n-2, b, d, a, RHS, w);

	delete[] b;
	delete[] a;
	delete[] d;
	delete[] RHS;
	delete[] x;
	delete[] w;

}
