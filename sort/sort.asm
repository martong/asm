
global start


section .text

newline:
    mov     rax, 0x2000004 ; write
    mov     rdi, 1 ; stdout
    mov     rsi, NEWLINE ; msg
    mov     rdx, 1 ; len
    syscall
    ret


display_one_digit:
    ; save param from rdi
    mov r15, [rdi]
    ; make it to be ascii
    add r15, '0'
    push r15

    mov     rax, 0x2000004 ; write
    mov     rdi, 1 ; stdout
    mov     rsi, rsp ; msg
    mov     rdx, 1 ; len
    syscall
    add rsp, 8
    ret

start:
    mov     rax, 0x2000004 ; write
    mov     rdi, 1 ; stdout
    mov     rsi, msg
    mov     rdx, msg.len
    syscall

    mov rdi, x
    call display_one_digit
    call newline

    mov     rax, 0x2000001 ; exit
    mov     rdi, 0
    syscall


section .data

msg:    db      "Hello, world!", 10
.len:   equ     $ - msg

NEWLINE: db 0x0a ; http://www.asmcommunity.net/forums/topic/?id=26085
x: dw 1, 2, 3, 4, 5
xx: dw '1'
