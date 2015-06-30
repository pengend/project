;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/12 03:56:04 by pxia              #+#    #+#              ;
;    Updated: 2015/06/29 15:08:52 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_strdup
	extern _ft_memalloc
	extern _ft_strlen
	extern _ft_memcpy
	section .text

_ft_strdup:
	push rdi
	call _ft_strlen
	mov rdi, rax
	mov rdx, rdi
	call _ft_memalloc
	mov rdi, rax
	pop rsi
	call _ft_memcpy
	
end:
	ret
