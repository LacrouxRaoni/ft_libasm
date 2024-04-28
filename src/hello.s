section .data
    msg db 'Hello, word', 0

section .text
    global _start

_start:
    ; Escreve o texto (stdout)
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, 13
    syscall

    mov     rax, 60
    xor     rdi, rdi
    syscall