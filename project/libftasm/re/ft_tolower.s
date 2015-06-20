;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/12 01:22:03 by pxia              #+#    #+#              ;
;    Updated: 2015/06/12 01:23:04 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_tolower

	section .text

_ft_tolower:
	mov rax, rdi
	cmp rax, 65
	jl end
	cmp rax, 90
	jg end
	add rax, 32

end:
	ret