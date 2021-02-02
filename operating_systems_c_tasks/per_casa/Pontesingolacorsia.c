#ifndef _MULTI_THREADED
	#define _MULTI_THREADED
#endif
#ifndef _POSIX_C_SOURCE
	#define _POSIX_C_SOURCE 200112L
#endif


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <inttypes.h>


#define NUMMACCHINE 5

int turnoDestra = 0;
int turnoSinistra = 0;
int turno=0;

/* variabili per la sincronizzazione */
pthread_mutex_t  mutex;
pthread_cond_t   condDestra, condSinistra;


void *MacchinaDestra (void *arg)
{

  while(1) {
      pthread_mutex_lock(&mutex);

      while (turnoDestra!=(int)((intptr_t)arg) || turno!=0) {
        printf("Macchina %d proveniente da destra in wait\n", (int)((intptr_t)arg));
        pthread_cond_wait(&condDestra,&mutex);
        if (turnoDestra!=(int)((intptr_t)arg))
           pthread_cond_signal(&condDestra);
      }

      printf("Macchina %d proveniente da destra transita\n", (int)((intptr_t)arg));
      sleep(1);


      if (turnoDestra==4) {
        turnoDestra=0;
        turno=1;
        pthread_cond_signal(&condSinistra);
      } else {
        pthread_cond_signal(&condDestra);
        turnoDestra++;
      }

      pthread_mutex_unlock(&mutex);



  }

    pthread_exit((void*) 0);

}

void *MacchinaSinistra (void *arg)
{
  while(1) {
      pthread_mutex_lock(&mutex);

      while (turnoSinistra!=(int)((intptr_t)arg) || turno!=1) {
        pthread_cond_wait(&condSinistra,&mutex);
        if (turnoSinistra!=(int)((intptr_t)arg))
           pthread_cond_signal(&condSinistra);
      }

      printf("Macchina %d proveniente da sinistra transita\n", (int)((intptr_t)arg));
      sleep(1);

      if (turnoSinistra==4) {
        pthread_cond_signal(&condDestra);
        turnoSinistra=0;
        turno=0;
      } else {
        pthread_cond_signal(&condSinistra);
        turnoSinistra++;
      }


      pthread_mutex_unlock(&mutex);

  }

  pthread_exit((void*) 0);

}


int main ()
{
  int i;
  void *ptr;

	pthread_t pt1[NUMMACCHINE];
  pthread_t pt2[NUMMACCHINE];
  pthread_mutex_init(&mutex,NULL);
  pthread_cond_init(&condDestra,NULL);
  pthread_cond_init(&condSinistra,NULL);

  for(i=0; i<NUMMACCHINE ; i++) {
    pthread_create(&pt1[i],NULL,MacchinaDestra, (void*)((intptr_t)i));
  }

  for(i=0; i<NUMMACCHINE ; i++) {
    pthread_create(&pt2[i],NULL,MacchinaSinistra, (void*)((intptr_t)i));
  }

  for(i=0; i<NUMMACCHINE; i++) {
    pthread_join(pt1[i], &ptr);
  }

  for(i=0; i<NUMMACCHINE; i++) {
    pthread_join(pt2[i], &ptr);
  }

  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&condDestra);
  pthread_cond_destroy(&condSinistra);

  pthread_exit(NULL);

  return 0;

}
