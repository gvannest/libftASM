section .text

global  _ft_atoi_base


_ft_len_alpha:
    push    rbp
    mov     rbp, rsp
    xor     rdx, rdx
    xor     rax, rax
    xor     r10, r10
    
    _loop_alpha:
        mov     dl, byte [rdi]
        mov     r10, 0x41
        _loop_capital:
            test    dl, byte r10
            jz      _new_loop
            inc     r10
            test    r10, 0x5b
            js      _loop_capital
        mov     r10, 0x61
        _loop_not_capital:
            test    dl, byte r10
            jz      _new_loop
            inc     r10
            test    r10, 0x7b
            js      _loop_not_capital
        mov     r10, 0x30
        _loop_numerical:
            test    dl, byte r10
            jz      _new_loop
            inc     r10
            test    r10, 0x3a
            js      _loop_numerical
        jmp     _return

    _new_loop:
        inc     rdi
        inc     rax
        jmp     _loop_alpha

    _return:
        leave
        ret


_ft_atoi_base:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 0x10

    _loop:
        mov     dl, byte [rdi]
        test    dl, 32
        jz      _loop_back
        mov     r10, 0x9

    _loop2:
        test    dl, byte r10
        jz      _loop_back
        inc     r10
        test    r10, 14
        js      _loop_back
        jmp     _suite

    _loop_back:
        inc     rdi
        jmp     _loop

    _suite:
        mov     [rbp - 0x8], rdi
        call    _ft_len_alpha
        mov     rdi, [rbp - 0x8]

    _leave:
        leave
        ret
        