;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/11 23:54:53 by pxia              #+#    #+#              ;
;    Updated: 2015/06/12 00:55:12 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_bzero

	section .text

_ft_bzero:
	cmp rdi, 0
	je end
	cmp rsi, 0
	je end
	mov rbx, rdi
	mov rax, rsi

_loop:
	mov byte[rbx], 0
	inc rbx
	dec rax
	cmp rax, 0
	je end
	jmp _loop
	
end:
	ret
	