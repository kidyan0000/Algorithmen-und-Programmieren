// Ak01
#include <cmath>
#include <stdio.h>

double integ(double *x, double *q, int n);
void main()
{
	// Teil a
	double xx, qq;
	double l = 1.0;
	int count = 0;

	FILE *fin;
	fopen_s(&fin, "STRECKENLAST.dat", "r");
	do
	{
		fscanf_s(fin, "%lf %lf \n", &xx, &qq);
		count++;

	} while (!feof(fin));
	fclose(fin); // close nicht vergessen

	fopen_s(&fin, "STRECKENLAST.dat", "r");
	double *x, *q;
	x = new double[count];
	q = new double[count];

	for (int i = 0; i < count; i++)
	{
		fscanf_s(fin, "%lf %lf \n", &x[i], &q[i]);

	}
	fclose(fin);

	fopen_s(&fin, "Ak1.dat", "w");
	for (int i = 0; i < count; i++)
	{
		fprintf_s(fin, "%10.5lf %10.5lf \n", x[i], q[i]);
	}
	fclose(fin);

	// Teil b
	// Kraft: Fa+Fb-q*l=0
	// Moment q*x*x/2-Fb*l=0

	// Teil c


	double F_a, F_b;
	
	
	// Brechung von F_b
	double *qx;
	qx = new double[count];
	for (int i = 0; i < count; i++)
	{
		qx[i] = q[i] * x[i];
	}

	double I_2;
	I_2 = integ(x, qx, count);
	F_b = I_2 / l;

	// Berechung von F_a
	double I;
	I = integ(x, q, count);
	F_a = I - F_b;

	printf_s("%10.5lf %10.5lf", F_a, F_b);
	scanf_s(" ");


	delete[] qx;
	delete[] x;
	delete[] q;
}

double integ(double *x, double *q, int n)
{
	// Numerische Integration mittels Trapezregel

	double res = 0.0;
	double dx = abs(x[0] - x[1]);

	for (int i = 0; i < n - 1; i++) {
		res = res + dx * q[i] + 0.5*dx*(q[i + 1] - q[i]);
	}

	return res;
}