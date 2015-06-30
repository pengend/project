;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/12 01:32:36 by pxia              #+#    #+#              ;
;    Updated: 2015/06/29 17:09:19 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_puts
	extern _ft_strlen
	default rel
	section .data
newline:db 10				;work
nullMsg:db "(null)", 10, 0	;plz

	section .text

_ft_puts:
	cmp rdi, 0
	je _if_null
	call _ft_strlen
	mov rdx, rax
	mov rax, 0x2000004
	mov rsi, rdi
	mov rdi, 1
	syscall

end:
	mov rax, 0x2000004
	lea rsi, [newline]
	mov rdx, 1
	mov rdi, 1
	syscall
	mov rax, 1
	ret

_if_null:
    mov rax, 0x2000004
	lea rsi, [nullMsg]
	mov rdx, 8
	mov rdi, 1
	syscall
	mov rax, 1
	ret
