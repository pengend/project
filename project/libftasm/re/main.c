/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 23:42:17 by pxia              #+#    #+#             */
/*   Updated: 2015/06/30 06:48:21 by pxia             ###   ########.fr       */
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
	char t1[2];
	int fd = open("main.c", O_RDONLY);
	char buf[9];

	ft_bzero(buf, 9);
	ft_strcat(buf, "Ba");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	printf("%s\n", buf);
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
	ft_puts("aaa\n(null)\n");
	ft_puts("aaa");
	ft_puts(NULL);
	ft_cat(fd);

	return (0);
}
