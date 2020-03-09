section .text

global  _ft_list_sort

_is_sorted:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 0x20
        test    rsi, rsi
        jz      _error
        test    rdi, rdi
        jz      _error
        xor     rax, rax
        mov     r8, rdi
        mov     [rbp - 0x18], rsi

    _loop_sorted:
        test    r8, r8
        jz      _return_sorted
        cmp     qword [r8 + data + next], 0x0
        je      _return_sorted
        mov     r9, [r8 + data + next]
        mov     rdi, [r8 + data]
        mov     rsi, [r9 + data]
        mov     [rbp - 0x8], r8
        mov     [rbp - 0x10], r9
        call    [rbp - 0x18]
        test    eax, eax
        jz      _continue
        jns     _return_non_sorted
    _continue:
        mov     r8, [rbp - 0x8]
        mov     r9, [rbp - 0x10]
        mov     r8, r9
        jmp     _loop_sorted
        
    _error:
        mov     rax, -1
        leave
        ret

    _return_sorted:
        mov     rax, 0x1
        leave
        ret

    _return_non_sorted:
        xor     rax, rax
        leave
        ret


_ft_list_sort:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 0x30

        test    rdi, rdi
        jz      _return
        test    rsi, rsi
        jz      _return
        cmp     qword [rdi], 0x0
        je      _return_sorted

        mov     rdx, [rdi]
        mov     [rbp - 0x8], rdx
        mov     [rbp - 0x20], rsi
    _main_loop:
        mov     rdi, [rbp - 0x8]
        mov     rsi, [rbp - 0x20]
        call    _is_sorted
        test    rax, rax
        js      _return
        jnz     _return
        mov     rdx, [rbp - 0x8]

        _internal_loop:
            cmp     qword [rdx + data + next], 0x0
            je      _main_loop
            mov     rcx, [rdx + data + next]
            mov     rdi, [rdx + data]
            mov     rsi, [rcx + data]
            mov     [rbp - 0x10], rdx
            mov     [rbp - 0x18], rcx
            call    [rbp - 0x20]
            mov     rdx, [rbp - 0x10]
            mov     rcx, [rbp - 0x18]
            test    eax, eax
            js      _ok_next
            jz      _ok_next
            jmp     _swap_data

        _swap_data:
            mov     r10, [rcx + data]
            mov     r11, [rdx + data]
            mov     [rdx + data], r10
            mov     [rcx + data], r11
            jmp     _ok_next

        _ok_next:
            mov     rdx, [rdx + data + next]
            jmp     _internal_loop    
             
    _return:
        leave
        ret


section .data
        size_i:             ; Used to determine the size of the structure
        struc node
            data: resb  8
            next: resb  8
        endstruc
        len: equ $ - size_i  ; Size of the data type
