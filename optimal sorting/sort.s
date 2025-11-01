.text
    .globl sort
sort:
    cmp $1, %rsi
    jle done

    mov %rsi, %rcx
    dec %rcx

outer_loop:
    xor %rbx, %rbx

inner_loop:
    movl (%rdi,%rbx,4), %eax
    movl 4(%rdi,%rbx,4), %edx
    cmpl %edx, %eax
    jle no_swap

    movl %edx, (%rdi,%rbx,4)
    movl %eax, 4(%rdi,%rbx,4)

no_swap:
    inc %rbx
    cmp %rbx, %rcx
    jl inner_loop

    dec %rcx
    jg outer_loop

done:
    ret
