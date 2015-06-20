;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/12 00:00:56 by pxia              #+#    #+#              ;
;    Updated: 2015/06/12 00:32:23 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_strcat

	extern _ft_strlen

	section .text

_ft_strcat:
	call _ft_strlen
	mov rcx, 0

_loop:
	cmp byte[rsi+rcx], 0
	je end
	mov r8, [rsi+rcx]
	mov [rdi+rax], r8
	inc rcx
	inc rax
	jmp _loop

end:
	mov byte[rdi+rax], 0
	mov rax, rdi
	ret
