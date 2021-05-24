#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main(){
    /*touch filename
    >ls -l filename
        -rw-rw-r--
    chmod u+s filename//setting super user privilige
    >ls -l filename
        -rwSrw-r--
    chmod u+x filename//current logged in user gets the permission
    >ls -l filename
        -rwsrw-r--
    //S vs s difference
    >ls -l /bin/mount
    >ls -l /bin/umount
        -rwsr-xr-x
    chmod g+s filename
    >ls -l filename
        -rwsrwSr--
    
    create another user in the system try setting setuid to one user and check if another user can access

    S-only super user can execute
    s-the user who owns the file can execute
    */
    return 0;
}