section     .text

global      _ft_strcpy

_ft_strcpy:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 0x10
        xor     rax, rax
        or      rsi, rsi
        jz      _leave
        mov     rax, rdi

    loop:
        mov     dl, byte [rsi]
        mov     byte [rdi], dl
        or      dl, dl
        jz      _leave
        inc     rsi
        inc     rdi
        jmp     loop
    
    _leave:
        mov     rsp, rbp
        pop     rbp
        ret