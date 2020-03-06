section     .text

    global  _ft_strdup
    extern  _malloc
    extern  _ft_strlen
    extern  _ft_strcpy

_ft_strdup:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 0x20
        mov     [rbp - 0x8], rdi
        call    _ft_strlen
        inc     rax
        mov     rdi, rax
        call    _malloc
        and     rax, rax
        jz      done
        mov     rsi, [rbp - 0x8]
        mov     rdi, rax
        call    _ft_strcpy

    done:
        leave
        ret
