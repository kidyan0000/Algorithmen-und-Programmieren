#include <stdio.h>
#include <math.h>

void main()
{
	FILE *fin;
	fopen_s(&fin, "review.dat", "r");
	double xx, yy;
	int count = 0;
	do
	{
		fscanf_s(fin, "%lf %lf \n", &xx, &yy);
	    count++;
	} while (!feof(fin));
	fclose(fin);

	double *x, *y;
	x = new double[count];
	y = new double[count];

	fopen_s(&fin, "review.dat", "r");
	for (int i = 0; i < count; i++)
	{
		fscanf_s(fin, "%lf %lf \n", &x[i], &y[i]);
	}
	fclose(fin);

	fopen_s(&fin, "_review.dat", "w");
	for (int i = 0; i < count; i++)
	{
		fprintf_s(fin, "%lf %lf \n", x[i], y[i]);
	}
	fclose(fin);

	// newton
	double v = 1.;
	double w = pow(v,2);
	
	do
	{
		double w_abl = 2.*v;
		v = v - w/w_abl;
		w = pow(v,2);
	}while(fabs(w)>1.e-8);
	printf_s("%lf \n", v);

	
	// Runge Kutta
	/*
	FILE *fin;
	fopen_s(&fin, "aufg05.dat", "w");
	int count = 0;
	v = 0;
	do
	{
		v1 = v; // not add deltaT
		a1 = g - ((cw1*rho / 2 * v1*v1*A) / m);
		
		v2 = v + a1 * dt / 2;
		a2 = g - ((cw1*rho / 2 * v2*v2*A) / m);

		v3 = v + a2 * dt / 2;
		a3 = g - ((cw1*rho / 2 * v3*v3*A) / m);

		v4 = v + a3 * dt;
		a4 = g - ((cw1*rho / 2 * v4*v4*A) / m);

		kz = 1. / 6. * (v1 + 2 * v2 + 2 * v3 + v4); // ./.
		kv = 1. / 6. * (a1 + 2 * a2 + 2 * a3 + a4);

		H = H - kz * dt; // need both H and v
		v = v + kv * dt;

		fprintf_s(fin, "%lf %lf \n", v, H);
		
		count++;

	} while (H > H2);

	*/
	/*
	for(int i=1; i<=m_zeit; i++){
		// Implizite FDM
		// Koeffizienten des Gleichungssystems
		for (int j=0; j<m; j++){
			aa[j] = bb[j] = -a * dt/(dx*dx);
			dd[j] = 1. + 2. * a *dt/(dx*dx) + alpha * u/(rho * A * c) * dt;
			RHS[j] = alpha * u * dt / (rho * A * c) * Tu + T_old[j];
		}
		// Randbedingungen
		aa[0] = 0.;
		bb[0] = 0.;
		dd[0] = 1.;
		RHS[0] = Ta;
		aa[m-1] = 0.;
		bb[m-1] = 0.;
		dd[m-1] = 1.;
		RHS[m-1] = Tu;
		// Gleichungssystem lösen
		tomy(0, m-1, bb, dd, aa, RHS, T_new);
		
		for(int j=0; j<m; j++){
			T_old[j] = T_new[j];
			fprintf(james, "%20.7lf", T_new[j]);
		}
		fprintf(james, "\n");
	}*/
	/*
		for(int i=0; i<n; i++)
	{
		d[i] = -2.;
		a[i] = 1.;
		b[i] = 1.;
		x[i] = i*dx;
		RHS[i] = (q0*l*x[i]*dx*dx) / (E*J*6.) + (pow(x[i]/l, 2) - 1.);
	}
	tomy (1, n-2, b, d, a, RHS, w);
	w[0] = 0.;
	w[n-1] = 0.;
	*/
	
	
	
	scanf_s(" ");

	delete[] x;
	delete[] y;

}