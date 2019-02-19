// Aufg 04
#include <stdio.h>
#include <math.h>

void gauss(double *m, double *x, double *r, int n, int nax);
void tomy(int il, int iu, double *b, double *d, double *a, double *c, double *l);

void main()
{
	double xx, yy;
	int count = 0;

	FILE *fin;
	fopen_s(&fin, "aufg04_dat.dat", "r");
	do
	{
		fscanf_s(fin, "%lf %lf", &xx, &yy);
		count++;
	} while (!feof(fin)); // end-of-file
	fclose(fin);

	double *x, *y;
	x = new double[count];
	y = new double[count];

	fopen_s(&fin, "aufg04_dat.dat", "r");
	for (int i = 0; i < count; i++)
	{
		fscanf_s(fin, "%lf %lf", &x[i], &y[i]);
	}
	fclose(fin);

	/*
	// Gauss Seid
	double *RHS, *coef, *a, *r;
	RHS = new double[count];
	a = new double[count];
	r = new double[count];
	coef = new double[count*count];

	int cc = 0;
	for (int i = 0; i < count; i++)
	{
		
		RHS[i] = y[i];
		for (int j = 0; j < count; j++)
		{
			coef[cc+j] = pow(x[i], j);
		}
		coef[cc] = sqrt(x[i]);
		cc = cc + count;
	}

	// Anfangswert
	for (int i = 0; i < count; i++)
	{
		a[i] = RHS[i];
		r[i] = RHS[i];
	}
	
	int dd = 0;
	double Res;
	
	do
	{ 
		for (int i = 0; i < count; i++)
		{
			double tmp = 0;

			for (int j = 0; j < count; j++)
			{
				if (i == j) { continue; } // i should not be same as j ==!
				else { tmp = tmp + coef[dd + j]*a[i]; }
			}
			dd = dd + count;

			a[i] = (a[i] - tmp)/coef[count+i]; // []
			r[i] = a[i] - tmp;
		}

		Res = 0;
		for (int i = 0; i < count; i++)
		{
			Res = Res + pow(r[i], 2);
		}
		Res = sqrt(Res);

	} while (Res > 1e-5);

	delete[] x;
	delete[] y;
	delete[] a;
	delete[] r;
	delete[] RHS;
	delete[] coef;

	*/

	double *RHS, *coef, *a, *r;
	RHS = new double[count];
	a = new double[count];
	r = new double[count];
	coef = new double[count*count];

	int cc = 0;
	for (int i = 0; i < count; i++)
	{
		RHS[i] = y[i];
		for (int j = 0; j < count; j++)
		{
			coef[cc + j] = pow(x[i], j);
		}
		coef[cc] = sqrt(x[i]);
		cc = cc + count;
	}

	// gauss(coef, a, RHS, count, count);

	fopen_s(&fin, "aufg04_koef.dat", "w");
	for (int i = 0; i < count*count; i++)
	{
		fprintf_s(fin, "%lf \n", coef[i]);
	}
	fclose(fin);
	
	fopen_s(&fin, "aufg04_RHS.dat", "w");
	for (int i = 0; i < count; i++)
	{
		fprintf_s(fin, "%lf \n", RHS[i]);
	}
	fclose(fin);
	

	delete[] x;
	delete[] y;
	delete[] a;
	delete[] r;
	delete[] RHS;
	delete[] coef;
}

void gauss(double *m, double *x, double *r, int n, int nax)
{
	/* n - Anzahl der Zeilen bzw. Spalten des Gleichungssystems
	   nax  - Groesse der Matrix m[nax][nax]
	   x    - Loesungsvektor
	   r    - rechte Seite des Gleichungssystems  */

	int i, j, k;

	/* ERZEUGEN EINER DREIECKSMATRIX */
	for (i = 0; i <= n - 2; i++)
	{
		for (k = i + 1; k <= n - 1; k++)
		{
			for (j = i; j <= n - 1; j++)
			{
				x[j] = -m[i * nax + j] * m[k * nax + i] / m[i * nax + i]; // a21 = a21-(a11*(a21/a11))
			}

			r[k] = r[k] - r[i] * m[k * nax + i] / m[i * nax + i];

			for (j = i; j <= n - 1; j++)
			{
				m[k * nax + j] = m[k * nax + j] + x[j];
			}

		}

	}

	/*  RUECKWAERTSEINSETZEN UM x ZU ERHALTEN  */
	x[n - 1] = r[n - 1] / m[(n - 1) * nax + n - 1];
	for (i = n - 2; i >= 0; i--)
	{
		x[i] = r[i];
		for (j = i + 1; j <= n - 1; j++)
		{
			x[i] = x[i] - m[i * nax + j] * x[j];
		}

		x[i] = x[i] / m[i * nax + i];
	}


	return;

}

void tomy(int il, int iu, double *b, double *d, double *a, double *c, double *l)
{
	int m, i;

	for (i = il + 1; i <= iu; i++)
	{
		d[i] = d[i] - b[i] / d[i - 1] * a[i - 1];
		c[i] = c[i] - b[i] / d[i - 1] * c[i - 1];
	}

	l[iu] = c[iu] / d[iu];
	for (i = 1; i <= (iu - il); i++)
	{
		m = iu - i;
		l[m] = (c[m] - a[m] * l[m + 1]) / d[m];
	}

	return;

}