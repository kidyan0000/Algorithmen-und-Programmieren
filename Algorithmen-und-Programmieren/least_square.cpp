//Least Square Approximation

#include<math.h>
#include<stdio.h>

void main()
{
	double sx, sy;
	double *m
	int m = 0, n = 5;//Polynom ordnung

	FILE *fin;
	fopen_s(&fin, "xy.dat", "r");
	//fin = fopn("xy.dat","r");
	
	do
	{
		m++; //m = m + 1
		fscanf_s(fin, "%lf %lf\n", &sx, &sy);
	} while (!feof(fin));
	
	fclose(fin);

	M = new double[n*n];

	for (int i = 0; i <= n; i++) //Ueber alle Zeilen
	{

	}

	printf("%5i\n", m);
	scanf("%i", m);

	delete M[]

}