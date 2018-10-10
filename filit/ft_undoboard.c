/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undoboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:04:05 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/09 20:23:59 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_undoboard(t_piece *p, t_board *b, int y, int x)
{
	int	i;

	i = 0;
	while (i < p->height)
	{
		b->board[y + i] ^= p->points[i] << (b->bmin - p->width - x);
		i++;
	}
}
