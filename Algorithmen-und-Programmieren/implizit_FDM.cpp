// EXPLIZITES VERFAHREN

#include <stdio.h>
#include <math.h>

void tomy(int il, int iu, double *b, double *d, double *a, double *c, double *l);
/*
void bsp(int &a);

bsp(a);
bsp(*a);
*/

void main()
{
	double alpha = 10., lambda = 15., u = 0.22, L = 0.3;
	double c = 500., rho = 7600.;
	double Ta = 150., Tu = 20., CFL = 0.3, a, A = 0.001;

	int m = 20, m_zeit = 1000;
	double dx = L / (m-1), *x, *T_old, *T_new;
	double *aa, *bb, *dd, *RHS;

	a = lambda / (rho*c);

	x = new double[m];
	T_new = new double[m];
	T_old = new double[m];

	aa = new double[m];
	bb = new double[m];
	dd = new double[m];
	RHS = new double[m];
	
	for (int i = 0; i <= m - 1; i++)
	{
		x[i] = i * dx;
	}

	// Anfangsbedingung
	T_old[0] = Ta;
	for (int i = 1; i <= m - 1; i++)
	{
		T_old[i] = Tu;
	}

	// Zeitschritt
	double dt = CFL * dx*dx / a;

	// KOEFFIZIENTEN DES GLEICHUNGSSYSTEMS
	/*
	for (int i = 0; i <= m - 1; i++)
	{
		aa[i] = bb[i] = -a * dt / (dx*dx);
		dd[i] = 1. + 2.*a*dt / (dx*dx) + alpha * u / (rho*A*c) *dt;
		// RHS[i] = alpha * u*dt / (rho*A*c)*Tu;

	}
	*/

	FILE *james;
	fopen_s(&james, "temperatur.dat", "w");
	// james = fopeen("temperatur.dat", "w");
	for (int j = 0; j <= m - 1; j++)
	{
		fprintf_s(james, "%20.7lf", T_old[j]);
	}
	fprintf_s(james, "\n");

	for (int i = 1; i <= m_zeit; i++)
	{
		// IMPLIZIT FDM
		for (int j = 0; j <= m - 1; j++)
		{
			// KOEFFIZIENTEN DES GLEICHUNGSSYSTEMS
			aa[j] =	bb[j] = -a * dt / (dx*dx);
			dd[j] = 1. + 2.*a*dt / (dx*dx) + alpha * u / (rho*A*c) *dt;
			RHS[j] = alpha * u*dt / (rho*A*c)*Tu + T_old[j];

		}
		// RANDBEDINGUNGEN
		aa[0] = 0.;
		bb[0] = 0.;
		dd[0] = 1.;
		RHS[0] = Ta;

		aa[m - 1] = 0.;
		bb[m - 1] = 0.;
		dd[m - 1] = 1.;
		RHS[m - 1] = Tu;

		// SOLVE THE EQUATIONS
		tomy(0, m-1, bb, dd, aa, RHS, T_new);

		for (int j = 0; j <= m - 1; j++)
		{
			T_old[j] = T_new[j];
			fprintf_s(james, "%20.7lf", T_new[j]);

		}
		fprintf_s(james, "\n");

	}
	fclose(james);

	delete[] x;
	delete[] T_new;
	delete[] T_old;

	delete[] aa;
	delete[] bb;
	delete[] dd;
	delete[] RHS;

}