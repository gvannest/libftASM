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
        or      dl, dl
        jz      end_of_string
        mov     byte [rdi], dl
        inc     rsi
        inc     rdi
        jmp     loop
        
    end_of_string:
        mov     byte [rdi], 0x0
    
    _leave:
        mov     rsp, rbp
        pop     rbp
        ret