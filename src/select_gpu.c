// select_gpu: A small program to start a GPU-based process on LUMI
// setting ROCR_VISIBLE_DEVICES based on the SLURM environment variable
// SLURM_LOCALID.
//
// This version is C-based rather than the script that is also provided
// and meant to be compiled just with the system gcc, with no dependencies
// beyond glibc.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( int argc, char *argv[] )
{
 
    if (argc < 2) {
        fprintf( stderr, "Usage: %s <file-to-exec> ...\n", argv[0] );
        exit( EXIT_FAILURE );
    }

    setenv( "ROCR_VISIBLE_DEVICES", getenv( "SLURM_LOCALID" ), 1 );

    execvp( argv[1], argv + 1 );
    perror( "execvp") ;   /* execvp() returns only on error */
 
    exit(EXIT_FAILURE);

}