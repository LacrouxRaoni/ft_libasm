section .text
global ft_strcpy    ;define the function ft_strcmp to to be used in other modules.


ft_strcpy:
                                ;rdi = dst;
                                ;rsi = src;

                                ;check if rdi or rsi is null
    test rdi, rdi
    jz null_pointer             ;if rdi is null jumps to null_pointer section
    test rsi, rsi
    jz null_pointer             ;if rsi is null jumps to null_pointer section

    xor rcx, rcx                ;set rcx to zero using xor


_len_src:
     cmp byte [rsi + rcx], 0    ;compare pointer of rsi until get the \0
     je _check_dst              ;if it reaches the \0 jumps to _check_dst
     inc rcx                    ;increment rcx
     jmp _len_src               ;start loop again

_check_dst:
    inc rcx                     ;increment rcx to allocate an \0
    mov rax, rcx                ;move rcx to rax to be used later

    cmp rcx, rdi                ;compare if rdx has the same size of rcx
    jb _buffer_to_small         ;if size in rdx is not enoght. jumps to _buffer_to_small section

_copy_data:
    mov rax, rdi                
    cld
    rep movsb
    ret

_buffer_to_small:
    xor rax, rax
    ret

null_pointer:
    xor rax, rax
    ret