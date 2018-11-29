// GAUSSS SEIDEL ALGORITHM

#include<math.h>
#include<stdio.h>

int main()
{
	double M[5][5], RHS[5], x[5];
	double residuum, eps = 1.e-8;

	M[0][0] = 7.;
	M[0][1] = 4.;
	M[0][2] = 1.;
	M[0][3] = 1.;
	M[0][4] = 0.;

	M[1][0] = 1.;
	M[1][1] = 8.;
	M[1][2] = 2.;
	M[1][3] = 1.;
	M[1][4] = 1.;

	M[2][0] = 2.;
	M[2][1] = 3.;
	M[2][2] = 9.;
	M[2][3] = 0.;
	M[2][4] = 2.;

	M[3][0] = 0.;
	M[3][1] = 3.;
	M[3][2] = 1.;
	M[3][3] = 6.;
	M[3][4] = 1.;

	M[4][0] = 2.;
	M[4][1] = 1.;
	M[4][2] = 2.;
	M[4][3] = 3.;
	M[4][4] = 9.;

	RHS[0] = 1.;
	RHS[1] = 4.;
	RHS[2] = 3.;
	RHS[3] = 0.;
	RHS[4] = 5.;

	int n = 5;
	// GUESS THE VECTOR OF SOLVER
	for (int i = 0; i <= n - 1; i++)
	{
		x[i] = 0.;
	}

	do { //INTERATIONS - LOOP
		for (int i = 0; i <= n - 1; i++) //Loop for all equations
		{
			x[i] = RHS[i];

			for (int j = 0; j <= n - 1; j++)
			{
				if (i == j) continue; // do not the following, but still in the loop
				x[i] = RHS[i] - M[i][j] * x[j];
			}
			// if break, jump to here. Break the loop 
			x[i] = x[i] / M[i][i];
		}
		
		residuum = 0.;
		for (int i = 0; i <= n - 1; i++) //Loop for all equations
		{
			double r = RHS[i];
			for (int j = 0; j <= n - 1; j++)
			{
				r = r - M[i][j] * x[j];
			}
			residuum = residuum + r * r;
			
		}
		
		residuum = sqrt(residuum);
		
		printf("%20.5lf\n", residuum);


	} while (residuum > eps);
	
	for (int i = 0; i <= n; i++)
	{
	    printf("%10.5lf\n", x[i]);
	}

	scanf_s("%i", &n);
    return(7);
}