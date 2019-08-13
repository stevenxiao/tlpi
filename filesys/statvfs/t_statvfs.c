#include <sys/statvfs.h>

#include "../../include/tlpi_hdr.h"


static void usageError(const char *progName)
{
  fprintf(stderr, "%s filepath\n\n", progName);
  exit(EXIT_FAILURE);
}


int main(int argc, char *argv[])
{
  struct statvfs stv;
  if(argc != 2)
    usageError(argv[0]);

  memset(&stv, 0, sizeof(struct statvfs));

  if(statvfs(argv[1], &stv) == -1)
    errExit("statvfs");


  printf("f_fbsize:    %ld\n", stv.f_bsize);
  printf("f_frsize:    %ld\n", stv.f_frsize);
  printf("f_blocks:    %ld\n", stv.f_blocks);
  printf("f_bfree:     %ld\n", stv.f_bfree);
  printf("f_bavail:    %ld\n", stv.f_bavail);
  printf("f_files:     %ld\n", stv.f_files);
  printf("f_ffree:     %ld\n", stv.f_ffree);
  printf("f_favail:    %ld\n", stv.f_favail);
  printf("f_fsid:      %ld\n", stv.f_fsid);
  printf("f_flag:      %ld\n", stv.f_flag);
  printf("f_namemax:   %ld\n", stv.f_namemax);
  exit(EXIT_SUCCESS);
  
}
