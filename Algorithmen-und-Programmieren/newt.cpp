// NEWTON VERFAHREN

#include<math.h>
#include<stdio.h>

void main()
{

	double A_AS = 2., dm = 0.001, eps = 1.e-8;
	bool is_supersonic = false;
	int i=0;

	if (is_supersonic == false)
	{

		// UNTERSCHALL
		do {

			i++;
			double M = i * dm;
			double F = A_AS - 1. / M * pow(1. + 1. / 6.*(M*M - 1), 3);


		} while ( F<0.);
		
		double w = 1. + 1. / 6.*(M*M - 1);
		double Fs = w * w * (1./(M*M)*w-1.);
		double Mn = M - F / Fs;
		
		M = Mn;
		F = A_AS - 1. / M * pow(1. + 1. / 6.*(M*M - 1), 3);
		Fs = w * w * (1. / (M*M)*w - 1.);
	}
	else
	{
		// UEBERSCHALL

	}
}