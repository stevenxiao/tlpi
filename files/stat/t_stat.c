#define _DEFAULT_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>

#include "../file_perms.h"
#include "../../include/tlpi_hdr.h"

static void diaplayStatInfo(const struct stat *sb)
{
  if(sb == NULL)
    return;
  printf("File type:            ");
  switch(sb->st_mode & S_IFMT){
    case S_IFREG: printf("regular file\n");                      break;
    case S_IFDIR: printf("directory\n");                         break;
    case S_IFCHR: printf("character device\n");                  break;
    case S_IFBLK: printf("block device\n");                      break;
    case S_IFLNK: printf("symbol (soft) link\n");                break;
    case S_IFIFO: printf("FIFO or pipe\n");                      break;
    case S_IFSOCK:printf("socket\n");                            break;
    default: printf("unkown file type?\n");                      break;
  }
  printf("Device containing i-node: major=%ld, minor=%ld\n", (long)major(sb->st_dev), (long)minor(sb->st_dev));

  printf("I-node number:      %ld\n", (long)sb->st_ino);
  printf("Mode:               %ld (%s)\n", (unsigned long)sb->st_mode, filePermStr(sb->st_mode, 0));
  if(sb->st_mode & (S_ISUID | S_ISGID | S_ISVTX))
    printf("                  special bits set:    %s%s%s\n", 
        (sb->st_mode & S_ISUID)?"set-UID ":"",
        (sb->st_mode & S_ISGID)?"set-GID ":"",
        (sb->st_mode & S_ISVTX)?"sticky ":"");
  printf("Number of (hard) links: %ld\n", (long) sb->st_nlink);
  printf("Ownership:                UID=%d, GID=%d\n", sb->st_uid, sb->st_gid);
  if(S_ISCHR(sb->st_mode) || S_ISBLK(sb->st_mode))
    printf("Device number (st_rdev): major=%ld; minor=%ld\n", (long)major(sb->st_rdev), (long)minor(sb->st_rdev));

  printf("File size:              %lld bytes\n", (long long) sb->st_size);
  printf("Optimal I/O block size: %ld bytes\n", (long) sb->st_blksize);
  printf("512B blocks allocated:  %lld\n", (long long)sb->st_blocks);
  printf("Last file access:       %s\n", ctime(&sb->st_atime));
  printf("Last file modification: %s\n", ctime(&sb->st_mtime));
  printf("Last status change:     %s\n", ctime(&sb->st_ctime));
}


int main(int argc, char *argv[])
{
  struct stat sb;
  Boolean statLink;
  int fname;

  statLink = (argc > 1) && strcmp(argv[1], "-l") == 0;

  fname = statLink ? 2: 1;

  if(fname >= argc || (argc > 1 && strcmp(argv[1], "--help") == 0))
    usageErr("%s [-l] file\n"
        "     -l = use lstat() instead of stat()\n", argv[0]);

  if(statLink){
    if(lstat(argv[fname], &sb) == -1)
      errExit("lstat");
  }else{
    if(stat(argv[fname], &sb) == -1)
      errExit("stat");
  }

  diaplayStatInfo(&sb);

  exit(EXIT_SUCCESS);
}
