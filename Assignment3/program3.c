//Compile with gcc -pthread program3.c
/*
objdump -M intel -D a.out | grep -A20 main.:  --> memaddress(in hex):hexadecimalinstruction assembly
gdb - q ./a.out
break main
run
info registers
rax,rbx,rcx,rdx->accumulator,base,counter,data regs
rsi,rdi,rbp,rsp --> stack & destination index,base and source pointer
r8-r15 general purpose
rip-instruction pointer

gdb -q ./a.out
disassemble main
break main
run
info register rip
nexti or x/1i $rip
*/ 
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int *a;
    int size;
}arrayparam;
float average=0,maximum=0,minimum=0;
int n=3;
void *avg(void *params){
    arrayparam *param=params;
    int sum=0;
    for(int i=0;i<param->size;i++){
        sum+=param->a[i];
    }
    average=sum/(param->size);
    pthread_exit(0);
}
void *max(void *params){
    arrayparam *param=params;
    maximum=param->a[0];
    for(int i=1;i<param->size;i++){
        if(param->a[i]>maximum)
            maximum=param->a[i];
    }
    pthread_exit(0);
}

void *min(void *params){
    arrayparam *param=params;
    minimum=param->a[0];
    for(int i=1;i<param->size;i++){
        if(param->a[i]<minimum)
            minimum=param->a[i];
    }
    pthread_exit(0);
}
void main(){
    pthread_t tid[3];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int param_arr[]={10,30,45};
    arrayparam arr;
    arr.a=param_arr;
    arr.size=3;
    printf("The array is: ");
    for(int i=0;i<arr.size;i++){
        printf("%d ",arr.a[i]);
    }
    printf("\n");
    pthread_create(&tid[0],&attr,avg,&arr);
    pthread_join(tid[0],NULL);
    printf("The average is: %.2f\n",average);
    pthread_create(&tid[1],&attr,max,&arr);
    pthread_join(tid[1],NULL);
    printf("The maximum is: %.2f\n",maximum);
    pthread_create(&tid[2],&attr,min,&arr);
    pthread_join(tid[2],NULL);
    printf("The minimum is: %.2f\n",minimum);
}