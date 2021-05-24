#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void main(){
	int pid=fork();
	if(pid<0)
		printf("Fork failed.");
	else if(pid==0){//child process
		execl("/bin/touch","touch","abc.txt",NULL);
	}
	else{//Parent Process
		wait(NULL);
		execlp("/bin/ls","ls",NULL);
	}
}