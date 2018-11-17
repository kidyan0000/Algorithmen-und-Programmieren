// TRAPEZREGEL //

#include<math.h>
#include<stdio.h>

// PROTOTPY //
double trapez( double *x; double *y, int n);

void main()
{
  printf("%10.4lf/n", I);
  scanf_s("%i",&n);
  
  int n = 100;
  double *x, *y, dx, a = -5, b = 7, I=0;
  x = new double[ n ]; // n  Speicherplaetze allokieren // 
  y = new double[ n ]; 
  dx = (b - a) / (n - 1);
  
  for( int i=0; i<=n-1; i=i+1)
  {
	  x[i] = a + dx * i;
	  y[i] = x[i] * x[i];
  }
  
  I = trapez( x, y, n);
  
  /* 
  x[0] = 7.0;
  x[1] = 8.9;
  x[3] = 9.0;
  x[4] = 7.0;
  x[5] = 8.9;
  */
  
  delete[] x;
  delete[] y;
}

double trapez( double *x; double *y, int n)
{

  double I=0;
  
  for( int i=0; i<=n-2; i++)
  {
	  I = I + ( y[i] + y[i+2] )/2. * (x[i+1] - x[i]);
  }
  
  
  /* 
  x[0] = 7.0;
  x[1] = 8.9;
  x[3] = 9.0;
  x[4] = 7.0;
  x[5] = 8.9;
  */
  
  return(I);
}

