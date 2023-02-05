/*
 * xargs.c
 */

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"

#define MAX 100

int main(int argc,char* argv[]) {
    char *cur[MAX];//Store the parameters of exec
    char buf[20];
    int i=0,j=0;
    for (i = 0; i <argc-1; i++) {//save parameters
        cur[i] = argv[i+1];
    }
    cur[i]=malloc(512);
    while ((read(0, buf, 1)==1)) {
        if (i == argc - 1)
            printf("%s,%s\n", buf, cur[i]);
        switch (buf[0]){
            case '\n': {
                if (fork() == 0) {
                    exec(cur[0], cur);
                    exit(0);
                } else
                    wait(0);
                for(int n=argc-1;n<=i;n++){
                    memset(cur[n],0,512);
                    free(cur[n]);
                }
                i=argc-1;
                cur[i]=malloc(512);
                j=0;
                break;
            }
            case ' ':{
                i++;
                j=0;
                if(i<MAXARG)
                    cur[i]=malloc(512);
                break;
            }
            default:{
                cur[i][j++]=buf[0];
                break;
            }
        }

    }
    exit(0);
}
