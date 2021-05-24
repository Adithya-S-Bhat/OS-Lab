#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#define MSG_SIZE 32
void main(){
    int fd[2],pid;
    char inbuf[MSG_SIZE];
    if(pipe(fd)<0)
        exit(1);
    pid=fork();
    if(pid<0)
        printf("Forking failed.");
    else if(pid==0){
        write(fd[1],"Message sent from child process",MSG_SIZE);
    }
    else{
        wait(NULL);
        read(fd[0],inbuf,MSG_SIZE);
        printf("%s\n",inbuf);
    }
}