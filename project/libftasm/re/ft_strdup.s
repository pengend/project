;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/12 03:56:04 by pxia              #+#    #+#              ;
;    Updated: 2015/06/12 20:35:13 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_strdup
	
	extern _ft_memcpy
	
	section .text

_ft_strdup:
	call _ft_strlen
	add rax, 1
	mov rdi, rax
	mov r8, rdi
	push r8
	call _malloc
	mov rdx, rdi
	mov rdi, rax
	pop rsi
	call _ft_memcpy
	
end:
	ret
