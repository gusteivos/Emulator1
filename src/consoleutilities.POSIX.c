
#ifndef _WIN32

    #include <consoleutilities.h>
    #include <sys/ioctl.h>
    #include <unistd.h>
    #include <stdio.h>

    void Ut_ClearConsole()                                 { fprintf(stdout, "\033[2J"); }

    void Ut_SetConsoleCursorPosition(int32_t x, int32_t y) { fprintf(stdout, "\033[%d;%dH", (int16_t)x, (int16_t)y); }

#endif