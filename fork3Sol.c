#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NRFIGLI 5

int main(){ 
  int pid, x;
  for (x= 0; x < NRFIGLI; x++)  { 
    pid = fork();                            // creo processo figlio 
    if (pid == 0){
      printf( " Sono il processo figlio con pid:%d.", getpid() );
      printf( " Il mio processo padre ha pid: %d\n", getppid());
      exit(1) ;                              // termina il processo figlio 
    }
  } 
  sleep(2);
  printf( "Sono il processo padre di tutti gli altri processi con pid:%d.\n", getpid() );
  return 0;
} 