/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eito-fis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:41:11 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/09 19:23:28 by eito-fis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define CHK_COL(b, p) (b == ((b | p) ^ p))

typedef struct	s_piece
{
	long			points[4];
	int				width;
	int				height;
	int				xfinal;
	int				yfinal;
	struct s_piece	*next;
}				t_piece;

typedef	struct	s_board
{
	long	board[26];
	int		bmin;
}				t_board;

int		ft_pieceslen(t_piece *pieces);
int		ft_piececol(t_piece *p, t_board *b, int y);
void	ft_setboard(t_piece *p, t_board *b, int y);
void	ft_undoboard(t_piece *p, t_board *b, int y);
void	ft_boardclean(long **arry, int l);
long	*fillit_solve(t_piece *pieces);

#endif
