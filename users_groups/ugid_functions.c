#include <pwd.h>
#include <grp.h>
#include <ctype.h>

#include "../include/tlpi_hdr.h"


char *userNameFromId(uid_t uid)
{
  struct passwd *pwd;

  pwd = getpwuid(uid);

  return (pwd == NULL)? NULL:pwd->pw_name;
}


uid_t userIdFromName(char *name)
{
  struct passwd *pwd;
  uid_t u;

  char *endptr;

  if(name == NULL || *name == '\0')
    return -1;

  u = strtol(name, &endptr, 10);
  if(*endptr == '\0')
    return u;

  pwd = getpwnam(name);
  if(pwd == NULL)
    return -1;

  return pwd->pw_uid;
}


char *groupNameFromId(gid_t gid)
{
  struct group *grp;

  grp = getgrgid(gid);
  return (grp == NULL)?NULL:grp->gr_name;
}

gid_t groupIdFromName(char *name)
{
  if(name == NULL || *name == '\0')
    return -1;

  struct group *grp;

  gid_t g;
  char *endptr;

  g = strtol(name, &endptr, 10);
  if(*endptr == '\0')
    return g;

  grp = getgrnam(name);
  if(grp == NULL)
    return -1;
  return grp->gr_gid;
}
