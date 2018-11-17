// FOURIER TRANSFORMATION COEFFICIENTS //

#include<math.h>
#include<stdio.h>

double trapez(double *x, double *y, int& n);
void main()
{
	int count = 0; //COUNTER
	double tt, ff;
	FILE *fin;  // VARIABLE fin FÜR FILE MANAGEMENT
	fopen_s(&fin, "fourier.dat", "r"); // OPEN THE fourier.dat

	do
	{
		fscanf_s(fin, "%lf %lf\n", &tt, &ff);
		count = count + 1;
	} while (!feof(fin));
	fclose(fin);

	// DYNAMISCHE SPEICHER
	double *t, *f;
	t = new double[count];
	f = new double[count];

	fopen_s(&fin, "fourier.dat", "r");
	for (int i = 0; i <= count - 1; i++)
	{
		fscanf_s(fin, "%lf %lf", &t[i], &f[i]);
	}
	fclose(fin);

	// JETZT BERECHNEN DER KOEFFIZENTEN
	double T = t[count - 1];
	double pi = 2 * acos(0.);
	double omega = 2. * pi / T;
	int n = 100; // ANZAHL DER KOEFFIZIENTEN
	double *ak, *bk, *intgr;
	ak = new double[n];
	bk = new double[n];

	intgr = new double[count];

	for (int k = 0; k <= n - 1; k++) // INITIALISIEREN
	{
		ak[k] = 0.;
		bk[k] = 0.;
	}

	for (int k = 0; k <= n - 1; k++) // BERECHNEN UEBER ALLE KOEFF.
	{
		for (int i = 0; i <= count - 1; i++) // AUFFUELLEN DES INNTEGRANDS
		{
			intgr[i] = f[i] * cos(k*omega*t[i]);

		}
		ak[k] = 2. / T * trapez(t, intgr, count);

		for (int i = 0; i <= count - 1; i++) // AUFFUELLEN DES INNTEGRANDS
		{
			intgr[i] = f[i] * sin(k*omega*t[i]);

		}
		bk[k] = 2./T * trapez(t, intgr, count);
	}
	
	// HAUSSCHREIBEN DER KOEEFIZIENTEN
	double ak_th, bk_th;
	fopen_s(&fin, "koeff.dat", "w"); //w for WRITING
	for (int i = 0; i <= n - 1; i++)
	{
		if (i == 0)
		{
			ak_th = 1.;
		}
		else
		{
			ak_th = 0.;
		}

		if (i % 2 == 0)
		{
			bk_th = 0.;
		}
		else
		{
			bk_th = -4. / (i*omega*T);
		}
	

		fprintf(fin, "%10.5lf %10.5lf %10.5lf %10.5lf\n", ak[i], bk[i], ak_th, bk_th);

	}
	fclose(fin);


	delete[] t;
	delete[] f;
	delete[] ak;
	delete[] bk;
	delete[] intgr;
}

double trapez(double *x, double *y, int& n)
{
	double I = 0.;
	for (int i = 0; i < n - 1; i++)
	{
		I += ((y[i] + y[i + 1]) / 2.) * (x[i + 1] - x[i]);
	}
	return I;
}