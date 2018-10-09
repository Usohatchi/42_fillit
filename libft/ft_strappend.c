/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:31:25 by eito-fis          #+#    #+#             */
/*   Updated: 2018/09/27 14:27:47 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *str, char *add, size_t s, size_t c)
{
	size_t i;

	if (s == 0)
		str = (char*)malloc(sizeof(char) * c);
	else
		str = (char*)ft_realloc(str, s, s + c);
	if (!str)
		return (NULL);
	i = 0;
	while (i < c)
	{
		str[s] = add[i];
		s++;
		i++;
	}
	return (str);
}
