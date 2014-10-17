#!/bin/sh

gcc -lm -L/usr/local/lib/cfitsio -I/usr/include/cfitsio/ -lcfitsio output.c psrfitsReader.c readfits.c -o psrfitsReader
