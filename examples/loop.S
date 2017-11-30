
.global do_inc
.type do_inc, @function
do_inc:
    push %rax
    push %rcx
    push %rdx
    push %rbx
    push %rdi
    mov (%rdi), %rax
    inc %rax
    mov %rax, (%rdi)
    add $40, %rsp
    ret
.size do_inc, . - do_inc

