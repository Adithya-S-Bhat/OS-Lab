//soft link and hard link
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
void main(){
    int fd=open("a.txt",O_RDWR|O_CREAT,0666);
    if(fd<0){//limits are crossed
        perror("Can't Open\n");
        exit(1);
    }

    link("a.txt","link.txt");//link from a.txt to link.txt. It basically creates a hard link
    write(fd,"Hello Worl",10);
    close(fd);
}