#include <emulador/CPUS/ms6502/ms6502.h>

MS6502 *CreateNewMS6502()
{
    
    MS6502 *new_ms6502 = malloc(sizeof(MS6502 *));

    new_ms6502->ReadMemory   = NULL;
    new_ms6502->WriteMemory  = NULL;

    return new_ms6502;

}

void ResetMS6502(MS6502 *cpu)
{
    
    cpu->program_counter = ((uint16_t)cpu->ReadMemory(0xFFFC) | (uint16_t)cpu->ReadMemory(0xFFFD) << 8);

    cpu->stack_pointer = 0xFF;

	cpu->status |= I;

}
