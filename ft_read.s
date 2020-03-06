%define MACH_SYSCALL(nb) 0x2000000 | nb
%define READ             3               

section     .text

global       _ft_read

_ft_read:
                push    rbp
                mov     rbp, rsp
                sub     rsp, 0x10
                mov     rax, MACH_SYSCALL(READ)
                syscall
                jc      error
                jmp     return

        error:
                mov     rax, -1

        return:
                leave
                ret