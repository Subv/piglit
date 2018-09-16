#include <switch.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static int fd = -1;

void userAppInit()
{
    /*fd = open("piglit_output.txt", O_WRONLY | O_CREAT);
    if (!fd) {
        svcOutputDebugString("ERROR", 5);
        return;
    }

    fflush(stdout);
    dup2(fd, STDOUT_FILENO);
    fflush(stderr);*/
    consoleDebugInit(debugDevice_SVC);
    stdout = stderr;
    setenv("PIGLIT_PLATFORM", "switch_egl", 1);
}

void userAppExit()
{
    if (fd >= 0) {
        close(fd);
        fd = -1;
    }
}
