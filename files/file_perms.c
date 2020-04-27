#include "file_perms.h"
#include <stdio.h>
#include <sys/stat.h>

#define STR_SIZE sizeof("rwxrwxrwx")

char *filePermStr(mode_t mode, int flags)
{
  static char str[STR_SIZE];
  snprintf(str, STR_SIZE, "%c%c%c%c%c%c%c%c%c",
           (mode & S_IRUSR) ? 'r' : '-', (mode & S_IWUSR) ? 'w' : '-',
           (mode & S_IXUSR) ? (((mode & S_ISUID) && (flags & FP_SPECIAL)) ? 's' : 'x') : (((mode & S_ISUID) && (flags & FP_SPECIAL)) ? 'S' : '-'),
           (mode & S_IRGRP) ? 'r' : '-', (mode & S_IWGRP) ? 'w' : '-',
           (mode & S_IXGRP) ? (((mode & S_ISGID) && (flags & FP_SPECIAL)) ? 's' : 'x') : (((mode & S_ISGID) && (flags & FP_SPECIAL)) ? 'S' : '-'),
           (mode & S_IROTH) ? 'r' : '-', (mode & S_IWOTH) ? 'w' : '-',
           (mode & S_IXOTH) ? (((mode & S_ISVTX) && (flags & FP_SPECIAL)) ? 't' : 'x') : (((mode & S_ISVTX) && (flags & FP_SPECIAL)) ? 'T' : '-'));
  return str;
}
