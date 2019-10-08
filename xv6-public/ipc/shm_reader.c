#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int key = 27; //numero usado para generar el id del bloque de memoria
    int shmid = shmget(key,100,IPC_CREAT);           //regresa la direccion de id y aqui lo agarra |   IPC_CREAT si no existe lo crea (el id)

    char *word;

    word = (char *)shmat(shmid, NULL, 0); //regresa la direccion de bloque  //si es diferente de 0 es solo lectura

    printf("Lo que hay en la memoria es: %s\n",word);
    word[0] = '*';  //indicar que ya lo leyo

    return 0;
}