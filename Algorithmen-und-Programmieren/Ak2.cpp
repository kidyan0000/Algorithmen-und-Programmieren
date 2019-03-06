#include <math.h>
#include <stdio.h>

double schub(double z, double C, double m);

void main() // void
{	// Teil 1
	/*
	S - (F_w + mg) = mz''
	S = 6.*m*g*(1-(z/40.)*(z/40.))
	F_w = c_w * rho/2. * C*C *A
	*/

	double S = schub(30, 10, 200);

	FILE *fin;
	fopen_s(&fin, "Ak2.dat", "w");
	int n = 0;

	double m = 200.0;
	double c_w = 0.13, A = 0.2, rho = 1.225;
	double dt = 0.1;

	double G = m * 9.81;

	double w = 0.0;
	double z = 0.0;
	double kz1, kz2, kz3, kz4, kz;
	double kw1, kw2, kw3, kw4, kw;
	double z1, z2, z3, z4;
	double w1, w2, w3, w4;
	do
	{
		double S, F_w;


		//
		w1 = w;
		z1 = z; // first timestep not times deltaT
		S = schub(z1, w1, m);
		F_w = c_w * rho / 2. * w1 * w1 *A;
		kw1 = (S - F_w - G) / m; // minus - richutng		
		kz1 = w1;

		//
		w2 = w + kw1 * dt/2.; // always using w abd z as base
		z2 = z + kz1 * dt/2.;
		S = schub(z2, w2, m);
		F_w = c_w * rho / 2. * w2 * w2 *A;
		kw2 = (S - F_w - G) / m;
		kz2 = w2;
		//
		w3 = w + kw2 * dt/2.;
		z3 = z + kz2 * dt/2.;
		S = schub(z3, w3, m);
		F_w = c_w * rho / 2. * w3 * w3 *A;
		kw3 = (S - F_w - G) / m;
		kz3 = w3;
		//
		w4 = w + kw3 * dt;
		z4 = z + kz3 * dt;
		S = schub(z4, w4, m);
		F_w = c_w * rho / 2. * w4 * w4 *A;
		kw4 = (S - F_w - G) / m;
		kz4 = w4;

		kz = 1. / 6.*(kz1 + 2 * kz2 + 2 * kz3 + kz4);
		kw = 1. / 6.*(kw1 + 2 * kw2 + 2 * kw3 + kw4);

		z = z + kz * dt;
		w = w + kw * dt;

		n++;
		double time = n * dt;
		fprintf_s(fin, "%10.8lf %10.8lf %10.8lf \n", time, z, w);


	} while (z > 0 && n<10000);

	

	fclose(fin);
}


double schub(double z, double C, double m)
{
	double g = 9.81;
	double S;
	
	if (C < 0)
	{
		S = 0;
	}
	else
	{
		if (z >= 0 && z <= 40000)
			S = 6.*m*g*(1 - (z / 40000.)*(z / 40000.)); // Einheit
		else
			S = 0;
	}

	return S; // return nicht vergessen
}