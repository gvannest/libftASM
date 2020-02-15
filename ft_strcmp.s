section     .text

globa       _ft_strcmp

_ft_strcmp:
                push    rbp
                mov     rbp, rsp
                sub     rsp, 0x10
                xor     rdx. rdx 
                xor     rcx. rcx

        loop:
                mov     dl, byte [rdi]
                mov     cl, byte [rsi]
                or      dl, dl
                jz      end
                or      cl, cl
                jz      end
                cmp     dl, cl
                jne     end
                inc     rdi
                inc     rsi

        end:
                movzx   rax, dl
                movzx   rdx, cl
                sub     rax, rdx    