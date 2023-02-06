
#ifndef MS_6502_H_
#define MS_6502_H_

    #include <stdint.h>
    #include <stdlib.h>

    typedef enum FLAGSMS6502_t
	{
	
    	C = (1 << 0),	// Carry Bit
		Z = (1 << 1),	// Zero
		I = (1 << 2),	// Disable Interrupts
		D = (1 << 3),	// Decimal Mode
		B = (1 << 4),	// Break
		U = (1 << 5),	// Unused
		V = (1 << 6),	// Overflow
		N = (1 << 7),	// Negative
	
    } FLAGSMS6502;

    /**
     * @brief New type of MS6502.
    */
    typedef struct MS6502_t
    {

        uint8_t  a;
        uint8_t  x;
        uint8_t  y;
        
        uint16_t program_counter;

        uint8_t    stack_pointer;
        
        uint8_t           status;

        uint8_t  fetched;   	// Represents the working input value to the ALU
        uint16_t temp; 			// A convenience variable used everywhere
        uint16_t addr_abs; 		// All used memory addresses end up in here
        uint16_t addr_rel;   	// Represents absolute address following a branch
        uint8_t  opcode;   		// Is the instruction byte
        uint8_t  cycles;	   	// Counts how many cycles the instruction has remaining
        uint32_t clock_count;	// A global accumulation of the number of clocks

        uint8_t (*ReadMemory )(uint16_t);

        void    (*WriteMemory)(void *, uint16_t, uint8_t);

    } MS6502;

    MS6502 *CreateNewMS6502 (void);

    void ResetMS6502    (MS6502 *);

#endif
