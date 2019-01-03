// EXPLIZITES VERFAHREN

#include <stdio.h>
#include <math.h>

void main()
{
	double alpha = 10., lambda = 15., u = 0.22, L = 0.3;
	double c = 500., rho = 7600.;
	double Ta = 150., Tu = 20., CFL = 0.3, a, A = 0.001;

	int m = 20, m_zeit = 1000;
	double dx = L / (m-1), *x, *T_old, *T_new;

	a = lambda / (rho*c);

	x = new double[m];
	T_new = new double[m];
	T_old = new double[m];

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

	FILE *james;
	fopen_s(&james, "temperatur.dat", "w");
	// james = fopeen("temperatur.dat", "w");
	for (int i = 1; i <= m_zeit; i++)
	{
		// Randbedingung
		T_new[0] = Ta;
		T_new[m - 1] = Tu;
		for (int j = 1; j <= m - 2; j++)
		{
			T_new[j] = a * (T_old[j + 1] - 2.*T_old[j] + T_old[j - 1]) / (dx*dx) *dt - alpha*u*dt / (rho * A * c)*(T_old[j] - Tu) + T_old[j];
		}

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

}