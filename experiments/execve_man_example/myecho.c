/* myecho.c */

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{

    printf( "Currently executing myecho.x\n" );

    for (int j = 0; j < argc; j++)
        printf("argv[%d]: %s\n", j, argv[j]);

    exit(EXIT_SUCCESS);
}
           