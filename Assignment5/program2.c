/*
Access Control List
mkdir d1
cd d1
touch c.txt
cd ..
>getfacl d1/c.txt
    #file:d1/c.txt
    #owner: ubuntu
    #group:ubuntu
    user::rw-
    group::rw-
    other::r--
>setfacl -m u:ubuntu:r-x d1/c.txt//-m=modify
>getfacl d1/c.txt
    #file:d1/c.txt
    #owner: ubuntu
    #group:ubuntu
    user::rw-
    user:ubuntu:r-x
    group::rw-
    mask::rwx
    other::r--

1) To add permission for user
setfacl -m "u:user:permissions" /path/to/file
2) To allow all files or directories to inherit ACL entries from the directory it is within
setfacl -dm "entry" /path/to/dir
3) To remove a specific entry
setfacl -x "entry" /path/to/file
4) To show permissions:
getfacl filename
5) To remove the set ACL permissions,
use setfacl command with -b option.
*/