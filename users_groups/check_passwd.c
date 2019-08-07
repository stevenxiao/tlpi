#define _DEFAULT_SOURCE             // Get getpass() declaration from <unistd.h>           
#define _XOPEN_SOURCE               // Get crypt() declaration from <unistd.h>
#define _GNU_SOURCE                 // Get getresuid() and getresgid() declaration from <unistd.h>

#include <unistd.h>
#include <limits.h>
#include <pwd.h>
#include <shadow.h>

#include "../include/tlpi_hdr.h"


int main(int argc, char *argv[])
{
  char *username, *password, *encrypted, *p;

  struct passwd *pwd;
  struct spwd   *spwd;

  Boolean authOk;

  size_t len;
  long lnmax;

  uid_t uid, euid, suid;
  gid_t gid, egid, sgid;
  
  if(getresuid(&uid, &euid, &suid) == -1)
    errExit("getresuid");

  printf("ruid: %ld, euid: %ld, suid: %ld\n", (long)uid, (long)euid, (long)suid);
  if(getresgid(&gid, &egid, &sgid) == -1)
    errExit("getresgid");
  printf("rgid: %ld, egid: %ld, sgid: %ld\n", (long)gid, (long)egid, (long)sgid);

  lnmax = sysconf(_SC_LOGIN_NAME_MAX);
  if(lnmax == -1)
    lnmax = 256;

  username = malloc(lnmax);
  if(username == NULL)
    errExit("malloc");

  printf("Username: ");
  fflush(stdout);

  if(fgets(username, lnmax, stdin) == NULL)
    exit(EXIT_FAILURE);

  len = strlen(username);
  if(username[len-1] == '\n')
    username[len-1] = '\0';

  pwd = getpwnam(username);
  if(pwd == NULL)
    fatal("could not get password record");

  spwd = getspnam(username);
  if(spwd == NULL && errno == EACCES)
    fatal("no permission to read shadow password file");
  
  if(spwd != NULL)
    pwd->pw_passwd = spwd->sp_pwdp;

  password = getpass("Password: ");
  
  encrypted = crypt(password, pwd->pw_passwd);

  for(p = password; *p != '\0';)
    *p++ = '\0';

  if(encrypted == NULL)
    errExit("crypt");

  authOk = strcmp(encrypted, pwd->pw_passwd) == 0;
  if(!authOk){
    printf("Incorrect password\n");
    exit(EXIT_FAILURE);
  }

  printf("Successful authenticated: UID = %ld\n",(long)pwd->pw_uid);

  exit(EXIT_SUCCESS);
}

