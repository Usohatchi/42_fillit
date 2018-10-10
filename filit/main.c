/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:30:00 by otahirov          #+#    #+#             */
/*   Updated: 2018/10/09 20:28:36 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	t_piece *piece;
	t_piece *piece2;
	t_piece *piece3;
	t_board *board;

	piece = malloc(sizeof(t_piece));
	piece2 = malloc(sizeof(t_piece));
	piece3 = malloc(sizeof(t_piece));
	piece->height = 3;
	piece->width = 2;
	piece->xfinal = 0;
	piece->yfinal = 0;
	piece->points[0] = 3;
	piece->points[1] = 1;
	piece->points[2] = 1;
	piece->points[3] = 0;
	piece->next = piece2;
	piece2->height = 2;
	piece2->width = 2;
	piece2->xfinal = 0;
	piece2->yfinal = 0;
	piece2->points[0] = 3;
	piece2->points[1] = 3;
	piece2->next = piece3;
	piece3->height = 3;
	piece3->width = 2;
	piece3->xfinal = 0;
	piece3->yfinal = 0;
	piece3->points[0] = 3;
	piece3->points[1] = 2;
	piece3->points[2] = 2;
	piece3->next = NULL;
	board = fillit_solve(piece);
	printf("%li\n", board->board[0]);
	printf("%li\n", board->board[1]);
	printf("%li\n", board->board[2]);
	printf("%li\n", board->board[3]);
	printf("%i", board->bmin);
	return (0);
}