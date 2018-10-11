/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:41:11 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/10 14:02:54 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_list
{
	int				fd;
	int				linel;
	int				buffl;
	char			buff[BUFF_SIZE];
	struct s_list	*next;
}				t_list;

char			*ft_strncpy(char *dst, const char *str, size_t n);
int				get_next_line(const int fd, char **line);

#endif
