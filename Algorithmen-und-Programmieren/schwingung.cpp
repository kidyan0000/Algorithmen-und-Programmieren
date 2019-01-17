// Schwingungsprobleme

#include <math.h>
#include <stdio.h>

void main()
{
	double dt, t_end = 8.;
	double x0 = 0., v0 = 1.; // Anfangsbedingung
	int n = 1000;
	double c = 5., m = 1.; // c ist die Federsteidigkeit
	double k1y, k2y, k3y, k4y, ky;
	double k1x, k2x, k3x, k4x, kx;
	double *x, *t, *y;

	dt = t_end / (n - 1);

	x = new double[n];
	y = new double[n];
	t = new double[n];

	// Anfangsbedingungen
	t[0] = 0.;
	x[0] = x0;	y[0] = v0;

	// RUNGE-KUTTA-VERFAHREB
	// musst from i=1 run!!!
	for (int i = 1; i <= n - 1; i++)
	{	
		t[i] = t[i - 1] + dt;

		k1y = -c / m * x[i - 1];
		k1x = y[i - 1];

		k2y = -c / m * (x[i - 1] + k1x * dt / 2.);
		k2x = y[i - 1] + k1y * dt / 2.;

		k3y = -c / m * (x[i - 1] + k2x * dt / 2.);
		k3x = y[i - 1] + k2y * dt / 2.;

		k4y = -c / m * (x[i - 1] + k3x * dt );
		k4x = y[i - 1] + k3y * dt;

		kx = (k1x + 2.*k2x + 2.*k3x + k4x) / 6.;
		ky = (k1y + 2.*k2y + 2.*k3y + k4y) / 6.;

		x[i] = x[i - 1] + kx * dt;
		y[i] = y[i - 1] + ky * dt;
	}

	FILE *fin;
	fopen_s(&fin, "schiwng.dat", "w");
	for (int i = 0; i <= n - 1; i++)
	{
		fprintf_s(fin, "%15.6lf %15.6lf %15.6lf\n", t[i], x[i], y[i]);
	}
	fclose(fin);


	delete[] x;
	delete[] y;
	delete[] t;
	
}