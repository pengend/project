;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/12 04:53:04 by pxia              #+#    #+#              ;
;    Updated: 2015/06/12 05:18:10 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_cat

	section .data

buff:		times 1024 db 0
buffsize:	equ $ - buff
	
	section .text

_ft_cat:
	mov rax, 0x2000003
	push rdi
	lea rsi, [rel buff]
	mov rdx, buffsize
	syscall
	jc end
	cmp rax, 0
	jle end
	mov rdi, 1
	mov rdx, rax
	mov rax, 0x2000004
	syscall
	pop rdi
	jmp _ft_cat

end:
	pop rdi
	ret