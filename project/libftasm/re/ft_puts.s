;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/12 01:32:36 by pxia              #+#    #+#              ;
;    Updated: 2015/06/12 05:53:12 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_puts

	extern _ft_strlen

	section .data
	
	newline db 0x0a
	
	section .text

_ft_puts:
	call _ft_strlen
	mov rdx, rax
	mov rax, 0x2000004
	mov rsi, rdi
	mov rdi, 1
	syscall
	
end:	
	mov rax, 0x2000004
	lea rsi, [rel newline]
	mov rdx, 1
	syscall
	
	ret
