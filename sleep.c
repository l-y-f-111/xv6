//Lab: Xv6 and Unix utilities

//sleep.c
#include "kernel/types.h"
#include "user/user.h"


int main(int arc, char *argv[]) {
    //arc 传入参数的数量
    //argv数组包含程序名字作为其第一个元素,argv[0]
    if (arc != 2)//传参错误
    {
        fprintf(2,"Error:pass arguments\n");
        exit(1);
    }
    int time = atoi(argv[1]);
    sleep(time);//休眠
    exit(0);

}

