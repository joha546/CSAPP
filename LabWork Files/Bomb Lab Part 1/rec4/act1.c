#include <stdio.h>

int main(int argc, char** argv)
{    
    int ret = printf("%s\n", argv[argc-1]);
    argv[0] = '\0'; // NOOP to force gcc to generate a callq instead of jmp
    return ret;
}

/*
by running (gdb) break main
break main
Breakpoint 1 at 0x401680: file act1.c, line 5. It tells that to gdb to pause right before entering
main function.
*/