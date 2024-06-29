section .text
global ft_strcmp    ;define the function ft_strcmp to to be used in other modules.

ft_strcmp:
    ;rdi = s1       
    ;rsi = s2

    test rdi, rdi   ;test if rdi is null
    jz null_pointer ;if rdi is null jumps to null_pointer section
    test rsi, rsi   ;check if rsi is null
    jz null_pointer ;if rsi is null jumps to null_pointer section

cmp_loop:
    mov al, [rdi]   ;mov rdi pointer to al
    mov bl, [rsi]   ;mov rsi pointer to bl

    cmp al, bl      ;compare if al and bl are equal
    jne str_not_eql ;jump to str_not_eql to return result

    cmp al, 0       ;check if al is hoolding the end of str \0
    je str_eql      ;jump to the  str_eql section to return 0

    inc rdi         ;increase rdi to the next pointer
    inc rsi         ;increase rsi to the next pointer

    jmp cmp_loop    ;repeal cmp_loop

str_eql:
    xor rax, rax    ;set rax to 0 using xor bitwise
    ret             ;return 0

str_not_eql:
    movzx rax, al   ;move data from al to a larger size register
    movzx rsi, bl   ;move data from bl to a larger size register
    sub rax, rbx    
    ret

null_pointer:
    mov rax, -1     ;set rax with -1
    ret             ;return -1