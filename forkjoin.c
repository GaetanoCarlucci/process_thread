#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int calcoli_figlio1(){
  int k;
  printf("1.1 elab. parallela processo figlio \n");
  k = 3 + 2;
  return k; 
} 

int calcoli_padre1(){
  int k;
  printf("1 elab. parallela processo padre \n");
  k = 6 - 2;
  return k; 
} 

int calcoli_finali_padre(int a, int b){
  int k;
  printf("2 elab. finale padre \n");
  k = (a * b);
  return k; 
} 
  
int main( ){ 
  int x = 0, y = 0 , z= 0 , status = 0;
  int pid;
  pid = fork();                       // inizio elaborazione parallela 
  if (pid == 0){    
    // chiamare la funzione che esegue i calcoli del processo figlio e lo scrive nella variabile x

    // far restituire alla exit il risultato dell'operazione, la variabile x
    
   }
  else{
    // chiamare la funzione che esegue i calcoli del processo padre e lo scrive nella variabile y

   }
  printf(".. join: padre aspetta \n");
  // join : il padre aspetta il figlio... quale funzione devi usare? suggerimento: non esiste la funzione join

  // leggere solo il byte piu' significativo della variabile status che continere il valore restituito dal processo figlio
  x = status;                        
  // suggerimento: eseguire uno shift di status a sinistra di 8 posizioni
  x = status >> 8;
  // chiamare la funzione che esegue il calcolo finale e lo scrive in z
  printf("-> risultato finale z = %d \n", z );
}