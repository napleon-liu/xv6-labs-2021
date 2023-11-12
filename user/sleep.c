#include "kernel/types.h"
#include "user/user.h"
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(2, "sleep: <usage> sleep ticks.\n");
        exit(1);
    }
    int ticks = atoi(argv[1]);
    int ret = sleep(ticks);
    exit(ret);
}