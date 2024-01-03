#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){ 
  int pid1 ,pid2;
  pid1 = fork();  // creo primo processo figlio 
  pid2 = fork();  // creo secondo processo figlio 
  if ((pid1 == 0) || (pid2 == 0)){
    printf("Sono il processo figlio con PID: %d\n", getpid());
    printf("Il mio processo padre ha pid: %d\n", getppid());
    exit(1) ;               // termina il processo figlio 
  }
  else{
    printf("Sono il processo padre con pid: %d\n", getpid());
    sleep(2); // sleep per non creare processi orfani
    exit(0) ;
  }
}