#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include  <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int genRandom(){
  int fd = open("/dev/random", O_RDONLY, 0644);
  if(errno){
    printf("Error #: %d\n", errno);
    printf("error message %s\n", strerror(errno));
  }
  int save;
  read(fd, &save, sizeof(int));
  return save;
}
