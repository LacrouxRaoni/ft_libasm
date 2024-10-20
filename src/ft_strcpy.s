section .data
null_msg db "The src or dst is null", 10, 0  ; Error message for null pointer, terminated with a null byte

section .text

global ft_strcpy

ft_strcpy:
    ; Check if the source pointer (rsi) is null

    test rsi, rsi
    jz  _null_pointer  ; If null, jump to _null_pointer
    ; Check if the destination pointer (rdi) is null
    test rdi, rdi
    jz _null_pointer   ; If null, jump to _null_pointer

    ; Initialize the length counter (rcx) and store the destination address in rbx
    xor rcx, rcx       ; Clear the rcx register
    mov rbx, rdi       ; Store the destination pointer in rbx

_src_len:
    ; Traverse the source string to calculate its length
    cmp byte [rsi + rcx], 0  ; Compare the current byte with 0 (null terminator)
    je _start_copy_data      ; If equal to 0, jump to _start_copy_data
    inc rcx                  ; Increment the length counter
    jmp _src_len             ; Repeat the loop

_start_copy_data:
    ; Start copying the data
    xor rdx, rdx       ; Clear the rdx register (used as copy counter)

copy_loop:
    ; Copy the source string byte by byte to the destination
    mov al, [rsi + rdx]     ; Load the current byte from the source into al
    mov [rbx + rdx], al     ; Store the current byte into the destination
    inc rdx                 ; Increment the copy counter
    test al, al             ; Test if the current byte is 0 (null terminator)
    jnz copy_loop           ; If not 0, repeat the loop

done:
    ; Finish the function, returning the destination pointer
    mov rax, rdi       ; Store the destination pointer in rax (return value)
    ret                ; Return from the function


_null_pointer:
    ; Error handling for null pointer
    lea rax, [rel null_msg] ; Load the address of the error message into rax
    ret                     ; Return from the function
    