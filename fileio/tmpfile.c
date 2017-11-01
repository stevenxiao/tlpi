#include <stdlib.h>
#include "../include/tlpi_hdr.h"

int
main(int argc, char *argv[])
{
    int fd;

    char template[] = "/tmp/somestringXXXXXXXXX";
    fd = mkstemp(template);
    if(fd == -1)
        errExit("mkstemp");
    printf("Generated filename was: %s\n", template);
    unlink(template);

    if(close(fd) == -1)
        errExit("close");

    exit(EXIT_SUCCESS);

}
