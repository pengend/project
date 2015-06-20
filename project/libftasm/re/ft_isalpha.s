;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/12 00:39:16 by pxia              #+#    #+#              ;
;    Updated: 2015/06/12 00:57:38 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_isalpha

	section .text

_ft_isalpha:
	mov rax, 0
	cmp rdi, 122
	jg end
	cmp rdi, 65
	jl end
	cmp rdi, 90
	jg _test
	jmp _yes

_test:
	cmp rdi, 97
	jl end
	
_yes:
	mov rax, 1
	
end:
	ret