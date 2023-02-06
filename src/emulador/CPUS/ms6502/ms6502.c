#include <emulador/CPUS/ms6502/ms6502.h>

MS6502 *CreateNewMS6502()
{
    
    MS6502 *_output_value = malloc(sizeof(MS6502 *));

    if (_output_value == NULL) goto _end_of_function;

    _output_value->a = 0x00;
    _output_value->x = 0x00;
    _output_value->y = 0x00;

    _output_value->program_counter  = 0x0000;
    _output_value->stack_pointer    = 0x00;
    _output_value->status          |= MS6502_INTERRUPT_FLAG;

    _output_value->fetched          = 0x00;
    _output_value->temp             = 0x00;
    _output_value->addr_abs         = 0x00;
    _output_value->addr_rel         = 0x00;
    _output_value->opcode           = 0x00;
    _output_value->clock_count      = 0x00;
    _output_value->clock_count      = 0x00;

    _output_value->ReadMemory   = NULL;

    _output_value->WriteMemory  = NULL;

_end_of_function:

    return _output_value;

}

void ResetMS6502(MS6502 *cpu)
{
    
    cpu->program_counter = ((uint16_t)cpu->ReadMemory(0xFFFC) | (uint16_t)cpu->ReadMemory(0xFFFD) << 8);

    cpu->stack_pointer = 0xFF;

	cpu->status |= MS6502_INTERRUPT_FLAG;

}
