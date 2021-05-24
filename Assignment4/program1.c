#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>//file control
#include<sys/types.h>//file modes
#include<sys/stat.h>//file size
void main(){
    int fd=open("prog1.txt",O_RDWR|O_CREAT,0666);//try 444->nothing happens and O_RDONLY->nothing is written
    if(fd<0){//limits are crossed
        perror("Can't Open\n");
        exit(1);
    }
    char wbuf[20]="Hello World!!HI Welc";
    write(fd,wbuf,20);
    char rbuf[100];
    lseek(fd,0,SEEK_SET);
    read(fd,rbuf,5);
    write(1,rbuf,5);
    printf("\n");
    lseek(fd,-5,SEEK_END);
    read(fd,rbuf,5);
    write(1,rbuf,5);
    printf("\n");

    size_t size=lseek(fd,0,SEEK_END);
    printf("Size:%ld\n",size);
    close(fd);
}