section .data
null_msg db "The src or dst is null", 10, 0
test_msg db "Puda", 0

section .text
global ft_strcpy

ft_strcpy:

    test rsi, rsi
    jb  _null_pointer
    test rdi, rdi
    jb _null_pointer

    xor rcx, rcx
    mov rbx, rdi


_src_len:
    cmp byte [rsi + rcx], 0
    je _copy_data
    inc rcx
    jmp _src_len

_copy_data:
    xor rdx, rdx

copy_loop:
    mov al, [rsi + rdx]
    mov [rbx + rdx], al
    inc rdx
    test al, al
    jnz copy_loop

    cmp rcx, rdx
    jne _buffer_overflow

done:
    mov rax, rdi
    ret

_buffer_overflow:
    mov rax, rdi
    ret

_null_pointer:
    lea rax, [rel null_msg]
    ret
    