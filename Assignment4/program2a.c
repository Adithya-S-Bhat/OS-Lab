#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
void main(){
    int fd=open("prog2.txt",O_WRONLY|O_CREAT,0);
    if(fd<0){//limits are crossed
        perror("Can't Open\n");
        exit(1);
    }
    write(fd,"",0);

    size_t size=lseek(fd,0,SEEK_END);
    printf("Size:%ld\n",size);
    close(fd);
}