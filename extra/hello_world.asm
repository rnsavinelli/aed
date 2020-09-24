; hello_world.asm for i386
;
; Author: R. Nicolás Savinelli
; Date: 20-Oct-2019 
;
; to compile:
; $ nasm -f elf32 -o hello_world.o hello_world.asm
; $ ld -m elf_i386 -o hello_world hello_world.o

global _start

section .text:

    _start:
	mov eax, 0x04		; use the write syscall
	mov ebx, 1		; use stdout as the fd
	mov ecx, message	; use message as the buffer
	mov edx, message_length	; specify message's length
	int 0x80		; invoke the syscall

	mov eax, 0x01		; use the exit syscall
	mov ebx, 0x00		; specify return value
	int 0x80		; invoke syscall

section .data:
    message: db "Hello world!", 0x0A
    message_length equ $-message
