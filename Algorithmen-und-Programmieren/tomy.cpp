void tomy (int il, int iu, double *b, double *d,
			   double *a, double *c, double *l)
{
int m, i;

for( i=il+1; i<=iu; i++)
{
     d[i] = d[i] - b[i]/d[i-1] * a[i-1];
     c[i] = c[i] - b[i]/d[i-1] * c[i-1];
}

l[iu] = c[iu]/d[iu];
for( i=1; i <= (iu-il); i++)
{
     m = iu - i;
     l[m] = (c[m] - a[m] * l[m+1])/d[m];
}

return;

}
