#include <math.h>
#include <stdio.h>

void main()
{
	double x0 = 1.; // Anfangswert
	double y, x;
	do
	{
		do
		{
			x = x0;
			y = -pow(x, 5) - 40.*pow(x, 2) + x + 7.;
			
			double y_abl = -5.*pow(x, 4) - 80 * x + 1.;
			double dx = y / y_abl;
			
			x0 = x - dx;

			y = -pow(x0, 5) - 40.*pow(x0, 2) + x0 + 7.; // calculate the residuum


			printf_s("%lf %lf \n", y, x0);
		

		} while (fabs(y) > 1.e-8); // abs value
	} while (x0 < 0 || x0 >1);

	scanf_s(" ");
}