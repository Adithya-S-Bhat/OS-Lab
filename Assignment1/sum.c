#include<stdio.h>
void main(int argc,char* argv[]){
    int sum=0,n,num;
    char *j;
    for(int i=1;i<argc;i++){
        j=argv[i];
        num=0;
        while(*(j)!='\0'){
            n=(*j)-'0';
            num=num*10+n;
            j++;
        }
        sum+=num;
    }
    printf("%d\n",sum);
}