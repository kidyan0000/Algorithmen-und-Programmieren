// GAUSSS SEIDEL ALGORITHM

#include<math.h>
#include<stdio.h>

void main()
{
	double M[5][5], RHS[5], x[5];

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


//	return(0);
}