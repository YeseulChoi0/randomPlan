#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include  <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "header.h"
//#include "randomGen.c"

int main(){
  int array[10];
  printf("Generating random numbers\n");

  int i;
  int currentNum;
  for (i = 0; i < 10; i++) {
    currentNum = genRandom();
    array[i] = currentNum;
    printf("random %d: %d\n", i, currentNum);
  }

  printf("\nWriting numbers to file...\n\n");
  int file = open("file", O_CREAT | O_WRONLY, 0644);
  if(errno){
    printf("Error #: %d\n", errno);
    printf("error message %s\n", strerror(errno));
  }
  write(file, &array, sizeof(array));

  int newArray[10];
  int newFile = open("file", O_RDONLY, 0644);
  if(errno){
    printf("Error #: %d\n", errno);
    printf("error message %s\n", strerror(errno));
  }
  printf("Reading numbers from file...\n\n");
  read(newFile, &newArray, sizeof(array));


  printf("Verification that written values were the same:\n\n");
  for (i = 0; i < 10; i++) {
    printf("random %d: %d\n", i, newArray[i]);
  }
}
