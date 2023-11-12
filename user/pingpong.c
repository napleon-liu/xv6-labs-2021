#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        fprintf(2, "<usage>: pingpong");
    }

    int fd1[2], fd2[2];
    char *buf = "a";
    pipe(fd1);
    pipe(fd2);

    int ret = fork();

    if (ret == 0)
    {
        int pid = getpid();
        close(fd1[1]);
        close(fd2[0]);
        read(fd1[0], buf, 1);
        printf("%d, received ping\n", pid);
        write(fd2[1], buf, 1);
        exit(0);
    }
    else
    {
        int pid = getpid();
        close(fd1[0]);
        close(fd2[1]);
        write(fd1[1], buf, 1);
        read(fd2[0], buf, 1);
        printf("%d, received pong\n", pid);
        exit(0);
    }
}