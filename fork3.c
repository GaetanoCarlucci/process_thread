#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NRFIGLI 5

int main(){ 
  int pid, x;
  for (x= 0; x < NRFIGLI; x++)  { 
    pid = fork();                            // creo processo figlio 
    printf( "Sono il processo con pid: %d.\n", getpid() );

  } 
  sleep(3);
  printf( "Sono il processo padre di tutti gli altri processi con pid:%d.\n", getpid() );
  return 0;
} 