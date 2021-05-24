//1a -->size ./a.out
//bss- global variables
/*For 1b:-
$gcc -c program1.c//Compile/assemble source files without linking
$ld program1.o -lc --print-map>map.txt
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int a;
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