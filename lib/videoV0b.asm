; Kernel now can be written in ASM and C
; This is ASM part for display using b8000
; Assume es has GDT_video = b8000
; Every parameter is 32 bits (4 dd)
;04/17/2017

 
			[bits 32]
			;align 32

[section .data]
disp_pos	dd	0
color_attr	db	0x2f				

[section .text]

global	__disp_str					;__ : asm util file, _ : c util file
global __disp_clk
; ========================================================================
; Func 1) -- void __disp_str(u8_t * string, u32_t color);
; ========================================================================
__disp_str:

	push ebp
	mov ebp, esp

	mov	 esi, [ebp + 8]					;pszInfo
										;		ss  color_attr(4)
										;		ss    char_ptr (4)
										;		ss         ret_ip (4)
										;		ss    push ebp (4)
										;stack esp -> 
	mov ebx, [ebp + 12]
	mov [color_attr], bl					;color enter stack first
											;use u8_t from u32_t passed by stack
	mov	 edi, [disp_pos]
	mov	 ah, [color_attr]

.1:
	lodsb
	test	al, al
	jz .3									;end of string, stop

	cmp	al, 0Ah							;enter key?
	jnz .2
	
	push eax
	mov	 eax, edi
	mov	 bl, 160
	div	bl
	and	eax, 0FFh
	inc	eax
	mov	 bl, 160
	mul	bl
	mov	 edi, eax
	pop	eax
	jmp	.1

.2:
	mov	 [es:edi], ax						;assume es->0xb8000
	add	edi, 2
	jmp	.1

.3:
	mov	[disp_pos], edi

	pop	ebp
	ret
; ========================================================================
; Func 2) -- void __disp_str(u8_t * string, u32_t color);
; ========================================================================
__disp_clk:

	push ebp
	mov ebp, esp

	mov	 esi, [ebp + 8]					;pszInfo
										;		ss  color_attr(4)
										;		ss    char_ptr (4)
										;		ss         ret_ip (4)
										;		ss    push ebp (4)
										;stack esp -> 
	mov ebx, [ebp + 12]
	mov [color_attr], bl					;color enter stack first
											;use u8_t from u32_t passed by stack
	mov	 edi, 144
	mov	 ah, [color_attr]

.1:
	lodsb
	test	al, al
	jz .3									;end of string, stop

	cmp	al, 0Ah							;enter key?
	jnz .2
	
	push eax
	mov	 eax, edi
	mov	 bl, 160
	div	bl
	and	eax, 0FFh
	inc	eax
	mov	 bl, 160
	mul	bl
	mov	 edi, eax
	pop	eax
	jmp	.1

.2:
	mov	 [es:edi], ax						;assume es->0xb8000
	add	edi, 2
	jmp	.1

.3:
	;mov	[disp_pos], edi

	pop	ebp
	ret
	
