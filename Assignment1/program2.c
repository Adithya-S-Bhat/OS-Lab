#include<stdio.h>
#include<unistd.h>
//#include<sys/types.h>
#include<sys/wait.h>
void main(int argc,char* argv[]){
	int pid=fork();
	if(pid<0)
		printf("Fork failed.");
	else if(pid==0){//child process
        execl("/mnt/c/Users/adith/Documents/4th Sem OS/Assignment1/sum.out","sum.out",argv[1],argv[2],NULL);
	}
	else{//Parent Process
		wait(NULL);
		printf("Inside parent process and child has finished execution\n");
	}
}