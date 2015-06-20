;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strchr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/12 05:23:40 by pxia              #+#    #+#              ;
;    Updated: 2015/06/12 06:05:51 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_strchr

	section .text

_ft_strchr:
	push rdi
	cmp rdi, 0
	je end

_loop:
	cmp byte[rdi], 0
	je end
	cmp rdi, rsi
	je end
	inc rdi
	jmp _loop

end:
	pop rax
	ret