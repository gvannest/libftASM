section     .text

    global  _ft_strdup
    extern  _malloc
    extern  _ft_strlen

_ft_strdup:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 0x10
        xor     r10, r10
        mov     r10, rdi
        call    _ft_strlen
        inc     rax
        mov     rdi, rax
        call    _malloc
        and     rax, rax
        jz      end
        mov     rdx, rax

    loop: 
        mov     [dl], byte [r10]
        or      [dl], [dl]
        jz      end
        inc     r10
        inc     rdx
        jmp     loop

    end:
        leave
        ret
