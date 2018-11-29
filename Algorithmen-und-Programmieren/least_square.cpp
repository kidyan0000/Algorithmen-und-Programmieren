//Least Square Approximation

#include<math.h>
#include<stdio.h>

void gauss(double *m, double *x, double *r, int n, int nax);

void main()
{
	double sx, sy;
	double *M, *x, *y, *RHS, *a; //double ist der Datentypen von Inhalt
	int m = 0;
	int n = 5; //n ist Polynomgrad

	FILE *fin;
	fopen_s(&fin, "xy.dat", "r");
	//fin = fopn("xy.dat","r");
	
	//Berechnen wie viel Zeile stehen in Daten
	do
	{
		m++; //m = m + 1
		fscanf_s(fin, "%lf %lf\n", &sx, &sy);
	} while (!feof(fin));
	
	fclose(fin);

	//Arrays anliegen
	M = new double[(n + 1)*(n + 1)];
	RHS = new double[n + 1];
	a = new double[n + 1];
	x = new double[m];
	y = new double[m];
	

	fopen_s(&fin, "xy.dat", "r");
	for (int i = 0; i <= m - 1; i++)
	{
		fscanf_s(fin, "%lf %lf\n", &x[i], &y[i]);
	}
	fclose(fin);
	

	for (int i = 0; i <= n; i++) //Ueber alle Zeilen
	{
		for (int j = 0; j <= n; j++) //Ueber alle Spalten
		{
			M[j + i * (n + 1)] = 0.;
			for (int k = 0; k <= m - 1; k++)
			{
				//M[j + i * (n + 1)] = M[j + i * (n + 1)] + ...
				M[j + i * (n + 1)] += pow(x[k], i)*pow(x[k], j);
			
			}
		}
	}

	for (int i = 0; i <= n; i++) //RHS ueber alle Spalten
	{
		RHS[i] = 0.;
		for (int k = 0; k <= m - 1; k++)
		{
			RHS[i] += y[k] * pow(x[k], i);
		}
	}

	gauss(M, a, RHS, n + 1, n + 1);

	for (int i = 0; i <= n; i++)
	{
		printf("%10.6lf \n", a[i]);
	}

	printf("%5i\n", m); //Aufruf der Konsole 
	scanf_s("%i", &m); //Aufruf der Eingabe &m

	delete[] M;
	delete[] RHS;
	delete[] a;
	delete[] x;
	delete[] y;

}