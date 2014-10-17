// read psrfits information
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "psrfitsReader.h"

int main (int argc, char *argv[])
{
	int h,i,j,k;

	/*
	if (argc != 8)
	{
		printf ("Usage: ptime_time -f fname\n"
	            "Read psrfits info\n");
	    exit (0);
	}
	*/


	//////////////////////////////////////////////////////
	char fname[128];   // name of data file
	int tmode; // to distinguish different type of algorithm

	int index, n;
	for (i=0;i<argc;i++)
    {
		if (strcmp(argv[i],"-f") == 0)
		{
            index = i + 1;
			n = 0;
			while ( (index + n) < argc )
			{
				n++;
		    }
			//strcpy(fname,argv[++i]);
		}
    }

	// name of different extension of data files
	char name_data[50]; 
	char name_predict[50]; 
	char name_psrparam[50]; 

	char data[] = "[SUBINT]";
	char predict[] = "[T2PREDICT]";
	char psrparam[] = "[PSRPARAM]";

	/////////////////////////////////////////////////////////////////////////////////
	// start to deal with different data file
	for (k = index; k < index + n; k++)
	{
		// get the data file name
		strcpy(fname,argv[k]);
		printf ("%s\n", fname);

		// name of different extension
		strcpy(name_data,fname);
		strcpy(name_predict,fname);
		strcpy(name_psrparam,fname);

		strcat(name_data, data);
		strcat(name_predict, predict);
		strcat(name_psrparam, psrparam);

		////////////////////////////////////////////////////
	
		double psrfreq;
		psrfreq = read_psrfreq(name_psrparam);
		//printf ("%.15lf\n", psrfreq);
	
		////////////////////////////////////////////////
		long int imjd, smjd;
		double offs;
		int nphase;
		int nchn;
		int nsub;
		int npol;
	
		imjd = stt_imjd(fname);
		smjd = stt_smjd(fname);
		offs = stt_offs(fname);

		nchn = get_nchan(name_data);	
		npol = get_npol(name_data);	
		nsub = get_subint(name_data);	
		nphase = get_nphase(name_data);	

		//printf ("%d\n", nchn);
		////////////////////////////////////////////////
		// subint
		for (h = 1; h <= nsub; h++)
		{
				output (name_data, h, imjd, smjd, offs);
		}
	}

	return 0;
}
