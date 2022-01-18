//  This assembly code does the following:
//      1. Set up stack pointer
//      2. Set up the program counter to start of ram memory
.extern __stack_start
.global _exit
.arm // Setup Processor in ARM mode
.section .text._init

.global _init
_init:
    // First function to run
    // The stack operations are implemented as PUSH and POP in 
    // the compiler. They are used as the following:
    // PUSH - STMFD (Store multiple full descending)
    // POP  - LDMDF (Load multiple increment after)
    // We need to give the stack some space above the stack
    LDR SP, =__stack_start // push stack address into stack pointer
    B main // Run to main function in C
    
_idle: 
    NOP
    B _idle

_exit: 
    B _idle