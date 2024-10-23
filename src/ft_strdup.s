section .data
null_msg db "The src is null", 10, 0  ; Error message for null pointer, terminated with a null byte
malloc_msg db "Allocation error", 10, 0

section .text

extern ft_strlen 
extern ft_strcpy
extern malloc

global ft_strdup

ft_strdup:
    test rsi, rsi             ;checxk if rsi is null
    jz _null_pointer          ;send the null poarameter to error section

    mov r8, rdi               ;save the rdi pointer to a temporary register
    
    call ft_strlen            ;check string size
    add rax, 1                ;increase 1 size to \0
    
    mov rdi, rax              ;mov the len data to return register
    
    call malloc wrt ..plt     ;call C malloc function
    test rax, rax             ;check for malloc error returned
    jz _malloc_error          ;jump to malloc error section

    mov rdi, rax              ;move malloc address to rdi
    
    mov rsi, r8               ;move the rdi pointer backup to rsi
        
    call ft_strcpy            ;copy rsi to rdi
    
end:
    ret                       ;return copied string

_null_pointer:
    lea rax, [rel null_msg]   ;send standard message funcionv to rax
    ret                       ;return message error

_malloc_error:
    lea rax, [rel malloc_msg] ;send standard message funcionv to rax
    re                        ;return message error