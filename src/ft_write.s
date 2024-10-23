section .text
global ft_write

ft_write:
    
    movsxd rdi, edi ;Sign-extend from 32-bit edi to 64-bit rdi
    cmp rdi, 0      ;compare if rdi is lower than 0
    jl error        ;jump to error section
    cmp rdx, 0      ;compare if rdi is lower than 0
    jl error        ;jump to error section
        
    test rsi, rsi
    je handle_null

    mov rax, 1
    syscall
    cmp rax, 0
    jl error
    
end:        
   mov rax, rdx 
   ret

handle_null:
    cmp rdx, 0
    jne error    
    jmp end

error:
    mov rax, -1 ;set rax with -1
    ret
