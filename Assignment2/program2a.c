#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define BUFFER_SIZE 5
int counter=0,in=0,out=0,buffer[BUFFER_SIZE];
int i=0;
void *consumer(void *param){
    while(1){
        while(counter==0);
        int next_consumed=buffer[out];
        out=(out+1)%BUFFER_SIZE;
        counter--;
        printf("Consumed item: %d\n",next_consumed);
    }
}
void *producer(void *param){
    while(i<10){
        int next_produced=random();
        while(counter==BUFFER_SIZE);//wait
        buffer[in]=next_produced;
        in=(in+1)%BUFFER_SIZE;
        counter++;
        printf("Produced item: %d\n",next_produced);
        i++;
    }
}
void main(){
    pthread_t tid[2];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid[0],&attr,producer,NULL);
    pthread_create(&tid[1],&attr,consumer,NULL);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
}