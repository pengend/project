/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 23:42:17 by pxia              #+#    #+#             */
/*   Updated: 2015/06/12 19:16:51 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "libft.h"

int main()
{
//	char t[10];

	char *s = (char*)ft_memalloc(10);
	char *s1 = "asdfg";

	ft_memcpy(s, s1, ft_strlen(s1));
	printf("%s\n", s);
	/*char t1[2];
//	int fd = open("main.c", O_RDONLY);
	
	t1[0] = '1';
	t1[1] = '\0';
	printf("bzero test : %s\n", t1);
	printf("strlen test : %zu\n", ft_strlen("asd"));
	printf("strcat test : %s\n", ft_strcat(t1, "ab"));
	printf("isalpha test : yes %d no %d yes %d no %d\n", ft_isalpha('z'), ft_isalpha('`'), ft_isalpha('A'), ft_isalpha(125));
	printf("isdigit test : yes %d no %d yes %d no %d\n", ft_isdigit('1'), ft_isdigit('/'), ft_isdigit('9'), ft_isdigit(':'));
	printf("isalnum test : yes %d no %d\n", ft_isalnum('1'), ft_isalnum('~'));
	printf("isascii test : yes %d no %d yes %d no %d\n", ft_isascii('\0'), ft_isascii(-12), ft_isascii(127), ft_isascii(200));
	printf("isprint test : yes %d no %d\n", ft_isprint(32), ft_isprint(127));
	printf("tolower test : A %c Z %c a %c ~ %c\n", ft_tolower('A'), ft_tolower('Z'), ft_tolower('a'), ft_tolower('~'));
	printf("toupper test : a %c z %c A %c ~ %c\n", ft_toupper('a'), ft_toupper('z'), ft_toupper('A'), ft_toupper('~'));
	ft_puts("Hello World");
	ft_strdup(10);
//	ft_puts(NULL);
//	puts(NULL);
//	ft_puts("asd");
//	ft_cat(fd);
//	ft_puts(ft_strchr("abcdefg\0", 'c'));

//	ft_puts(s);
//	ft_memset(s, 'a', ft_strlen(s));
*/
	return (0);
}
