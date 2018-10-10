/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:15:29 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/09 19:25:44 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static int	ft_placepiece(int x, int y, t_piece *p, t_board *b)
{
	while (y <= b->bmin - p->height)
	{
		while (x <= b->bmin - p->height)
		{
			if (!ft_piececol(p, b, y))
			{
				ft_setboard(p, b, y);
				if (!p->next || ft_placepiece(x + 1, y, p->next, b))
				{
					p->xfinal = x;
					p->yfinal = y;
					return (1);
				}
				ft_undoboard(p, b, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

long		*fillit_solve(t_piece *pieces)
{
	t_board *b;
	
	b = malloc(sizeof(t_board));
	ft_boardclean(&(b->board), 26);
	b->bmin = ft_sqrt(ft_pieceslen(pieces) * 4);
	while (!ft_placepiece(0, 0, pieces, b))
		  (b->bmin)++;
}
