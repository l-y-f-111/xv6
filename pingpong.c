//Lab: Xv6 and Unix utilities
//
//pingpong.c

#include "kernel/types.h"
#include "user/user.h"

int main(int argc,char *argv[]){
    int fd_child[2];//child -> parent
    int fd_parent[2];//parent -> child
    int pid;
    char buffer[20];
    pipe(fd_child);
    pipe(fd_parent);
    pid = fork();
    if(pid==0){//child
        read(fd_parent[0],buffer,sizeof(buffer));
        fprintf(2,"%d: received ping\n",getpid());
        write(fd_child[1],buffer, sizeof(buffer));
        exit(0);
    }
    write(fd_parent[1],buffer, sizeof(buffer));
    wait(0);
    read(fd_child[0],buffer, sizeof(buffer));
    fprintf(2,"%d: received pong\n",getpid());
    exit(0);
}
