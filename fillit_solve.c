/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:15:29 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/09 18:41:48 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

long	*fillit_solve(t_piece *pieces)
{
	long	board[26];
	int		bmin;
	
	ft_boardclean(&board, 26);
	bmin = ft_sqrt(ft_pieceslen(pieces) * 4);
}
