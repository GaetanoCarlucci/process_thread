#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){ 
  int pid;
  int numero;
  int status = 0;
  printf( "1) prima della fork \n" );
  printf( "Inserisci numero intero: " );
  scanf("%d", &numero);

  pid = fork();
  
  printf( " 2) dopo della fork \n" );
  if (pid == 0){
    
    sleep(3);
    printf("Sono il processo figlio con PID: %d.Il mio processo padre ha pid: %d\n", getpid(), getppid());
    numero = numero + 15;
    printf("La somma nel processo figlio e' : %d\n", numero);
    exit(1) ;                              // termina il processo figlio 
  }
  else{
    printf("Sono il processo padre con PID: %d.Il mio processo padre ha pid: %d\n", getpid(), getppid());
    numero = numero + 10;
    printf("La somma nel processo padre e' : %d\n", numero);
    pid = wait(&status);
    printf("Il pid restituito da wait e' : %d\n", pid);
    printf("Lo stato restituito da wait (exit del processo figlio) e' : %d\n", status);
    exit(0) ;                              // non necessaria
  }
}