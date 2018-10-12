/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_mapcheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 12:58:37 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/12 12:49:39 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"
#include <fcntl.h>

void			getpoints(t_piece *piece, char **map)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	MV_LAST(piece);
	y = piece->coord[0] - 1;
	while (++y < (piece->coord[0] + piece->height))
	{
		x = piece->coord[1] - 1;
		while (++x < (piece->coord[1] + piece->width))
		{
			piece->points[i] <<= 1;
			if (map[y][x] == '#')
				piece->points[i] += 1;
		}
		SET_INDEX(piece->points[i], i);
	}
}

static void		checkline(char *line, int *lines)
{
	char			*l;
	static int		i;
	int				hash;
	static int		start;

	l = line;
	CHECK_STARTNL(l, start);
	SET_FIRST_LINE(start);
	CHECK_NL(l, *lines);
	CHECK_NL_V(l, *lines, i);
	CHECK_NL_V(l, *lines, start);
	CHECK_NL_V_R(l, *lines);
	hash = FALSE;
	MV_NL(l);
	CHECK_NUM(l, line);
	l = line;
	while ((l - line) < 4)
	{
		CHECK_SIGN(l);
		COUNT_HASH(l, i);
		CHECK_HOR_FLAG(l, hash);
		SET_HOR_FLAG(l, hash);
		l++;
	}
	CHECK_HASH(i);
}

void			ft_countwidth(char **map, t_piece *piece)
{
	int		x;
	int		y;
	int		ym[2];
	int		xm[2];

	x = -1;
	ym[0] = INT_MAX;
	xm[0] = INT_MAX;
	ym[1] = 0;
	MV_LAST(piece);
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			SET_XMIN(map[y][x], xm[0], x);
			SET_MAX(map[y][x], xm[1], x);
			SET_XMIN(map[y][x], ym[0], y);
			SET_YMAX(map[y][x], ym[1], y);
		}
	}
	piece->width = xm[1] - xm[0] + 1;
	piece->height = ym[1] - ym[0] + 1;
	piece->coord[0] = ym[0];
	piece->coord[1] = xm[0];
}

static void		ft_itermap(char **map, int *lines, t_piece **pieces, int fd)
{
	int		i;

	i = 1;
	while (get_next_line(fd, &map[i]) == 1)
	{
		checkline(map[i], lines);
		if (!ft_strcmp(map[i], ""))
		{
			*lines = 0;
			ft_piecevalidate(map, pieces);
			*pieces = ft_pieceadd(pieces, ft_piecenew(0, 0));
			i = 0;
			continue ;
		}
		*lines += 1;
		i++;
	}
	if (map[0])
		ft_piecevalidate(map, pieces);
	else
		error();
}

t_piece			*ft_mapcheck(char *fn)
{
	int		fd;
	char	**map;
	int		lines;
	t_piece	*pieces;

	CHECK_NULL((map = malloc(5 * sizeof(char *))));
	CHECK_FD((fd = open(fn, O_RDONLY)));
	pieces = ft_piecenew(0, 0);
	lines = 0;
	CHECK_FIRSTLINE(get_next_line(fd, &map[0]));
	checkline(map[0], &lines);
	lines++;
	ft_itermap(map, &lines, &pieces, fd);
	free(map);
	close(fd);
	return (pieces);
}
