/* execve.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    char *newargv[] = { NULL, NULL };

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    newargv[0] = argv[1];

    // putenv( "HELLOWORLD=Hello, My Little World!" );
    setenv( "HELLOWORLD", "Hello, My Little Little World!", 1 );

    printf( "Starting \"%s\" with execv:\n", argv[1] );
    fflush( stdout );

    execv( argv[1], newargv );
    perror("execve");   /* execve() returns only on error */
    exit(EXIT_FAILURE);
}