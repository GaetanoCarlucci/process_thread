#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NRFIGLI 5

int main(){ 
  int pid, x;
  int status;
  for (x= 0; x < NRFIGLI; x++)  { 
    pid = fork();                            // creo processo figlio 
    if (pid == 0){
      printf( " Sono il processo figlio con pid:%d.", getpid() );
      sleep(2);
      printf( " Il mio processo padre ha pid: %d\n", getppid());
      exit(1);                              // termina il processo figlio 
    }
    else{
      //INSERISCI IN MODO OPPORTUNO LA FUNZIONE WAITPID AL FIDE DI CREARE UN FIGLIO ALLA VOLTA
    }
  } 
  printf( "Sono il processo padre di tutti gli altri processi con pid:%d.\n", getpid() );
  return 0;
} 