;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memalloc.s                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/12 19:11:37 by pxia              #+#    #+#              ;
;    Updated: 2015/06/12 19:26:06 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_memalloc

	extern _malloc
	extern _ft_bzero

	section .text

_ft_memalloc:
	push rdi
	call _malloc
	cmp rax, 0
	je end
	pop rdi
	push rdi
	push rax
	mov rsi, rdi
	mov rdi, rax
	call _ft_bzero
	pop rax

end:
	pop rdi
	ret