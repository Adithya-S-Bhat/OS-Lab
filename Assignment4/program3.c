//mimic ls command
#include<stdio.h>
#include<dirent.h>
int main(int argc,char* argv[]){
    struct dirent *de;
    //de->d_ino,d_name

    DIR *dr;
    if(argc==1)
        dr=opendir(".");
    else if(argc==2)
        dr=opendir(argv[1]);//"." = current directory
    else
        printf("Too many arguments.\n");
    //getcwd can be passed instead of "."
    if(dr==NULL){
        printf("Can't Open.\n");
        return 0;
    }

    while((de=readdir(dr))!=NULL){
        printf("%s\n",de->d_name);
    }

    closedir(dr);

    return 0;
}