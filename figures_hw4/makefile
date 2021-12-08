# makefile for task.asm
task: main.o
	gcc -g -o task main.o -no-pie
main.o: main.asm
	nasm -f elf64 -g -F dwarf main.asm -l main.lst
