;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/06/12 00:59:19 by pxia              #+#    #+#              ;
;    Updated: 2015/06/12 01:03:25 by pxia             ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global _ft_isalnum

	extern _ft_isalpha
	extern _ft_isdigit
	
	section .text

_ft_isalnum:
	call _ft_isalpha
	cmp rax, 1
	je end
	call _ft_isdigit

end:
	ret