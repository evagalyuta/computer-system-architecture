; Square of shapes.
extern SPHERE
extern PARALLELEPIPED
extern TETRAHEDRON

;----------------------------------------------
; Square sphere.
global SquareSphere
SquareSphere:
section .text
push rbp
mov rbp, rsp

    mov eax, [rdi]
    mov ebx, eax
    imul eax, ebx
    imul eax, 3
    imul eax, 4

leave
ret

; Square Parallelepiped.
global SquareParallelepiped
SquareParallelepiped:
section .text
push rbp
mov rbp, rsp

    mov eax, [rdi]
    imul eax, [rdi+4]
    mov ebx, [rdi]
    imul ebx, [rdi+8]
    add eax, ebx
    mov ebx, [rdi+8]
    imul ebx, [rdi+4]
    add eax, ebx
    imul eax, 2

leave
ret

; Square tetrahedron.
global SquareTetrahedron
SquareTetrahedron:
section .data
    .i4     dq      4
section .text
push rbp
mov rbp, rsp

    mov eax, [rdi]
    mov ebx, eax
    imul eax, ebx
    imul eax, 2
    idiv qword[.i4]
    mov eax, edx

leave
ret

;----------------------------------------------
; Square of shape.
global SquareShape
SquareShape:
section .text
push rbp
mov rbp, rsp

    mov eax, [rdi]
    cmp eax, [SPHERE]
    je sphereSquare
    cmp eax, [PARALLELEPIPED]
    je parallelSquare
    cmp eax, [TETRAHEDRON]
    je tetrahedSquare
    xor eax, eax
    cvtsi2sd    xmm0, eax
    jmp     return
sphereSquare:
    add     rdi, 4
    call    SquareSphere
    jmp     return
parallelSquare:
    add     rdi, 4
    call    SquareParallelepiped
    jmp     return
tetrahedSquare:
    add     rdi, 4
    call    SquareTetrahedron
return:
leave
ret

;----------------------------------------------
; Sum of all squares.
global SquareSumContainer
SquareSumContainer:
section .data
    .sum    dq  0.0
section .text
push rbp
mov rbp, rsp

    mov ebx, esi            ; length shapes
    xor ecx, ecx            ; count shapes
    movsd xmm1, [.sum]
.loop:
    cmp ecx, ebx
    jge .return

    mov r10, rdi
    call SquareShape
    addsd xmm1, xmm0
    inc rcx
    add r10, 20
    mov rdi, r10
    jmp .loop
.return:
    movsd xmm0, xmm1
leave
ret
