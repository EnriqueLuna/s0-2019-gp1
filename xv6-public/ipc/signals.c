#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int forever =1;

void signalHandler(int sgn){
    printf("RECEIVED SIGNAL: %d\n", sgn);
    forever=0;                  //para volver a donde estabamos de while
}

int main(){
    int pid;
    signal(10,signalHandler);   //para que agarre la señal del padre
    pid=fork();
    if(pid == 0){                //soy el hijo
        //signal(10,signalHandler); se pone antes para garantizar que le llega la señal bien
        printf("Soy el hijo\n");
        //Codigo que quiero que haga el hijo
        while(forever){}         //cuando despierta el padre ya tiene la señal
        printf("Salgo del ciclo infinito\n");
    }else{
        printf("Soy el proceso padre y mi hijo es : %d\n",pid);
        sleep(5);               //para que duerma 5 seg para garantizar que al despertar mandar la señal
        kill(pid,10);
                                //codigo padre
        for(;;){}
    }
}