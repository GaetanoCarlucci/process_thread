#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void *processo_leggero(void * arg) {       // codice che esegue il thread 
  pthread_t tid;
  tid = pthread_self();    // ritorna identificato del thread (il valore di ptid)
  sleep(1);
  printf("Sono il thread  %d del processo pesante: %d\n", tid, getpid());
  int *retValue = malloc(sizeof(int)); // Allocare una porzione di memoria condivisa 
  *retValue = 5;                       // inserire in questa area di memoria un valore a piacimento
  pthread_exit(retValue);              // restituire tramite la funzione pthred_exit l’indirizzo di questa area di memoria
}

int main (){
  pthread_t TID;         // identificatore thread alla creazione 
  void *status;
  printf ("Il pid del processo pesante e': %d\n", getpid ());
  pthread_create (&TID, NULL, &processo_leggero, NULL);
  printf ("Il thread che ho creato ha TID: %d \n", TID );
  pthread_join(TID, &status);
  int* retValue = (int*)status;
  printf("Il valore di ritorno restituito dal thread è: %d\n", *retValue );
  return 0;
}