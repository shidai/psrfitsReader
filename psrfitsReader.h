#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//#include <gsl/gsl_rng.h>
//#include <gsl/gsl_randist.h>
#include "fitsio.h"
//#include "ptime.h"

#define NP 2048
#define PI 3.14159265359

long int stt_imjd ( char *name );
long int stt_smjd ( char *name );
double stt_offs ( char *name );

int get_nchan ( char *name );
int get_npol ( char *name );
int get_nphase ( char *name );
int get_subint ( char *name );


int read_prof ( char *name, int subint, double *profile, int phase );


int print_t2pred ( char *name );
double read_offs ( char *name, int subint);
int read_freq ( char *name, int subint, double *freq, int nchan );
int read_wts ( char *name, int subint, double *wts, int nchan );

double read_psrfreq ( char *name );

int readfile ( char *filename, int *ntxt, double *x, double *y );

int output (char *name_data, int subint, long int imjd, long int smjd, double offs);
