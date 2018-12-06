// NEWTON VERFAHREN

#include<math.h>
#include<cmath>
#include<stdio.h>

void main()
{

	double A_AS = 2., dm = 0.001, eps = 1.e-8;
	bool is_supersonic = false;
	double M, F, Mn, Fs;
	int i=0;

	if (is_supersonic == false)
	{

		// UNTERSCHALL
		do {

			i++;
			M = i * dm;
			F = A_AS - 1. / M * pow(1. + 1. / 6.*(M*M - 1), 3);


		} while ( F > 0.);

	}
	else
	{
		// UEBERSCHALL

		do {

			i++;
			M = 1 + i * dm;
			F = A_AS - 1. / M * pow(1. + 1. / 6.*(M*M - 1), 3);


		} while (F < 0.);




	}

	do {
		double w = 1. + 1. / 6.*(M*M - 1);
		Fs = w * w * (1. / (M*M)*w - 1.);
		Mn = M - F / Fs; // 

		M = Mn;
		F = A_AS - 1. / M * pow(1. + 1. / 6.*(M*M - 1), 3);
		// Fs = w * w * (1. / (M*M)*w - 1.);
	} while (abs(F) > eps);

	printf("MACHZAHL = %lf6.4\n", M);
	scanf_s("%i\n", i);
}