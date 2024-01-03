#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){ 
  int pid1 ,pid2;
  pid1 = fork();  // creo primo processo figlio 
  if ((pid1 == 0)){
    printf("Sono il primo processo figlio con PID: %d\n", getpid());
    printf("Il mio processo padre ha pid: %d\n", getppid());
    exit(1) ;               // termina il processo figlio 
  }
  else{
    printf("Sono il processo padre con pid: %d\n", getpid());
    pid2 = fork();  // creo secondo processo figlio 
    if ((pid2 == 0)){
      printf("Sono il secondo processo figlio con PID: %d\n", getpid());
      printf("Il mio processo padre ha pid: %d\n", getppid());
      exit(2) ;               // termina il processo figlio 
    }
  sleep(2); // sleep per non creare processi orfani
  exit(0) ;
  }
}