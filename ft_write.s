%define MACH_SYSCALL(nb) 0x2000000 | nb
%define WRITE            4               

section     .text

global       _ft_write

_ft_write:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 0x10
        mov     rax, MACH_SYSCALL(WRITE)
        syscall
        leave
        ret