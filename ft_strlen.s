section  .text

global  _ft_strlen

_ft_strlen:       
    push    rbp
    mov     rbp, rsp
    sub     rsp, 16
    xor     rax, rax
    
    loop:   
        mov     dl, byte [rdi + rax]
        or      dl, dl
        jz      return
        inc     rax
        jmp     loop

    return: 
        leave
        ret