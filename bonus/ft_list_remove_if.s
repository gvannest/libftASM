section .text

global  _ft_list_remove_if

_ft_list_remove_if:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 0x30
        xor     rax, rax

        test    rdi, rdi
        jz      _return
        test    rsi, rsi
        jz      _return
        test    rdx, rdx
        jz      _return
        cmp     qword [rdi], 0x0
        je      _return

        mov     [rbp - 0x20], rbx 
        mov     [rbp - 0x8], rdi            ; Save inputs on stack to make sure we don't lose them
        mov     [rbp - 0x10], rsi
        mov     [rbp - 0x18], rdx
        mov     rbx, [rdi]
        xor     r10, r10
    _loop:
        mov     rsi, [rbp - 0x10]
        mov     rdx, [rbp - 0x18]
        test    rbx, rbx
        jz      _return
        mov     rdi, rsi
        mov     rsi, [rbx + data]
        call    rdx
        test    rax, rax
        jz      _delete
        jmp     _continue

    _delete:
        mov     rbx, [rbx + data + next]
        test    r10, r10
        jz      _first_node
        mov     [r10 + data + next], rbx
        jmp     _loop

    _first_node:
        mov     rdi, [rbp - 0x8]
        mov     [rdi], rbx
        jmp     _loop

    _continue:
        mov     r10, rbx
        mov     rbx, [rbx + data + next]
        jmp     _loop

    _return:
        mov     rbx, [rbp - 0x20]
        leave
        ret



section .data
        size_i:                 ; Used to determine the size of the structure
        struc node
            data: resb 8
            next: resb 8
        endstruc
        len: equ $ - size_i          ; Size of the data type