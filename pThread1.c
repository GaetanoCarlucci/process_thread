#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *processo_leggero(void * arg) {       // codice che esegue il thread 
  pthread_t tid;
  tid = pthread_self();    // ritorna identificato del thread (il valore di ptid)
  printf("Sono il thread  %i  del processo pesante: %i\n", tid, getpid());
}

int main (){
  pthread_t TID;         // identificatore thread alla creazione 
  printf ("Il pid del processo pesante e': %i\n", getpid ());
  pthread_create (&TID, NULL, &processo_leggero, NULL);
  printf ("Il thread che ho creato ha TID: %i \n", TID );
  return 0;
}