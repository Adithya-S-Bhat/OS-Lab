#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define BUFFER_SIZE 5
int counter=0,in=0,out=0,buffer[BUFFER_SIZE],i=0;
sem_t mutex,full,empty;

void *consumer(void *param){
    while(1){
        sem_wait(&full); // wait until full > 0 and then decrement 'full'
        sem_wait(&mutex);
        while(counter==0);
        int next_consumed=buffer[out];
        out=(out+1)%BUFFER_SIZE;
        counter--;
        printf("Consumed item: %d\n",next_consumed);
        sem_post(&mutex);
        sem_post(&empty);//increment empty
    }
}
void *producer(void *param){
    while(i<10){
        int next_produced=random();
        sem_wait(&empty); //wait until empty > 0 and then decrement 'empty' 
        sem_wait(&mutex);
        while(counter==BUFFER_SIZE);//wait
        buffer[in]=next_produced;
        in=(in+1)%BUFFER_SIZE;
        counter++;
        printf("Produced item: %d\n",next_produced);
        sem_post(&mutex);
        sem_post(&full);//increment full
        i++;
    }
}
void main(){
    pthread_t tid[2];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,BUFFER_SIZE);

    pthread_create(&tid[0],&attr,producer,NULL);
    pthread_create(&tid[1],&attr,consumer,NULL);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
}