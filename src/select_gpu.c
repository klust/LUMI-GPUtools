// select_gpu: A small program to start a GPU-based process on LUMI
// setting ROCR_VISIBLE_DEVICES based on the SLURM environment variable
// SLURM_LOCALID.
//
// This version is C-based rather than the script that is also provided
// and meant to be compiled just with the system gcc, with no dependencies
// beyond glibc.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MIN_GPU 0
#ifndef MAX_GPU
#define MAX_GPU 7
#endif

int main( int argc, char *argv[] )
{
 
    if (argc < 2) {
        fprintf( stderr, "Usage: %s <file-to-exec> ...\n", argv[0] );
        exit( EXIT_FAILURE );
    }

    // Get SLURM_LOCALID
    char * const slurm_localid = getenv( "SLURM_LOCALID" );
    if ( (void *) slurm_localid == NULL ) {
        fprintf( stderr, "select_gpu: The environment variable SLURM_LOCALID cannot be found.\n" \
                 "This command is meant to be used with srun as SLURM_LOCALID determines which GPU " \
                 "will be selected.\n");
        exit( EXIT_FAILURE );
    }

    // Check if SLURM_LOCALID is a valid integer.
    const int slurm_localid_value = atoi( slurm_localid );
    char slurm_localid_reconstruct[21];  // Should be enough for a 64-bit integer and terminating null.

    sprintf( slurm_localid_reconstruct, "%d", slurm_localid_value );
    if ( ( strlen( slurm_localid ) != strlen( slurm_localid_reconstruct ) ) || 
         ( strcmp( slurm_localid, slurm_localid_reconstruct ) != 0 ) ) {
        fprintf( stderr, "select_cpu: The value '%s' of SLURM_LOCALID is invalid. "
                 "A number between %d and %d is expected.\n", slurm_localid, MIN_GPU, MAX_GPU );
        exit( EXIT_FAILURE );
    }

    if ( ( slurm_localid_value < MIN_GPU ) || ( slurm_localid_value > MAX_GPU ) ) {
        fprintf( stderr, "select_cpu: The value '%s' of SLURM_LOCALID is invalid. "
                 "A number between %d and %d is expected.\n", slurm_localid, MIN_GPU, MAX_GPU );
        exit( EXIT_FAILURE );
    }

    // Set ROCR_VISIBLE_DEVICES and start the given executable.
    setenv( "ROCR_VISIBLE_DEVICES", slurm_localid, 1 );

    execvp( argv[1], argv + 1 );

    // This code will only be executed if execvp returns, i.e., if it fails to start
    // the new process.
    fprintf( stderr, "seledct_gpu: Failed to start %s\n", argv[1] );
    exit(EXIT_FAILURE);

}