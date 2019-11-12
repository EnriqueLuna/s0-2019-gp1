#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char **argv){
    char *file1 = argv[1];
    char *pwd = getcwd(NULL,0);     //me regresa la cadena

    char path1[strlen(file1) + strlen(pwd) + 2];    //path y para que termine la cadena +2

    sprintf(path1,"%s/%s",pwd,file1); 
    printf("pwd %s\n",path1);

    unlink(path1);

}