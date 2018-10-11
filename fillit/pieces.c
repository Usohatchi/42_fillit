/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:07:55 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/10 18:18:52 by otahirov         ###   ########.fr       */
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

t_piece		*ft_piecenew(int w, int h)
{
	t_piece		*new_piece;
	int			i;

	CHECK_NULL((new_piece = malloc(sizeof(t_piece))));
	i = 0;
	new_piece->height = h;
	new_piece->width = w;
	new_piece->xfinal = 0;
	new_piece->yfinal = 0;
	while (i < 4)
		new_piece->points[i++] = 0;
	new_piece->next = NULL;
	return (new_piece);
}

t_piece		*ft_pieceadd(t_piece **head, t_piece *add)
{
	t_piece		*pieces;

	if (head == NULL || add == NULL)
		return (NULL);
	pieces = *head;
	while (pieces->next)
		pieces = pieces->next;
	pieces->next = add;
	return (*head);
}
