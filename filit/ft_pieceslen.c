/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieceslen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:26:43 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/10 12:42:46 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_pieceslen(t_piece *pieces)
{
	int ret;

	ret = 0;
	while (pieces)
	{
		pieces = pieces->next;
		ret++;
	}
	return (ret);
}
