section .text

global  _ft_atoi_base
extern  _ft_strlen

_ft_find_index:
        push    rbp
        mov     rbp, rsp
        push    rsi
        xor     rax, rax
        mov     dl, byte [rdi]

    _loop_index:    
        cmp     dl, byte [rsi]
        je      _return_index
        inc     rax
        inc     rsi
        jmp     _loop_index

    _return_index:
        pop     rsi
        leave
        ret


_ft_len_numerical:
        push    rbp
        mov     rbp, rsp
        xor     rdx, rdx
        xor     rax, rax
        xor     r10, r10
        cmp     byte [rdi], 0x2d
        je      neg_sign
    
    loop_n:
        push    rsi
        mov     dl, byte [rdi]
        test    dl, dl
        jz      _return
        ; mov     r10, byte [rsi]
        inside_loop:
        cmp     dl, byte [rsi]
        je      new_loop
        inc     rsi
        cmp     byte[rsi], 0x0
        je      _return
        jmp     inside_loop

    new_loop:
        inc     rdi
        inc     rax
        pop     rsi
        jmp     loop_n

    neg_sign:
        inc     rdi
        inc     rax
        jmp     loop_n

    _return:
        leave
        ret


_ft_atoi_base:
        push    rbp
        mov     rbp, rsp
        xor     rax, rax
        cmp     byte [rsi], 0x0
        je      _true_leave
        cmp     byte [rdi], 0x0
        je      _true_leave
        sub     rsp, 0x30
        xor     r11, r11

    _loop:
        movzx   rdx, byte [rdi]
        cmp     dl, 0x20
        je      _loop_back
        cmp     dl, 0x2b
        je      _loop_back
        mov     r10, 0x9
        _loop2:
        cmp     rdx, r10
        je      _loop_back
        inc     r10
        cmp     r10, 0xd
        jle      _loop2
        jmp     _suite
    _loop_back:
        inc     rdi
        jmp     _loop

    _suite:
        mov     [rbp - 0x8], rdi
        mov     [rbp - 0x10], rsi
        call    _ft_len_numerical
        mov     r8, rax
        mov     rdi, [rbp - 0x10]
        call    _ft_strlen
        mov     r9, rax
        xor     rax, rax
        mov     rdi, [rbp - 0x8]
        mov     rsi, [rbp - 0x10]
        cmp     byte [rdi], 0x2d
        je      _negative

    _positive:
        mul     r9
        push    rax
        call    _ft_find_index
        mov     rdx, rax
        pop     rax
        add     rax, rdx
        inc     rdi
        dec     r8
        test    r8, r8
        jz      _leave
        jmp     _positive

    _negative:
        mov     r11, -1
        inc     rdi
        dec     r8
        jmp     _positive

    _set_neg:
        mul     r11
        jmp     _true_leave

    _leave:
        test    r11, r11
        js      _set_neg      

    _true_leave:
        leave
        ret
        