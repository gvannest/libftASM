section .text

global  _ft_list_size

_ft_list_size:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 0x20

        xor     rax, rax
        

    loop:    
        test    rdi, rdi
        jz      _return
        inc     rax
        mov     rdi, [rdi + data + next]
        jmp     loop
        
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