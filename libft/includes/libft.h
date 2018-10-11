/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:07:58 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/10 18:22:50 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

void			ft_putchar(char c);
void			ft_putstr(const char *str);
void			ft_putendl(const char *str);
void			ft_putnbr(int i);
void			ft_putnbruns(unsigned int i);
void			ft_putaddrs(int i);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *str);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(char *str, int n);
void			*ft_memcpy(void *restrict dst,
		const void *restrict src, size_t n);
void			*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t l);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
char			*ft_strcat(char	*restrict str1, char *restrict str2);
char			*ft_strncat(char *restrict str1, char *restrict str2, size_t n);
size_t			ft_strlcat(char *restrict dst, char *restrict src, size_t n);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *hay, const char *ndl);
char			*ft_strnstr(const char *hay, const char *ndl, size_t l);
void			*ft_memalloc(size_t size);
void			ft_memdel(void	**ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *str);
void			ft_striter(char *str, void (*f)(char*));
void			ft_striteri(char *str, void (*f)(unsigned int, char*));
char			*ft_strmap(const char *str, char (*f)(char));
char			*ft_strmapi(const char *str, char (*f)(unsigned int, char));
int				ft_strequ(const char *str1, const char *str2);
int				ft_strnequ(const char *str1, const char *str2, size_t n);
char			*ft_strsub(const char *str, unsigned int start, size_t l);
char			*ft_strjoin(const char *str1, const char *str2);
char			*ft_strtrim(const char *str);
char			**ft_strsplit(const char *str, char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putendl_fd(const char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
size_t			ft_getdigits(int n);
int				ft_power(int base, int pwr);
void			*ft_realloc(void *ptr, size_t cur, size_t l);
char			*ft_strappend(char *str, char *add, size_t cur, size_t f);
int				ft_sqrt(int i);

#endif
