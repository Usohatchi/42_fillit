/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 12:58:13 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/10 15:12:26 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	ft_printboardmake(t_piece *p, int bmin, char *str)
{
	char	*alpha;
	int		i;
	int		w;

	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = 0;
	while (p)
	{
		while (--(p->height) >= 0)
		{
			w = p->width;
			while (--w >= 0)
			{
				if ((p->points)[p->height] % 2 == 1)
					str[(p->xfinal + p->yfinal * bmin) +
						(w + p->height * bmin)] = alpha[i];
				p->points[p->height] = p->points[p->height] >> 1;
			}
		}
		i++;
		p = p->next;
	}
}

void	fillit_print(t_piece *p, t_board *b)
{
	int		cells;
	int		i;
	char	*str;

	cells = b->bmin * b->bmin;
	str = (char*)malloc(sizeof(char) * (cells + b->bmin));
	i = 0;
	while (i < cells + b->bmin)
	{
		str[i] = '.';
		if ((i + 1) % (b->bmin + 1) == 0)
			str[i] = '\n';
		i++;
	}
	ft_printboardmake(p, b->bmin + 1, str);
	write(1, str, cells + b->bmin);
	free(str);
}


