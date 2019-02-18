// aufg03
#include <stdio.h>
#include <math.h>

double trapez(double *x, double *y, int n);

void main()
{
	double T = 0.001;

	int count = 0;
	double tt, yy;
	
	// file read
	FILE *fin;
	fopen_s(&fin, "aufg03_dat.dat", "r");
	
	do
	{
		fscanf_s(fin, "%lf %lf \n", &tt, &yy); // "%lf"
		count++;
	} while (!feof(fin));
	fclose(fin);

	double *t, *y;
	t = new double[count];
	y = new double[count];

	fopen_s(&fin, "aufg03_dat.dat", "r");
	for (int i=0; i < count; i++)
	{
		fscanf_s(fin, "%lf %lf \n", &t[i], &y[i]);
	}
	fclose(fin);

	fopen_s(&fin, "test.dat", "w");
	for (int i = 0; i < count; i++)
	{
		fprintf_s(fin, "%f %lf \n", t[i], y[i]);
	}
	fclose(fin);

	// calcaulate the coefficients
	int n = 5; // number of the coefficients
	double *a_k, *b_k;
	a_k = new double[n];
	b_k = new double[n];

	double pi = 2. * acos(0.);
	double omega = 2. * pi / T; // omega = 2.*pi/T

	double *intg_sin, *intg_cos;
	intg_sin = new double[count];
	intg_cos = new double[count];
	
	fopen_s(&fin, "aufg03_coef.dat", "w");
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < count; i++)
		{
			intg_sin[i] = y[i] * sin(k*omega*t[i]);
			intg_cos[i] = y[i] * cos(k*omega*t[i]); // t[i]
		}
		a_k[k] = 2. / T * trapez(t, intg_cos, count);
		b_k[k] = 2. / T * trapez(t, intg_sin, count);

		fprintf_s(fin, "%lf %lf \n", a_k[k], b_k[k]); //%5.2lf
	}
	fclose(fin);

	double F_t;
	double F;

	double *F_orig, *F_mod;
	F_orig = new double[count];
	F_mod = new double[count];

	fopen_s(&fin, "aufg03_results_orig.dat", "w");
	for (int i = 0; i < count; i++)
	{
		F = a_k[0] / 2.;
		for (int k = 1; k < n; k++)
		{
			F_t = a_k[k] * cos(k*omega*t[i]) + b_k[k] * sin(k*omega*t[i]);
			F = F + F_t;
		}
		F_orig[i] = F;
		fprintf_s(fin, "%lf \n", F_orig[i]);

	}
	fclose(fin);

	// calculate the frequence
	fopen_s(&fin, "aufg03_coef_mod.dat", "w");
	for (int k = 0; k < n; k++)
	{
		double freq = k * omega;
		if (freq > 3000)
		{
			a_k[k] = a_k[k] / 2.;
			b_k[k] = b_k[k] / 2.;
		}
		fprintf_s(fin, "%lf %lf \n", a_k[k], b_k[k]);
	}
	fclose(fin);

	fopen_s(&fin, "aufg03_results_mod.dat", "w");
	for (int i = 0; i < count; i++)
	{
		F = a_k[0]/2.;
		for (int k = 1; k < n; k++)
		{
			F_t = a_k[k] * cos(k*omega*t[i]) + b_k[k] * sin(k*omega*t[i]);
			F = F + F_t;
		}
		F_mod[i] = F;
		fprintf_s(fin, "%lf \n", F_mod[i]);

	}
	fclose(fin);

	delete[] t;
	delete[] y;

	delete[] a_k;
	delete[] b_k;

	delete[] intg_sin;
	delete[] intg_cos;
	
	delete[] F_orig;
	delete[] F_mod;
}

double trapez(double *x, double *y, int n)
{
	double A = 0.;
	for (int i = 0; i <= n-2; i++)
	{
		double A_t = (y[i + 1] + y[i])*(x[i + 1] - x[i]) / 2.;
		A = A + A_t;
	}
	return A;
}
