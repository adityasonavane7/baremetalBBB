/*
* The Beaglebone Black has a BOOTROM which loads the MLO file
* from the MMC to the internal RAM
* 
* The RAM starts from 0x402f_0000 and is 64kB in size.
*
* There is a reserved section in RAM which is 1kB in space so
* the effective space in RAM is 63kB.
* 
*/
MEMORY {
    RAM : org = 0x402f0000, len = 64K
}

PHDRS {
	image PT_LOAD;
}

ENTRY( _init )

SECTIONS {
    /* The first 1K of RAM cant be used */
    .reserved 0x402f0000 (NOLOAD): { . += 0x400; } > RAM :NONE
    
    /* Assign the stack to top so that we can have it grow above */
    . = 0x402f0400;
    .text : {
        KEEP(*( .text._init ))
        *( .text .text.* )
    } :image

    .rodata : {
        *( .rodata .rodata.* )
    } :image

    . = ALIGN(8);

    .data : {
        *(.data .data.*)
    } :image

    .bss : {
        __bss_start__ = .;
        *(.bss .bss.*)
        __bss_end__ = .;
    } :image

    /* . += 1K;
    __stack_start = .; */
    . += 512;

    . = .;
    __stack_start = .;

	.orphan : { INPUT_SECTION_FLAGS (SHF_ALLOC) *(*) } :NONE
	ASSERT( SIZEOF(.orphan) == 0, "unassigned sections" ) 
}