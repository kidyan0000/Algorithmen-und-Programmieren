// Aufg 07
// be careful about the memory
// we have here the array 0,1,2,3,4,5,..,m-1
// thus the loop should be form 1 to m-2
// the size of T is m
// and the last entry of T is m-1

#include <stdio.h>
#include <math.h>

void main()
{
	// Teil 1
	// Wärmeübertragung
	// 1. 1HS der Thermodynamik
	//		U = W + Q = cmT -> W = 0 -> d(cmT) = dQ
	// Fourier Transportansatz
	//		Q/A = -\lambda * (\partiel Q / \partiel x)
	// Wärmeübergang
	//		Q/A^ = \alpha * (T_2 - T_1)
	// Konvektiver
	//		Q/A* = \rho * c * A * v * T 
	
	// Teil 2
	double rho, c, v, lambda, alpha, U, A, l, T_u;
	rho = 1000.;
	c = 4200.;
	v = 0.1;
	U = 0.0628;
	A = 3.14e-4;
	alpha = 2.5;
	l = 20.;
	lambda = 0.6;
	T_u = 288.0;

	double a = lambda / (rho*c);
	double CFL = 0.5;
	double dx = 1;
	// double dt = CFL * dx*dx / a; // devergeniert!!!
	double dt = 0.01; // oszillation if using big dt?

	int m = l / dx + 1;

	double *T_1, *T_2;
	T_1 = new double[m];
	T_2 = new double[m];

	// Anfangsbedingung
	for (int i = 0; i < m; i++)
	{
		T_1[i] = 288.0;
	}
	// Randbedingung
	T_1[0] = 318.0;
	T_1[m-1] = 288.0; // only up to m-1

	T_2[0] = 318.0;
	T_2[m-1] = 288.0;

	FILE *fin;
	fopen_s(&fin, "aufg07.dat", "w");

	int count = 0;
	do
	{ 
		fprintf_s(fin, "time is %f \n", count*dt);
		for (int i = 1; i < m - 1; i++) // here up to m-2
			{
			T_2[i] = ((a*(T_1[i + 1] - 2 * T_1[i] + T_1[i - 1]) / (dx * dx)) - (v*(T_1[i + 1] - T_1[i - 1]) / (dx * 2)) - ((alpha*U / c / A / rho) * (T_1[i] - T_u) ))*dt+T_1[i];
			// T_2[i] = ((a*(T_1[i + 1] - 2 * T_1[i] + T_1[i - 1]) / (dx * dx)) - ((alpha*U / c / A / rho) * (T_1[i] - T_u)))*dt + T_1[i];
			}
		for (int i = 0; i < m; i++)
		{
			fprintf_s(fin, "%lf \n", T_2[i]);
		}

		// upadte the T_1
		for (int i = 0; i < m; i++)
		{
			T_1[i] = T_2[i];
		}

		fprintf_s(fin, "\n");

		count++;
	} while (count < 10000);
	fclose(fin);

	delete[] T_1;
	delete[] T_2;
}