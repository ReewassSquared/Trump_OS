
[bits 16]
global start
start:
	mov di, 0				;move ds to zero
	mov ds, di				
	
	mov ah, 42H				;42h = read
	mov si, diskthingy		;si is a pointer to diskythingy
	int 13H					;call disk services
	
	mov ah, 0EH
	mov al, 'I'
	int 10H
	mov al, ' '
	int 10H
	mov al, 'w'
	int 10H
	mov al, 'i'
	int 10H
	mov al, 'l'
	int 10H
	mov al, 'l'
	int 10H
	mov al, ' '
	int 10H
	mov al, 'b'
	int 10H
	mov al, 'e'
	int 10H
	mov al, '.'
	int 10H
	mov al, '.'
	int 10H
	mov al, '.'
	int 10H


	xor ax, ax
	mov ax, 0
	int 16H

	mov ah, 0EH
	mov al, ' '
	mov bx, 68
	call printloop	
	mov al, 't'
	int 10H
	mov al, 'h'
	int 10H
	mov al, 'e'
	int 10H
	mov al, ' '
	int 10H
	mov al, 'g'
	int 10H
	mov al, 'r'
	int 10H
	mov al, 'e'
	int 10H
	mov al, 'a'
	int 10H
	mov al, 't'
	int 10H
	mov al, 'e'
	int 10H
	mov al, 's'
	int 10H
	mov al, 't'
	int 10H
	mov al, ' '
	int 10H
	mov al, 'O'
	int 10H
	mov al, 'p'
	int 10H
	mov al, 'e'
	int 10H
	mov al, 'r'
	int 10H
	mov al, 'a'
	int 10H
	mov al, 't'
	int 10H
	mov al, 'i'
	int 10H
	mov al, 'n'
	int 10H
	mov al, 'g'
	int 10H
	mov al, ' '
	int 10H
	mov al, 'S'
	int 10H
	mov al, 'y'
	int 10H
	mov al, 's'
	int 10H
	mov al, 't'
	int 10H
	mov al, 'e'
	int 10H
	mov al, 'm'
	int 10H
	mov al, '.'
	int 10H
	mov al, '.'
	int 10H
	mov al, '.'
	int 10H

	xor ax, ax
	mov ax, 0
	int 16H

	mov ah, 0EH
	mov al, ' '
	mov bx, 48
	call printloop	
	mov al, 't'
	int 10H	
	mov al, 'h'
	int 10H	
	mov al, 'a'
	int 10H	
	mov al, 't'
	int 10H	
	mov al, ' '
	int 10H	
	mov al, 'D'
	int 10H	
	mov al, '-'
	int 10H	
	mov al, 'T'
	int 10H	
	mov al, 'E'
	int 10H	
	mov al, 'K'
	int 10H	
	mov al, '.'
	int 10H
	mov al, '.'
	int 10H
	mov al, '.'
	int 10H

	xor ax, ax
	mov ax, 0
	int 16H

	mov ah, 0EH
	mov al, ' '
	mov bx, 67
	call printloop
	mov al, 'h'
	int 10H
	mov al, 'a'
	int 10H
	mov al, 's'
	int 10H
	mov al, ' '
	int 10H
	mov al, 'e'
	int 10H
	mov al, 'v'
	int 10H
	mov al, 'e'
	int 10H
	mov al, 'r'
	int 10H
	mov al, ' '
	int 10H
	mov al, 'c'
	int 10H
	mov al, 'r'
	int 10H
	mov al, 'e'
	int 10H
	mov al, 'a'
	int 10H
	mov al, 't'
	int 10H
	mov al, 'e'
	int 10H
	mov al, 'd'
	int 10H
	mov al, '.'
	int 10H
	mov al, '.'
	int 10H
	mov al, '.'
	int 10H

	xor ax, ax
	mov ax, 0
	int 16H
		

	jnc setup

	diskthingy:	db 16,0	
	.read_sector: dw 80
	.offset: dw 7e00h
	.segment: dw 0000h
	.end: dq 1H
	
printloop:
	jmp .start
	.start:
		int 10H
		cmp bx, 0
		je .end
		dec bx
		jmp .start
	.end:
		ret

;:::==========================================:::
;:::{{{{{{{{{{{{{{{{{GDT}}}}}}}}}}}}}}}}}}}}}}:::
;:::==========================================:::

