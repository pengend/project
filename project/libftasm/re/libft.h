/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 23:42:35 by pxia              #+#    #+#             */
/*   Updated: 2015/06/12 19:14:32 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

void ft_bzero(void *s, size_t n);
char *ft_strcat(char *s1, const char *s2);
size_t ft_strlen(char *s);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_tolower(int c);
int ft_toupper(int c);
int ft_puts(char *s);
void *ft_memalloc(size_t size);
char *ft_strdup(char *s);
void *ft_memset(void *b, int c, size_t len);
void *ft_memcpy(void *dst, const void *src, size_t n);
void ft_cat(int fd);
char *ft_strchr(const char *s, int c);

#endif
