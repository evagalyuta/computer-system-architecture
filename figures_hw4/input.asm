extern printf
extern fscanf

extern SPHERE
extern PARALLELEPIPED
extern TETRAHEDRON

;----------------------------------------------
; Input sphere.
global InSphere
InSphere:
section .data
    .infmt db "%d%lf",0
section .bss
    .FILE   resq    1   ; file address
    .pspher resq    1   ; sphere address
section .text
push rbp
mov rbp, rsp

    mov     [.pspher], rdi
    mov     [.FILE], rsi

    mov     rdi, [.FILE]
    mov     rsi, .infmt
    mov     rdx, [.pspher]    ;radius address
    mov     rcx, [.pspher]
    add     rcx, 4            ;density address
    mov     rax, 1
    call    fscanf

leave
ret

; Input parallelepiped.
global InParallelepiped
InParallelepiped:
section .data
    .infmt db "%d%d%d%lf",0
section .bss
    .FILE   resq    1   ; file address
    .parallel  resq    1   ; parallelepiped address
section .text
push rbp
mov rbp, rsp

    mov     [.parallel], rdi
    mov     [.FILE], rsi

    mov     rdi, [.FILE]
    mov     rsi, .infmt
    mov     rdx, [.parallel]       ; a address
    mov     rcx, [.parallel]
    add     rcx, 4              ; b address
    mov     r8, [.parallel]
    add     r8, 8               ; c address
    mov     r12, [.parallel]
    add     r12, 12               ; density address
    mov     rax, 1
    call    fscanf

leave
ret

; Input tetrahedron.
global InTetrahedron
InTetrahedron:
section .data
    .infmt db "%d%lf",0
section .bss
    .FILE   resq    1   ; file address
    .ptetrahed resq    1   ; tetrahedron address
section .text
push rbp
mov rbp, rsp

    mov     [.ptetrahed], rdi
    mov     [.FILE], rsi

    mov     rdi, [.FILE]
    mov     rsi, .infmt
    mov     rdx, [.ptetrahed]    ;edge address
    mov     rcx, [.ptetrahed]
    add     rcx, 4            ;density address
    mov     rax, 1
    call    fscanf

leave
ret

; Input shape.
global InShape
InShape:
section .data
    .tagFormat   db      "%d",0
    .tagOutFmt   db     "Tag is: %d",10,0
section .bss
    .FILE       resq    1   ; file address
    .pshape     resq    1   ; shape address
    .shapeTag   resd    1   ; shape type
section .text
push rbp
mov rbp, rsp

    mov     [.pshape], rdi
    mov     [.FILE], rsi

    mov     rdi, [.FILE]
    mov     rsi, .tagFormat
    mov     rdx, [.pshape]
    xor     rax, rax
    call    fscanf

    mov rcx, [.pshape]
    mov eax, [rcx]
    cmp eax, [SPHERE]
    je .sphereIn
    cmp eax, [PARALLELEPIPED]
    je .parallelIn
    cmp eax, [TETRAHEDRON]
    je .tetrahedIn
    xor eax, eax
    jmp     .return
.sphereIn:
    mov     rdi, [.pshape]
    add     rdi, 4
    mov     rsi, [.FILE]
    call    InSphere
    mov     rax, 1
    jmp     .return
.parallelIn:
    mov     rdi, [.pshape]
    add     rdi, 4
    mov     rsi, [.FILE]
    call    InParallelepiped
    mov     rax, 1
    jmp     .return
.tetrahedIn:
    mov     rdi, [.pshape]
    add     rdi, 4
    mov     rsi, [.FILE]
    call    InTetrahedron
    mov     rax, 1
.return:

leave
ret

; Input container.
global InContainer
InContainer:
section .bss
    .pcont  resq    1   ; container address
    .plen   resq    1   ; count address
    .FILE   resq    1   ; file address
section .text
push rbp
mov rbp, rsp

    mov [.pcont], rdi
    mov [.plen], rsi
    mov [.FILE], rdx

    xor rbx, rbx
    mov rsi, rdx
.loop:
    push rdi
    push rbx

    mov     rsi, [.FILE]
    mov     rax, 0
    call    InShape
    cmp rax, 0
    jle  .return

    pop rbx
    inc rbx

    pop rdi
    add rdi, 20

    jmp .loop
.return:
    mov rax, [.plen]
    mov [rax], ebx
leave
ret
