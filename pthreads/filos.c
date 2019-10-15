#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define NUM_FILOS 5 //numeros de filosofos
pthread_mutex_t forks[NUM_FILOS]; //arreglo con el numero de filosofos

void actions(){
    sleep(1 + rand()%5);
}

void * life(void *ptId){
    long tid;
    tid = (long)ptId;
    srand(time(NULL) + tid);//como corre en paralelo ese time es nuestro tiempo de reloj

    while(1){
        //pensar
        printf("voy a pensar un rato %ld\n",tid);
        actions();
        printf("tengo hambre %ld\n",tid);

        if(tid%2 ==0){
            pthread_mutex_lock(&forks[tid]);    //el & es para la direccion de tid y modificar el original, sin & modifica copia
                printf("ya tengo el tenedor derecho %ld\n",tid);
            pthread_mutex_lock(&forks[(tid+1)%NUM_FILOS]);    //para cuando este en el 5 se regresa al 1
                printf("ya tengo el tenedor izquierdo %ld\n",tid);
                //comer
                printf("COMER %ld\n",tid);
                actions();
                //despues regreso los forks
                printf("regreso los tenedores %ld\n",tid);
            pthread_mutex_unlock(&forks[tid]);
            pthread_mutex_unlock(&forks[(tid+1)%NUM_FILOS]);
        }
        else{
            pthread_mutex_lock(&forks[(tid+1)%NUM_FILOS]);
                printf("ya tengo el tenedor izquierdo %ld\n",tid);
            pthread_mutex_unlock(&forks[tid]);
                printf("ya tengo el tenedor derecho %ld\n",tid);
                //comer
                printf("COMER %ld\n",tid);
                actions();
                //despues regreso los forks
                printf("regreso los tenedores %ld\n",tid);
            pthread_mutex_unlock(&forks[tid]);
            pthread_mutex_unlock(&forks[(tid+1)%NUM_FILOS]);
        }
    }
}

int main(){
     pthread_t threads[NUM_FILOS];//se crea arreglo de los hilos
   int rc;
   long t;
   for(t=0;t<NUM_FILOS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, life, (void *)t);   //se ejecuta la funcion para crear hilos
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
    }
    /* Last thing that main() should do */
   pthread_exit(NULL);//checa que todos se hayan terminado
}