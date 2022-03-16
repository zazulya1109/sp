.data

print_format:
	.string "Получается что: %d\n"

arr:
	.long 10,-12,2,7,3,-44,150,8,-9,17
arr_end:

.text
.globl main
.type main, @function

main:
	movl $0, %ecx
	movl $arr, %ebx
	movl (%ebx), %eax

jmp bound

start:
	cmpl $0, (%ebx)
	jg ok
	notl (%ebx)
	addl $1, (%ebx)

ok:
	add (%ebx), %ecx
	addl $4, %ebx
	movl (%ebx), %eax

bound:
	cmpl $arr_end, %ebx
	jne start

push %ecx
push $print_format
call printf
addl $8, %esp
movl $0, %ecx
movl $0, %ebx
movl $0, %eax
ret


