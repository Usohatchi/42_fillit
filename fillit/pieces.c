/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:07:55 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/10 13:22:52 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/**
 * @param: w = width of the shape
 * @param: h = height of the shape
 * @param: p = Array of points in binary
 * @return: Initialized piece
 * @description: Initializes a piece with the @params
 */

t_piece		*ft_piecenew(int w, int h, long *p)
{
	t_piece		*new_piece;
	int			i;

	if (w == 0 || h == 0 || p == NULL)
		exit (NULL);
	CHECK_NULL(new_piece = malloc(sizeof(t_piece)));
	i = 0;
	new_piece->height = h;
	new_piece->width = w;
	new_piece->xfinal = 0;
	new_piece->yfinal = 0;
	while (i < 4)
	{
		new_piece->points[i] = p[i];
		i++;
	}
	new_piece->next = NULL;
	return (new_piece);
}