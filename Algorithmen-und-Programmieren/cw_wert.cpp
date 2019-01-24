//PROGRAMM CW-Wert

#include<math.h>

double cwert( double Re )
{
	double cw;

	if( Re <= 1000 )
	{
		cw = 24./Re * ( 1. + 1./6. * pow( Re, 2./3. ) );
	}

	if( ( Re > 1000 ) && ( Re <= 3.5e5 ) )
	{
		cw = 0.424;
	}

	if( Re > 3.5e5 )
	{
		cw = 0.09;
	}

	return( cw );
}
