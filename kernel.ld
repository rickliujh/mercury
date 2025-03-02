/* 
 * How They Work Together:
 * 1. Compilation: The compiler generates object files that contain these sections.
 * 2. Linking: The linker combines the object files and arranges the sections in 
 *      the final executable file.
 * 3. Loading: The operating system loader reads the executable file and loads 
 *      these sections into memory.
 * 4. Execution: The CPU executes the instructions in the .text section, and the 
 *      program accesses the data in the .data, .rodata, and .bss sections.
 */
ENTRY(boot)


SECTIONS {
    . = 0x80200000;

    /* 
     * .text contains the executable instructions of the program.
     * It holds the machine code that the CPU will execute.
     * Typically read-only.
     * Contains the program's functions and other executable code.
     * Often placed in a protected memory region to prevent accidental modification.
     * */
    .text :{
        KEEP(*(.text.boot));
        *(.text .text.*);
    }

    /* 
     * .rodata contains read-only data, such as string literals and constant values.
     * It holds data that should not be modified during program execution.
     * */
    .rodata : ALIGN(4) {
        *(.rodata .rodata.*);
    }

    /* 
     * .data contains initialized global and static variables.
     * It holds data that has a defined initial value.
     * */
    .data : ALIGN(4) {
        *(.data .data.*);
    }

    /* 
     * .bss stands for "Block Started by Symbol." 
     * It's used to allocate memory for variables that are declared but not 
     * explicitly initialized in the source code.
     * */
    .bss : ALIGN(4) {
        __bss = .;
        *(.bss .bss.* .sbss .sbss.*);
        __bss_end = .;
    }

    . = ALIGN(4);
    . += 128 * 1024; /* 128KB */
    __stack_top = .;

    . = ALIGN(4096);
    __free_ram = .;
    . += 64 * 1024 * 1024; /* 64MB */
    __free_ram_end = .;
}
