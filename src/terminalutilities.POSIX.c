
#ifndef _WIN32

    #include <terminalutilities.h>
    #include <sys/ioctl.h>
    #include <unistd.h>
    #include <stdio.h>

    void ClearTerminal()                                 { fprintf(stdout, "\033[2J"); }

    void SetTerminalCursorPosition(int32_t x, int32_t y) { fprintf(stdout, "\033[%d;%dH", (int16_t)x, (int16_t)y); }

#endif