section .data
null_msg db "The src is null", 10, 0  ; Error message for null pointer, terminated with a null byte
malloc_msg db "Allocation error", 10, 0

section .text

extern ft_strlen 
extern ft_strcpy
extern malloc

global ft_strdup

ft_strdup:
    test rsi, rsi
    jz _null_pointer

    mov r8, rdi
    
    call ft_strlen
    add rax, 1
    
    mov rdi, rax
    
    call malloc wrt ..plt
    test rax, rax
    jz _malloc_error

    mov rdi, rax
    
    mov rsi, r8
        
    call ft_strcpy
    
end:
    ret

_null_pointer:
    lea rax, [rel null_msg]
    ret

_malloc_error:
    lea rax, [rel malloc_msg]
    ret