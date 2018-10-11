/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:41:11 by eito-fis          #+#    #+#             */
/*   Updated: 2018/10/10 20:12:20 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# define TRUE 1
# define FALSE 0
# define CHK_COL(b, p) (b != ((b | p) ^ p))
# define MV_NL(x) while (*x != '\n' && *x) x++
# define MV_LAST(x) while (x->next) x = x->next

# define CHECK_NULL(x) if (x == NULL) error()
# define CHECK_NL(x, y) if (!ft_strcmp(x, "") && y != 4) error()
# define CHECK_NL_V(x, y, z) if (!ft_strcmp(x, "") && y == 4) z = 0
# define CHECK_NL_VL(x, z) if (!ft_strcmp(x, "")) z = 0
# define CHECK_NL_VLD(x) if (!ft_strcmp(x, "")) ft_strdel(&x)
# define CHECK_NL_VLC(x) if (!ft_strcmp(x, "")) continue 
# define CHECK_NL_V_R(x, y) if (!ft_strcmp(x, "") && y == 4) return 
# define CHECK_FD(x) if (x <= 2) error()
# define CHECK_FIRSTLINE(x) if (x == 0) error()
# define CHECK_NUM(x, y) if ((x - y) != 4) error()
# define CHECK_SIGN(x) if (*x != '.' && *x != '#') error()
# define CHECK_HASH(x) if (x > 4) error()
# define CHECK_HOR_FLAG(x, f) if (f == TRUE && *x == '#') error()
# define CHECK_STARTNL(x, f) if (!ft_strcmp(x, "") && f == FALSE) error()
# define SET_HOR_FLAG(x, f) if (*x == '#' && *(x + 1) != '#') f = TRUE
# define SET_PREV(x, y) if (x == NULL) x = y
# define SET_FIRST_LINE(f) if (f == FALSE) f = TRUE
# define SET_WIDTH(x, y, z) if ((x - y - 1) > z) z = (x - y - 1)
# define SET_INDEX(x, y) if (x > 0) y++
# define SET_HEIGHT(f, x) if (f == TRUE) x++
# define COUNT_HASH(x, y) if (*x == '#') y++
# define CHECK_LASTPOINT(x, y, z) if ((x - y) < 3) z = z << 1

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
int		ft_piececol(t_piece *p, t_board *b, int y, int x);
void	ft_setboard(t_piece *p, t_board *b, int y, int x);
void	ft_undoboard(t_piece *p, t_board *b, int y, int x);
void	ft_boardclean(long *arry, int l);
t_board	*fillit_solve(t_piece *pieces);
t_piece	*ft_piecenew(int w, int h);
t_piece	*ft_pieceadd(t_piece **head, t_piece *add);
t_piece	*ft_mapcheck(char *fn);
void	fillit_print(t_piece *p, t_board *b);
void	error(void);

#endif
