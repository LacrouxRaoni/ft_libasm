section .text
global ft_strlen

ft_strlen:
    xor rcx, rcx

_loop:
    cmp byte [rdi + rcx], 0
    je done
    inc rcx
    jmp _loop

done:
    mov rax, rcx
    ret