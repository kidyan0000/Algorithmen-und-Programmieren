#include <math.h>
#include <stdio.h>

void grenzschicht(double *y, double *u, int n, double U);
double integ(double *y, double *u, int n);

void main()
{
	double *y, *u, *u_2, U;
	double delta, theta;
	int n;
	double H_vor = 10.0;
	double delta = 1;

	n = 100;

	double dy = delta / (n - 1);

	y = new double[n];
	u = new double[n];
	u_2 = new double[n];

	for (int i = 0; i < n; i++)
	{
		y[i] = i * dy;
	}

	// berechnen die Geschwindigkeitsprofil
	double U = 0.5; // Anfangswert willkuerlich
	// double U1=0.5, U2=0.7;
	
	double H_vor = 2.5;
	
	// Anfangsbedingung
	grenzschicht(y, u, n, U); // y, u sind Zeiger
				  // andersfall int x -> &x
	

	// calculate the u^2
	for (int i = 0; i < n; i++)
	{
		u_2[i] = u[i] * u[i];
	}

	double I = integ(y, u, n);
	double I_2 = integ(y, u_2, n);

	// H need to be initialized
	H = (delta - (I / U)) / ((I / U) - (I_2 / (U*U)));
	// H1 H2
	
	
	
	// Newton Raphson Method
	
	do
	{
		grenzschicht(y, u, n, U); // y, u sind Zeiger
						  // andersfall int x -> &x
		// grenz(u1,U1);
		// grenz(u2,U2);

		// calculate the u^2
		for (int i = 0; i < n; i++)
		{
			u_2[i] = u[i] * u[i];
		}

		I = integ(y, u, n);
		I_2 = integ(y, u_2, n);
		// I_1,I_2, I2_1, I2_2;
		// H1; H2
			
		dH = ((U*U*delta*I) - (2 * U*delta*I_2) + (I*I_2)) / ((I*U - I_2)*(I*U - I_2));
		// dH = (H1-H2)/(U1-U2);
		// U3 = U2 - H2/dH;
		// U2 = U3; U1 = U2;
		// H2 = H3; H1 = H2;
		
		U = -H/dH + U; 
		
		H = (delta - (I / U)) / ((I / U) - (I_2 / (U*U))); // update der H
		// H3 = f(U3);


	} while (abs(H-H_vor) > 1e-5); // abs values!


	delete[] y;
	delete[] u;
	delete[] u_2;
}