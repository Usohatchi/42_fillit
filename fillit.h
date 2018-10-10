/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:41:11 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/09 18:55:53 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "libft.h"

typedef struct	s_list
{
	long			points[4];
	int				width;
	int				height;
	struct s_list	*next;
}				t_piece;

typedef	struct	s_board
{
	long	board[26];
	int		bmin;
}				t_board;

int		ft_pieceslen(t_piece *pieces);
void	ft_boardclean(long **arry, int l);
long	*fillit_solve(t_piece *pieces);

#endif
