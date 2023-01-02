/* execve.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
 
    if (argc < 2) {
        fprintf( stderr, "Usage: %s <file-to-exec> ...\n", argv[0] );
        exit( EXIT_FAILURE );
    }

    execvp( argv[1], argv + 1 );
    perror( "execvp") ;   /* execvp() returns only on error */
    exit(EXIT_FAILURE);
}