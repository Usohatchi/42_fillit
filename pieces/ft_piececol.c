/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piececol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:00:09 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/09 20:24:03 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_piececol(t_piece *p, t_board *b, int y, int x)
{
	int	i;

	i = 0;
	while (i < p->height)
	{
		if (CHK_COL(b->board[y + i], p->points[i] << (b->bmin - p->width - x)))
			return (1);
		i++;
	}
	return (0);
}
