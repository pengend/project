;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/12 00:12:55 by pxia              #+#    #+#              ;
;    Updated: 2015/06/12 05:57:05 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_strlen

	section .text

_ft_strlen:
	push rdi
	mov rcx, -1
	xor al, al
	cld
	repne scasb
	mov rax, -2
	sub rax, rcx

end:
	pop rdi
	ret
