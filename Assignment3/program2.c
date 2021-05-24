/*$gcc -g -Wall -o program2 program2.c //-g to  tell compiler to include debugger info in executable
$gdb ./program2
gdb: li //list first 15 lines
br main or br 23//to introduce break point at main
run
x command is used to examine the memory
print &a->to get address
x/1dw <address>-->1dw-1 decimal word
fw->float word 1xw->1 hexadecimalword
4xb->4 hexadecimal byte
cont->to continue
(gdb)x/1xw 0x7ffffffeddb8
	0x7ffffffede18: 0x00007625
x/4xb 0xfffffffeddb8
	0x7ffffffede18: 0x25    0x76    0x00    0x00
Hence,Little Endian

Program2b x/30i main->main+instructions till 30 address
x/30x main->main+16,32,48,64,80... till 30 instructions in hexadecimal
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	int a=30245;
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
	return 0;
}

/*int main(void){
	char *binpath="/bin/ps";
	char *args[]={binpath,"-x",NULL};
	execv(args[0],args);
	return 0;
}*/