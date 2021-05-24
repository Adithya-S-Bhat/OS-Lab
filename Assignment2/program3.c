#include<stdio.h>
#define N 5//No. of processes
#define M 3//No. of resources
void main(){
    int available[M]={0,0,0};//indicates the number of available resources of each type
    int allocation[N][M]={{0,1,0},
                {2,0,0},
                {3,0,3},
                {2,1,1},
                {0,0,2}};//An n x m matrix defines the number of resources of each type currently allocated to each process
    int request[N][M]={{0,0,0},
            {2,0,2},
            {0,0,1},
            {1,0,0},
            {0,0,2}};//An n x m matrix indicates the current request of each process. If Request [i][j] = k, then process Pi is requesting k more instances of resource type Rj

    int work[M];
    for(int i=0;i<M;i++)
        work[i]=available[i];
    int finish[N];
    int i,k;
    for(i=0;i<N;i++){
        k=0;
        for(int j=0;j<M;j++){
            if(allocation[i][j]!=0){
                finish[i]=0;
                k=1;
                break;
            }
        }
        if(k==0)
            finish[i]=1;
    }

    step2:
    for(i=0;i<N;i++){
        if(finish[i]==0){
            k=0;
            for(int j=0;j<M;j++)
                if(request[i][j]>work[j]){
                    k=1;
                    break;
                }
            if(k==0)
                break;
        }
    }

    if(i<N){
        printf("Process %d executed.\n",i);
        for(int j=0;j<M;j++)
            work[j]=work[j]+allocation[i][j];
        finish[i]=1;
        goto step2;
    }

    else{
        for(i=0;i<N;i++){
            if(finish[i]==0){
                printf("Deadlock detected and Process");
                printf(" P%d ",i);
                printf(" is deadlocked.\n");
            }
        }
    }
}