#ifndef TLPI_HDR_H
#define TLPI_HDR_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "get_num.h"

#include "error_functions.h"

typedef enum { FALSE, TRUE } Boolean;

#define min(m, n) ((m) < (n) ? (m) : (n))
#define max(m, n) ((m) > (n) ? (m) : (n))

#endif
