section .text

extern __errno_location               ; Import the errno location function
global ft_write

ft_write:  
    movsxd rdi, edi                   ; Sign-extend from 32-bit edi to 64-bit rdi
    cmp rdx, 0                        ; Compare if rdx is lower than 0
    jl invalid_size                   ; Jump to error section

    test rsi, rsi                     ; Check if rsi has a null value
    je handle_null                    ; Jump to handle_null if rsi is null

    mov rax, 1                        ; Syscall number for sys_write (1)
    syscall                           ; Make the syscall
    cmp rax, 0                        ; Check if syscall failed
    jl bad_file_descriptor           ; Jump to bad_file_descriptior if failed
    
end:        
   mov rax, rdx                       ; Send buffer size to rax
   ret                                ; Return buffer size written

handle_null:
    cmp rdx, 0                        ; Check if buffer size is null
    jne invalid_size                  ; If not zero, jump to invalid_size section
    jmp end                           ; Jump to end to return 0

invalid_size:
    call __errno_location wrt ..plt   ; Get the address of errno
    mov dword [rax], 14               ; Set errno to EFAU (Invalid argument, value 22)
    jmp error                         ; Jump to error handling

bad_file_descriptor:
    call __errno_location wrt ..plt   ; Get the address of errno
    mov dword [rax], 9                ; Set errno to EBADF (Bad file descriptor, value 9)
    jmp error                         ; Jump to error handling

error:
    mov rax, -1                       ; Set rax to -1 to indicate error
    ret                               ; Return -1