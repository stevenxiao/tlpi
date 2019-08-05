#include <stdio.h>

#include "curr_time.h"


int main(int argc, char *argv[])
{
  char *s = currTime("%F");
  printf("%s\n", s);


  s = currTime(NULL);
  printf("%s\n", s);

  return 0;
}
