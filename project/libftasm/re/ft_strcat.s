;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/12 00:00:56 by pxia              #+#    #+#              ;
;    Updated: 2015/06/30 06:46:25 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_strcat
	section .text

	_ft_strcat :
	mov rax, rdi

first:
	cmp [rdi], byte 0
	je next
	inc rdi
	jmp first

next:
	cmp [rsi], byte 0
	je end
	mov al, [rsi]
	mov [rdi], al
	inc rsi
	inc rdi
	jmp next
end:
	ret