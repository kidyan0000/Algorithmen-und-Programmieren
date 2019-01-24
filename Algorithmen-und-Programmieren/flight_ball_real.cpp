// BAHNKURVEBERECHNUNG

#include <math.h>
#include <stdio.h>

double cwert(double Re);

void main()
{
	// problemgroesse
	double C0 = 30., alpha = 45., rho = 1.225, mu = 1.7e-5, d = 0.21, m = 0.225, g=9.81;
	double cw = 0.0;
	double dt = 0.005;
	double pi;

	pi = 2. * acos(0.);

	int n = 10000;

	double k1x, k1z, k1u, k1w;
	double k2x, k2z, k2u, k2w;
	double k3x, k3z, k3u, k3w;
	double k4x, k4z, k4u, k4w;
	double kx, kz, ku, kw;

	// pointer fuer die arrays
	double *x, *z, *u, *w, *t;
	x = new double[n];
	z = new double[n];
	u = new double[n];
	w = new double[n];
	t = new double[n];

	// anfangsbedingungen
	x[0] = 0.; 
	z[0] = 0.; 
	t[0] = 0.;
	u[0] = C0 * cos(alpha*pi / 180.);
	w[0] = C0 * sin(alpha*pi / 180.);

	int cc = 0;
	do
	{

		cc++;

		t[cc] = t[cc - 1] + dt;
		
		// 1.Zeitschritt
		double C = sqrt(pow(u[cc - 1], 2) + pow(w[cc - 1], 2));
		double Re = rho * C*d / mu;

		cw = cwert(Re);

		k1x = u[cc - 1];
		k1z = w[cc - 1];
		k1u = -cw * rho / 8.*pi / m * d*d*u[cc - 1] * sqrt(pow(u[cc - 1], 2) + pow(w[cc - 1], 2));
		k1w = -cw * rho / 8.*pi / m * d*d*w[cc - 1] * sqrt(pow(u[cc - 1], 2) + pow(w[cc - 1], 2)) - g;

		// 2.Zeitschritt
		k2x = u[cc - 1] + k1u * dt / 2.;
		k2z = w[cc - 1] + k1w * dt / 2.;

		C = sqrt(pow(k2x, 2) + pow(k2z, 2));
		Re = rho * C*d / mu;

		cw = cwert(Re);

		k2u = -cw * rho / 8.*pi / m * d*d*(u[cc - 1] + k1u * dt / 2.) * sqrt(pow((u[cc - 1] + k1u * dt / 2.), 2) + pow((w[cc - 1] + k1w * dt / 2.), 2));
		k2w = -cw * rho / 8.*pi / m * d*d*(w[cc - 1] + k1w * dt / 2.) * sqrt(pow((u[cc - 1] + k1u * dt / 2.), 2) + pow((w[cc - 1] + k1w * dt / 2.), 2)) - g;

		// 3.Zeitschritt
		k3x = u[cc - 1] + k2u * dt / 2.;
		k3z = w[cc - 1] + k2w * dt / 2.;

		C = sqrt(pow(k3x, 2) + pow(k3z, 2));
		Re = rho * C*d / mu;

		cw = cwert(Re);
		
		k3u = -cw * rho / 8.*pi / m * d*d*(u[cc - 1] + k2u * dt / 2.) * sqrt(pow((u[cc - 1] + k2u * dt / 2.), 2) + pow((w[cc - 1] + k2w * dt / 2.), 2));
		k3w = -cw * rho / 8.*pi / m * d*d*(w[cc - 1] + k2w * dt / 2.) * sqrt(pow((u[cc - 1] + k2u * dt / 2.), 2) + pow((w[cc - 1] + k2w * dt / 2.), 2)) - g;

		// 4. Zeitschritt
		k4x = u[cc - 1] + k3u * dt;
		k4z = w[cc - 1] + k3w * dt;

		C = sqrt(pow(k4x, 2) + pow(k4z, 2));
		Re = rho * C*d / mu;

		cw = cwert(Re);

		k4u = -cw * rho / 8.*pi / m * d*d*(u[cc - 1] + k3u * dt) * sqrt(pow((u[cc - 1] + k3u * dt), 2) + pow((w[cc - 1] + k3w * dt), 2));
		k4w = -cw * rho / 8.*pi / m * d*d*(w[cc - 1] + k3w * dt) * sqrt(pow((u[cc - 1] + k3u * dt), 2) + pow((w[cc - 1] + k3w * dt), 2)) - g;

		kx = (k1x + 2.*k2x + 2.*k3x + k4x) / 6.;
		kz = (k1z + 2.*k2z + 2.*k3z + k4z) / 6.;
		ku = (k1u + 2.*k2u + 2.*k3u + k4u) / 6.;
		kw = (k1w + 2.*k2w + 2.*k3w + k4w) / 6.;
		
		x[cc] = x[cc - 1] + kx * dt;
		u[cc] = u[cc - 1] + ku * dt;
		z[cc] = z[cc - 1] + kz * dt;
		w[cc] = w[cc - 1] + kw * dt;

	} while ((cc <= n - 1) && (z[cc] > 0.));

	FILE *fin;
	fopen_s(&fin, "flug_real.dat", "w");
	for (int i = 0; i <= cc - 1; i++)
	{
		fprintf_s(fin, "%15.10f %15.10f %15.10f %15.10f %15.10f \n", t[i], x[i], z[i], u[i], w[i]);
	}
	fclose(fin);

	delete[] x;
	delete[] z;
	delete[] u;
	delete[] w;
	delete[] t;

}