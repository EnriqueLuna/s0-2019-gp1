#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int num = 0;

    fprintf(stderr, "Imprimir nums primos del 1 al 100 \n");

  while(1){
    int cnt=0;

    scanf("%d\n",&num);//noten que leo de stdout

    if(num == -1){
      break;
    }

    for(int i=1; i<100; i++){
        if(num %i == 0){
            cnt++;
        }
    }
    if(cnt==2){
        fprintf(stderr,"%d\n",num);
    }

  }

  fprintf(stderr, "completado\n");

}
