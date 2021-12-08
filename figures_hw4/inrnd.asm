extern printf
extern rand

extern SPHERE
extern PARALLELEPIPED
extern TETRAHEDRON


;----------------------------------------------
; Random numbers from 1 to 20.
global Random
Random:
section .data
    .i20     dq      20
    .rndNumFmt       db "Random number = %d",10,0
section .text
push rbp
mov rbp, rsp

    xor     rax, rax
    call    rand
    xor     rdx, rdx
    idiv    qword[.i20]
    mov     rax, rdx
    inc     rax
        ;tests
    ;mov     rdi, .rndNumFmt
    ;mov     esi, eax
    ;xor     rax, rax
    ;call    printf

leave
ret

; Random fraction from 0 to 1.
global RandomFraction
RandomFraction:
section .data
    .i99     dq      99
    .i100     dq      100
    .rndNumFmt       db "Random number = %d",10,0
section .text
push rbp
mov rbp, rsp

    xor     rax, rax
    call    rand
    xor     rdx, rdx
    idiv    qword[.i99]
    mov     rax, rdx
    inc     rax
    idiv    qword[.i100]
        ;tests
    ;mov     rdi, .rndNumFmt
    ;mov     esi, eax
    ;xor     rax, rax
    ;call    printf

leave
ret

;----------------------------------------------
;Random sphere data (radius, density).
global InRandSphere
InRandSphere:
section .bss
    .pshper  resq 1   ;sphere address
section .text
push rbp
mov rbp, rsp

    mov     [.pshper], rdi

    call    Random
    mov     rbx, [.pshper]
    mov     [rbx], eax    ;radius
    call    RandomFraction
    mov     rbx, [.pshper]
    mov     [rbx+4], eax    ;density

leave
ret

;----------------------------------------------
;Random parallelepiped data (a, b, c, density).
global InRandParallelepiped
InRandParallelepiped:
section .bss
    .pparallel  resq 1   ;parallelepiped address
section .text
push rbp
mov rbp, rsp

    mov     [.pparallel], rdi

    call    Random
    mov     rbx, [.pparallel]
    mov     [rbx], eax    ;a
    call    Random
    mov     rbx, [.pparallel]
    mov     [rbx+4], eax    ;b
    call    Random
    mov     rbx, [.pparallel]
    mov     [rbx+8], eax    ;c
    call    RandomFraction
    mov     rbx, [.pparallel]
    mov     [rbx+12], eax    ;density


leave
ret

;----------------------------------------------
;Random tetrahedron data (edge, density).
global InRandTetrahedron
InRandTetrahedron:
section .bss
    .ptetrahed  resq 1   ;tetrahedron address
section .text
push rbp
mov rbp, rsp

    mov     [.ptetrahed], rdi

    call    Random
    mov     rbx, [.ptetrahed]
    mov     [rbx], eax    ;edge
    call    RandomFraction
    mov     rbx, [.ptetrahed]
    mov     [rbx+4], eax    ;density

leave
ret

;----------------------------------------------
; Input random shape.
global InRandShape
InRandShape:
section .data
    .i3     dq      3
    .rndNumFmt       db "Random number = %d",10,0
section .bss
    .pshape     resq    1   ; shape address
    .key        resd    1   ; key
section .text
push rbp
mov rbp, rsp

    mov [.pshape], rdi

    xor     rax, rax
    call    rand
    xor     rdx, rdx
    idiv    qword[.i3]
    mov     rax, rdx
    inc     rax
        ;tests
    ;mov     [.key], eax
    ;mov     rdi, .rndNumFmt
    ;mov     esi, [.key]
    ;xor     rax, rax
    ;call    printf
    ;mov     eax, [.key]

    mov     rdi, [.pshape]
    mov     [rdi], eax
    cmp eax, [SPHERE]
    je .spherInRand
    cmp eax, [PARALLELEPIPED]
    je .parallelInRand
    cmp eax, [TETRAHEDRON]
    je .tetrahedInRand
    xor eax, eax
    jmp     .return
.spherInRand:     ;random sphere
    add     rdi, 4
    call    InRandSphere
    mov     eax, 1
    jmp     .return
.parallelInRand:      ;random parallelepiped
    add     rdi, 4
    call    InRandParallelepiped
    mov     eax, 1
    jmp     .return
.tetrahedInRand:      ;random tetrahedron
    add     rdi, 4
    call    InRandTetrahedron
    mov     eax, 1
.return:
leave
ret

;----------------------------------------------
;Random input container
global InRandContainer
InRandContainer:
section .bss
    .pcont  resq    1   ; container address
    .plen   resq    1   ; cout address
    .psize  resd    1   ; size address
section .text
push rbp
mov rbp, rsp

    mov [.pcont], rdi
    mov [.plen], rsi
    mov [.psize], edx
    xor ebx, ebx
.loop:
    cmp ebx, edx
    jge     .return

    push rdi
    push rbx
    push rdx

    call    InRandShape
    cmp rax, 0
    jle  .return

    pop rdx
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
