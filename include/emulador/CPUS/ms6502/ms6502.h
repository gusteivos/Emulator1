
#ifndef MS_6502_H_
#define MS_6502_H_

    #include <stdint.h>
    #include <stdlib.h>

    #define MS6502_BREAK_FLAG 			(uint8_t)	0b00010000
    #define MS6502_CARRY_FLAG 			(uint8_t)	0b00000001
    #define MS6502_DECIMAL_FLAG 	    (uint8_t)	0b00001000
    #define MS6502_INTERRUPT_FLAG 		(uint8_t)	0b00000100
    #define MS6502_NEGATIVE_FLAG 		(uint8_t)	0b10000000
    #define MS6502_OVERFLOW_FLAG 		(uint8_t)	0b01000000
    #define MS6502_UNUSED_FLAG      	(uint8_t)	0b00100000
    #define MS6502_ZERO_FLAG      		(uint8_t)	0b00000010

    typedef struct MS6502_t
    {

        uint8_t  a;
        uint8_t  x;
        uint8_t  y;
        
        uint16_t pc;
        uint8_t  sp;
        uint8_t  sr;

        uint8_t  _opcode;       // Is the instruction byte
        uint8_t  _cycles;	   	// Counts how many cycles the instruction has remaining

        uint8_t (*ReadMemory )(uint16_t);

        void    (*WriteMemory)(void *, uint16_t, uint8_t);

    } MS6502;

    MS6502 *CreateNewMS6502 (void);

    void ResetMS6502    (MS6502 *);

    void SetMS6502Flag  (MS6502 *, uint8_t);

    void ClearMS6502Flag(MS6502 *, uint8_t);

#endif
