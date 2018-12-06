// NEWTON VERFAHREN

#include<math.h>
#include<stdio.h>

void main()
{

	double A_AS = 2., dm = 0.001;
	bool is_supersonic = false;
	int i;

	if (is_supersonic == false)
	{

		// UNTERSCHALL
		do {

			i++;
			double M = i * dm;
			double F = A_AS - 1. / M * pow(1. + 1. / 6.*(M*M - 1), 3);


		} while ( F<0.);
	}
	else
	{
		// UEBERSCHALL

	}
}