section .text
global ft_strcpy

;verificar se as strings sao nulas, ok
;verificar o tamanho da src
;verrificar se a dst eh igual ou maior que a src
;copiar e retornar







ft_strcpy:
    ;rdi = dst;
    ;rsi = src;

    ;check if rdi or rsi is null
    test rdi, rdi
    jz null_pointer
    test rsi, rsi
    jz null_pointer


null_pointer:
    mov rax, 0
    ret