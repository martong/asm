global _find_smallest_in_range
global _asm_selection_sort

section .text

; char* f(char* range, size_t len)
; rdi: pointer to range of bytes
; rsi: len of range
_find_smallest_in_range:
    mov r15b, [rdi] ; first element's value
    mov rax, rdi ; first element
loop2:
    mov r14b, [rdi]
    cmp r14b, r15b
    jge greater_or_eq
    ; less
    mov r15b, [rdi]
    mov rax, rdi ; first element
greater_or_eq:
    ; loop end
    inc rdi
    dec rsi
    jnz loop2
    ret


; void asm_selection_sort(char* range, size_t len)
; rdi: pointer to range of bytes
; rsi: len of range
_asm_selection_sort:
loop3:
    push rdi
    push rsi
    call _find_smallest_in_range
    mov r15b, [rax] ;smallest value
    pop rsi
    pop rdi

    ; swap
    mov r14b, [rdi] ;vale at the beginning
    mov [rdi], r15b
    mov [rax], r14b

    inc rdi
    dec rsi
    jnz loop3
    ret


