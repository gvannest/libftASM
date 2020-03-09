section .text

global  _ft_list_push_front
extern  _malloc

_ft_list_push_front:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 0x20

        test    rdi, rdi
        jz      _return            ; return if no list
        cmp     qword [rdi], 0x0
        je      _return
                          
        mov     [rbp - 0x8], rdi          ;save registers
        mov     [rbp - 0x10], rsi
        mov     rdi, len
        call    _malloc                  ; call malloc with len as a parameter
        test    rax, rax
        jz      _return                  
        mov     rdi, [rbp - 0x8]             ;get registers back           
        mov     rsi, [rbp - 0x10]

        mov     [rax + data], rsi
        mov     rdx, [rdi]      ; we make the next pointer of the newly block pointing to first block
        mov     [rax + data + next], rdx
        mov     [rdi], rax


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