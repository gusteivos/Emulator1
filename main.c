
#include <emulador/CPUS/ms6502/ms6502.h>
#include <terminalutilities.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_t main(int32_t argument_count, char *argument_values[])
{

    ClearTerminal();

    MS6502 *cpu = CreateNewMS6502();

    SetMS6502Flag(cpu, MS6502_CARRY_FLAG);

    if (cpu->sr >= 127)
    {

        printf("oky \n");

    }
    else
        printf("not \n");

    return 0;

}
