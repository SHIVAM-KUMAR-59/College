// WAP to show the usability of fprintf, fscanf, write, read, system and sprintf, strtok function 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>

int main(){

    // system("pwd");

    // fprintf(stdout,"Hello World\n");

    // int i;
    // fscanf(stdin,"%d",&i);

    // char str[] = "Hello World";
    // char *token = strtok(str," ");
    // while(token != NULL){
    //     printf("%s\n",token);""
    //     token = strtok(NULL," ");
    // }

    // write(1, "Hello 2\0", 6);
    char a[5];
    read(0, a, sizeof(int));
    printf("%s\n",a);
    return 0;
}