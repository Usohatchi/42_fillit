/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_mapcheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 12:58:37 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/10 20:05:12 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "get_next_line.h"
#include <fcntl.h>

static int		getpoints(t_piece **head, char *line, int i)
{
	t_piece		*piece;
	int			w;
	int			h;
	char		*l;

	l = line;
	w = 0;
	h = FALSE;
	piece = *head;
	MV_LAST(piece);
	while (*l)
	{
		if (*l == '#')
		{
			w++;
			piece->points[i] = piece->points[i] << 1;
			piece->points[i] += 1;
			h = TRUE;
			SET_WIDTH(l, line, piece->width);
		}
		l++;
	}
	SET_HEIGHT(h, piece->height);
	SET_INDEX(piece->points[i], i);
	return (i);
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

static void		ft_eamon(char *line, int *lines, t_piece **pieces, int fd)
{
	int		i;

	i = 1;
	while (get_next_line(fd, &line) == 1)
	{	
		checkline(line, lines);
		if (!ft_strcmp(line, ""))
		{
			*lines = 0;
			ft_strdel(&line);
			*pieces = ft_pieceadd(pieces, ft_piecenew(0, 0));
			i = 0;
			continue ;
		}
		*lines += 1;
		i = getpoints(pieces, line, i);
		ft_strdel(&line);
	}
}

t_piece			*ft_mapcheck(char *fn)
{
	int		fd;
	char	*line;
	int		lines;
	t_piece	*pieces;

	CHECK_FD((fd = open(fn, O_RDONLY)));
	pieces = ft_piecenew(0, 0);
	lines = 0;
	CHECK_FIRSTLINE(get_next_line(fd, &line));
	checkline(line, &lines);
	lines++;
	getpoints(&pieces, line, 0);
	ft_strdel(&line);
	ft_eamon(line, &lines, &pieces, fd);
	close(fd);
	return (pieces);
}