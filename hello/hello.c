#include <stdio.h>  //busca la libreria en el sistema
#include "./libhello.h" //busca la libreria local


int main (int argc, char **argv){

    int i;
    for(i=1; i<argc; i++){
    printHello(argv[i]);
    }


    //al poner return arriba de otro le dices al SO que algo falló
    return 0;
}