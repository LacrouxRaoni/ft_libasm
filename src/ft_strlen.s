section .text
global ft_strlen            ;define the function ft_strlen to be used in other modules. 

ft_strlen:
    test rdi, rdi           ;check if register rdi is null
    jz null_pointer         ;if rdi is null it jumps to null_pointer section
    xor rcx, rcx            ;set the rcx to 0 using operand xor by bitwise

_loop:
    cmp byte [rdi + rcx], 0 ;checks if the current character is the end of the string (\0)
    je done                 ;jump to done label when cmp find the end byte
    inc rcx                 ;increment rcx by 1
    jmp _loop               ;jump to the _loop label executing the loop again.

done:
    mov rax, rcx            ;move the rcx register value to rax
    ret                     ;return size len

null_pointer:
    mov rax, -1             ;set rax with -1
    ret                     ;return -1