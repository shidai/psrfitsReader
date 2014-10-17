#include <string.h>
#include <stdlib.h>
#include <math.h>
//#include <gsl/gsl_rng.h>
//#include <gsl/gsl_randist.h>
#include "psrfitsReader.h"
//#include "nrutil.h"
#define ITMAX 100000  // Maximum allowed number of iterations.
#define EPS 1.0e-16 // Machine double floating-point precision.
//#define EPS 3.0e-8 // Machine floating-point precision.
#define SIGN(a,b) ((b) >= 0.0 ? fabs(a) : -fabs(a))
double pi=3.1415926;

int output (char *name_data, int subint, long int imjd, long int smjd, double offs)
{
	int h;
	h = subint;
	double offset;

	offset = read_offs(name_data, h);

  printf ("%s %d %d %lf %lf\n", name_data, imjd, smjd, offs, offset);

	return 0;
}

