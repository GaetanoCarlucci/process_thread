#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){ 
  int pid;
  printf( "1) prima della fork \n" );
  //COMMENTARE IL COMANDO FORK. COSA SUCCEDE SECONDO TE?
  pid = fork();                            // creo processo figlio 
  printf( " 2) dopo della fork \n" );
  if (pid == 0){
    sleep(3);
    printf(" 3) sono il processo figlio con pid:%d.", getpid());
    printf(" Il mio processo padre ha pid: %d\n", getppid());
    exit(1);                              // termina il processo figlio 
  }
  else{
    printf(" 3) sono il processo padre pid:%d.", getpid());
    printf(" Il mio processo padre ha pid: %d\n", getppid());
    exit(0) ;                              // non necessaria
  }
}