gdtstart:				;GDT GUIDE !!!!!!!!
	dd 0				;16 bits null ('null descriptor' or whatever)
	dd 0					;start of code descriptor (where we define our 	executable code, i guess...)
	dw 0FFFFH			;this is the max we can set our segment registers (so we can load highest potental value in there)
	dw 0				;this is the segment starting address (0), so we can access from 0 to FFFFH
	db 0				;continuation of last section (with segment starter address)
	db 10011010B		;MAGICAL TABLE!!!! ;;;;;;;KEY;;;;;;;; (bits go least -> most significance: 76543210)
						;bit 0 == 'access bit' (dont worry about it, something called 'virtual memory' or some bullshit)
						;bit 1 == 'read/write bit' (1 for read/execute, 0 is for just execute)
						;bit 2 == 'expansion direction' don't quite know what it does, leave to 0
						;bit 3 == 'code/data descriptor' (this is a code descriptor, so we set to 1)
						;bit 4 == 'system/(code or data)' (again, this is code, so it is a 1)
						;bit 5-6 == 'permissions level' (0 == kernel, 3 == apps)
						;bit 7 == again, virtual memory. don't really know/care.
	db 11001111B		;another key
						;bits 0-3 == k20th address line max value (for when we enable the address line)
						;bits 4-5 == reserved/we just dont give a fuck
						;bit 6 == 16 (0) or 32 (1) bit (we want 1, since that's why we are doing this in the first place -_____-)
						;bit 7 == 'granulaity', set to 1 for 4 kB for something to do with segments.... (i fucking hate segments)
	db 0				;last byte of starting address for segments that was before the two 'magical tables' (wtf is this ordering...)
						;data descriptor (or whatever)
	dw 0FFFFH			;same thing basically
	dw 0				
	db 0				
	db 10010010B		;except we set the code descriptor bit to zero, because data descriptor!
	db 11001111B		
	db 0
	
gdtp: 
	dw gdtp - gdtstart - 1
	dd gdtstart
	
setup:
	mov ax, 03H			;setup VGA graphics mode for ease
	int 10H				
	
	in al, 0x92			;fast way of enabling a20
	or al, 2
	out 0x92, al

	cli					;disable interupt

	xor eax, eax			;sets up the code segment
	mov ax, 8H
	mov ax, ds

	lgdt [gdtp]			;global descriptor table
	xor eax, eax
	mov eax, cr0		;we need to set bit one of cr0 to enter protected
	or eax, 1			;so we set it in eax
	mov cr0, eax		;and move it back

	jmp 08H:entry		;far jump to clear all of the registers
	

times 510-($-$$) db 0
dw 0AA55H	;jump to the next step if successful (it just works this way for some reason...)		

[bits 32]

extern main
entry:
	mov ax, 10H
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	mov esp, 90000H
	mov [0B8003H], byte 'I'
	mov [0B8002H], byte 0FH
;	jmp hang

	call main


;hang:
;	jmp hang
	
global gdt_flush     ; Allows the C code to link to this
extern gptr            ; Says that '_gp' is in another file
gdt_flush:
    lgdt [gptr]        ; Load the GDT with our '_gp' which is a special pointer
    mov ax, 0x10      ; 0x10 is the offset in the GDT to our data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush2   ; 0x08 is the offset to our code segment: Far jump!
flush2:
    ret      
	
;loads idt!!!
global idt_load
extern iptr

idt_load:
	lidt [iptr]
	ret

global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31

isr0:   ;divide by 0
	cli
	push byte 0
	push byte 0
	jmp isr_common_stub

isr1:   ;debug exception
	cli
	push byte 0
	push byte 1
	jmp isr_common_stub

isr2:   ;non-maskable interrupt exception
	cli
	push byte 0
	push byte 2
	jmp isr_common_stub

isr3:   ;breakpoint exception
	cli
	push byte 0
	push byte 3
	jmp isr_common_stub

isr4:   ;into detected overflow exception
	cli
	push byte 0
	push byte 4
	jmp isr_common_stub

isr5:   ;out of bounds exception
	cli
	push byte 0
	push byte 5
	jmp isr_common_stub

isr6:   ;invalid opcode exception
	cli
	push byte 0
	push byte 6
	jmp isr_common_stub

isr7:   ;no coprocessor exception
	cli
	push byte 0
	push byte 7
	jmp isr_common_stub

isr8:   ;double fault exception
	cli
	push byte 8
	jmp isr_common_stub

isr9:   ;coprocessor segment overrun exception
	cli
	push byte 0
	push byte 9
	jmp isr_common_stub

isr10:   ;bad TSS exception
	cli
	push byte 10
	jmp isr_common_stub

isr11:   ;segment not present exception
	cli
	push byte 11
	jmp isr_common_stub

isr12:   ;stack fault exception
	cli
	push byte 12
	jmp isr_common_stub

isr13:   ;general protection fault exception
	cli
	push byte 13
	jmp isr_common_stub

isr14:   ;page fault exception
	cli
	push byte 14
	jmp isr_common_stub

isr15:   ;unknown interrupt exception
	cli
	push byte 0
	push byte 15
	jmp isr_common_stub

isr16:   ;coprocessor fault exception
	cli
	push byte 0
	push byte 16
	jmp isr_common_stub

isr17:   ;alignment check exception (486 and on)
	cli
	push byte 0
	push byte 17
	jmp isr_common_stub

isr18:   ;machine check exception (pentium/586 and on)
	cli
	push byte 0
	push byte 18
	jmp isr_common_stub

isr19:   ;reserved
	cli
	push byte 0
	push byte 19
	jmp isr_common_stub

isr20:   ;reserved
	cli
	push byte 0
	push byte 20
	jmp isr_common_stub

isr21:   ;reserved
	cli
	push byte 0
	push byte 21
	jmp isr_common_stub

isr22:   ;reserved
	cli
	push byte 0
	push byte 22
	jmp isr_common_stub

isr23:   ;reserved
	cli
	push byte 0
	push byte 23
	jmp isr_common_stub

isr24:   ;reserved
	cli
	push byte 0
	push byte 24
	jmp isr_common_stub

isr25:   ;reserved
	cli
	push byte 0
	push byte 25
	jmp isr_common_stub

isr26:   ;reserved
	cli
	push byte 0
	push byte 26
	jmp isr_common_stub

isr27:   ;reserved
	cli
	push byte 0
	push byte 27
	jmp isr_common_stub

isr28:   ;reserved
	cli
	push byte 0
	push byte 28
	jmp isr_common_stub

isr29:   ;reserved
	cli
	push byte 0
	push byte 29
	jmp isr_common_stub

isr30:   ;reserved
	cli
	push byte 0
	push byte 30
	jmp isr_common_stub

isr31:   ;reserved
	cli
	push byte 0
	push byte 31
	jmp isr_common_stub

extern fault_handler

isr_common_stub:
	pusha
	push ds
	push es
	push fs
	push gs
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov eax, esp
	push eax
	mov eax, fault_handler
	call eax
	pop eax
	pop gs
	pop fs
	pop es
	pop ds
	popa
	add esp, 8
	iret

global irq0
global irq1
global irq2
global irq3
global irq4
global irq5
global irq6
global irq7
global irq8
global irq9
global irq10
global irq11
global irq12
global irq13
global irq14
global irq15

irq0:
	cli
	push 0
	push byte 32
	jmp irq_common_stub
irq1:
	cli
	push 0
	push byte 33
	jmp irq_common_stub

irq2:
	cli
	push 0
	push byte 34
	jmp irq_common_stub

irq3:
	cli
	push 0
	push byte 35
	jmp irq_common_stub

irq4:
	cli
	push 0
	push byte 36
	jmp irq_common_stub

irq5:
	cli
	push 0
	push byte 37
	jmp irq_common_stub

irq6:
	cli
	push 0
	push byte 38
	jmp irq_common_stub

irq7:
	cli
	push 0
	push byte 39
	jmp irq_common_stub

irq8:
	cli
	push 0
	push byte 40
	jmp irq_common_stub

irq9:
	cli
	push 0
	push byte 41
	jmp irq_common_stub

irq10:
	cli
	push 0
	push byte 42
	jmp irq_common_stub

irq11:
	cli
	push 0
	push byte 43
	jmp irq_common_stub

irq12:
	cli
	push 0
	push byte 44
	jmp irq_common_stub

irq13:
	cli
	push 0
	push byte 45
	jmp irq_common_stub

irq14:
	cli
	push 0
	push byte 46
	jmp irq_common_stub

irq15:
	cli
	push 0
	push byte 47
	jmp irq_common_stub

extern irq_handler

irq_common_stub:
	pusha
	push ds
	push es
	push fs
	push gs
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov eax, esp
	push eax
	mov eax, irq_handler
	call eax
	pop eax
	pop gs
	pop fs
	pop es
	pop ds
	popa
	add esp, 8
	iret

global stack_loc
stack_loc:
	mov eax, [esp]
	
	xor eax, eax

; Here is the definition of our BSS section. Right now, we'll use
; it just to store the stack. Remember that a stack actually grows
; downwards, so we declare the size of the data before declaring
; the identifier '_sys_stack'
SECTION .bss
    resb 8192               ; This reserves 8KBytes of memory here
sys_stack:
