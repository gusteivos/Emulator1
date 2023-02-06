#include <CPUS/ms6502/ms6502.h>

MS6502 *CreateNewMS6502()
{
    
    MS6502 *_output_value = malloc(sizeof(MS6502 *));

    if (_output_value == NULL) goto _end_of_function;

    _output_value->a    = 0x00;
    _output_value->x    = 0x00;
    _output_value->y    = 0x00;

    _output_value->pc   = 0x0000;
    _output_value->sp   = 0x00;
    _output_value->sr  |= MS6502_INTERRUPT_FLAG;

    _output_value->ReadMemory   = NULL;

    _output_value->WriteMemory  = NULL;

_end_of_function:

    return _output_value;

}

void ResetMS6502(MS6502 *cpu)
{
    
    cpu->pc     = 0xFFFC;

    cpu->pc     = ((uint16_t)cpu->ReadMemory(cpu->pc) | (uint16_t)cpu->ReadMemory(0xFFFD) << 8);

    cpu->sp     = 0xFD;

	cpu->sr    |= MS6502_UNUSED_FLAG;

}

void SetMS6502Flag  (MS6502 *cpu, uint8_t flag)
{

    if (cpu == NULL) return;

    cpu->sr |= flag;

}

void ClearMS6502Flag(MS6502 *cpu, uint8_t flag)
{

    if (cpu == NULL) return;

    cpu->sr &= ~flag;

}
