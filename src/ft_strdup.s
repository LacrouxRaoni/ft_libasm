section .data
null_msg db "The src is null", 10, 0  ; Error message for null pointer, terminated with a null byte
malloc_msg db "Allocation error", 10, 0

section .text

extern ft_strlen 
extern ft_strcpy
extern malloc
extern __errno_location             ; Import the errno location function

global ft_strdup

ft_strdup:
    test rdi, rdi                   ; Check if rdi is null
    jz _null_pointer                ; Send the null poarameter to error section

    mov r14, rdi                     ; Save the rdi pointer to a temporary register
    
    call ft_strlen                  ; Check string size
    add rax, 1                      ; Increase 1 size to \0
    
    mov rdi, rax                    ; Mov the len data to return register
    
    call malloc wrt ..plt           ; Call C malloc function
    test rax, rax                   ; Check for malloc error returned
    jz _malloc_error                ; Jump to malloc error section

    mov rdi, rax                    ; Move malloc address to rdi
    
    mov rsi, r14                     ; Move the rdi pointer backup to rsi
        
    call ft_strcpy                  ; Copy rsi to rdi
    
end:
    ret                             ; Return copied string

_null_pointer:
    xor rax, rax         ; Send standard message funcionv to rax
    ret                             ; Return message error

_malloc_error:
    call __errno_location wrt ..plt ; Get the address of errno
    mov dword [rax], 12             ; Set errno to ENOMEM (out of memory, value 12)
    lea rax, [rel malloc_msg]       ;send standard message funcionv to rax
    ret                             ;return message error