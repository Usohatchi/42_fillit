/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:30:00 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/10 19:26:55 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

void	error(void)
{
	write(1, "error\n", 6);
	exit (EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	t_piece		*piece;
	t_board		*board;

	if (ac != 2)
		error();
	piece = ft_mapcheck(av[1]);
	board = fillit_solve(piece);
	printf("%li\n", board->board[0]);
	printf("%li\n", board->board[1]);
	printf("%li\n", board->board[2]);
	printf("%li\n", board->board[3]);
	printf("%i", board->bmin);
	return (0);
}