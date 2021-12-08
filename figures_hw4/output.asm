extern printf
extern fprintf

extern SquareSphere
extern SquareParallelepiped
extern SquareTetrahedron

extern SPHERE
extern PARALLELEPIPED
extern TETRAHEDRON

;----------------------------------------------
; Output sphere.
global OutSphere
OutSphere:
section .data
    .outfmt db "It is Sphere: radius = %d, density = %g. Square = %g",10,0
section .bss
    .pspher  resq  1
    .FILE   resq  1       ; file address
    .p      resq  1       ; sphere square
section .text
push rbp
mov rbp, rsp

    mov     [.pspher], rdi
    mov     [.FILE], rsi

    call    SquareSphere
    movsd   [.p], xmm0

    mov     rdi, [.FILE]
    mov     rsi, .outfmt
    mov     rax, [.pspher]
    mov     edx, [rax]          ; radius
    mov     ecx, [rax+4]        ; density
    movsd   xmm0, [.p]          ; square
    mov     rax, 1
    call    fprintf

leave
ret

; Output parallelepiped.
global OutParallelepiped
OutParallelepiped:
section .data
    .outfmt db "It is Parallelepiped: a = %d, b = %d, c = %d. Square = %g",10,0
section .bss
    .pparallel  resq  1
    .FILE   resq  1       ; file address
    .p      resq  1       ; square parallelepiped
section .text
push rbp
mov rbp, rsp

    mov     [.pparallel], rdi
    mov     [.FILE], rsi

    call    SquareParallelepiped
    movsd   [.p], xmm0

    mov     rdi, [.FILE]
    mov     rsi, .outfmt
    mov     rax, [.pparallel]
    mov     edx, [rax]          ; a
    mov     ecx, [rax+4]        ; b
    mov      r8, [rax+8]        ; c
    movsd   xmm0, [.p]          ; square
    mov     rax, 1
    call    fprintf

leave
ret

; Output tetrahedron.
global OutTetrahedron
OutTetrahedron:
section .data
    .outfmt db "It is Tetrahedron: edge = %d, density = %g. Square = %g",10,0
section .bss
    .ptetrahed  resq  1
    .FILE   resq  1       ; file address
    .p      resq  1       ; tetrahedron square
section .text
push rbp
mov rbp, rsp

    mov     [.ptetrahed], rdi
    mov     [.FILE], rsi

    call    SquareTetrahedron
    movsd   [.p], xmm0

    mov     rdi, [.FILE]
    mov     rsi, .outfmt
    mov     rax, [.ptetrahed]
    mov     edx, [rax]          ; edge
    mov     ecx, [rax+4]        ; density
    movsd   xmm0, [.p]          ; square
    mov     rax, 1
    call    fprintf

leave
ret

;----------------------------------------------
; Output shape.
global OutShape
OutShape:
section .data
    .erShape db "Incorrect figure!",10,0
section .text
push rbp
mov rbp, rsp

    mov eax, [rdi]
    cmp eax, [SPHERE]
    je spherOut
    cmp eax, [PARALLELEPIPED]
    je parallelOut
    cmp eax, [TETRAHEDRON]
    je tetrahedOut
    mov rdi, .erShape
    mov rax, 0
    call fprintf
    jmp     return
spherOut:
    add     rdi, 4
    call    OutSphere
    jmp     return
parallelOut:
    add     rdi, 4
    call    OutParallelepiped
    jmp     return
tetrahedOut:
    add     rdi, 4
    call    OutTetrahedron
return:
leave
ret

;----------------------------------------------
; Output container.
global OutContainer
OutContainer:
section .data
    numFmt  db  "%d: ",0
section .bss
    .pcont  resq    1   ; container address
    .len    resd    1   ; count
    .FILE   resq    1   ; file address
section .text
push rbp
mov rbp, rsp

    mov [.pcont], rdi
    mov [.len],   esi
    mov [.FILE],  rdx

    mov rbx, rsi
    xor ecx, ecx
    mov rsi, rdx
.loop:
    cmp ecx, ebx
    jge .return

    push rbx
    push rcx

    mov     rdi, [.FILE]
    mov     rsi, numFmt
    mov     edx, ecx
    xor     rax, rax,
    call fprintf

    mov     rdi, [.pcont]
    mov     rsi, [.FILE]
    call OutShape

    pop rcx
    pop rbx
    inc ecx

    mov     rax, [.pcont]
    add     rax, 20
    mov     [.pcont], rax
    jmp .loop
.return:
leave
ret
