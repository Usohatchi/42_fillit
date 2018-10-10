/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piececol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:00:09 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/09 19:22:34 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_piececol(t_piece *p, t_board *b, int y)
{
	int	i;

	i = 0;
	while (i < p->height)
	{
		if (CHK_COL(p->points[i] << b->bmin - p->width,
					b->board[y + i]))
			return (1);
		i++;
	}
	return (0);
}
