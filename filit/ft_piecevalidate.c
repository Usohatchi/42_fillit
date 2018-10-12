/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piecevalidate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 12:43:53 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/12 12:44:47 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_piecevalidate(char **map, t_piece **pieces)
{
	ft_countwidth(map, *pieces);
	getpoints(*pieces, map);
	ft_freemap(map);
}
