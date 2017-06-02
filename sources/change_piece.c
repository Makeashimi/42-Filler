/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:16:38 by jcharloi          #+#    #+#             */
/*   Updated: 2017/05/31 11:43:01 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	count_min_piece(t_pos *pos)
{
	int		y;
	int		x;

	y = 0;
	pos->x_min_piece = -1;
	pos->y_min_piece = -1;
	while (y < pos->y_piece)
	{
		x = 0;
		while (pos->piece[y][x] != '\0')
		{
			if (pos->piece[y][x] == '*')
			{
				if (x < pos->x_min_piece || pos->x_min_piece == -1)
					pos->x_min_piece = x;
				if (y < pos->y_min_piece || pos->y_min_piece == -1)
					pos->y_min_piece = y;
			}
			x++;
		}
		y++;
	}
}

void	piece_to_top(t_pos *pos)
{
	int		y;
	int		x;

	y = 0;
	while (y < pos->y_piece)
	{
		x = 0;
		while (pos->piece[y][x] != '\0')
		{
			if (pos->piece[y][x] == '*')
			{
				pos->piece[y - pos->y_min_piece][x - pos->x_min_piece] = '*';
				pos->piece[y][x] = '.';
			}
			x++;
		}
		y++;
	}
}

void	count_max_piece(t_pos *pos)
{
	int		copy;
	int		y;
	int		x;

	y = 0;
	copy = pos->y_piece;
	pos->x_piece = -1;
	pos->y_piece = -1;
	while (y < copy)
	{
		x = 0;
		while (pos->piece[y][x] != '\0')
		{
			if (pos->piece[y][x] == '*')
			{
				if (x >= pos->x_piece || pos->x_piece == -1)
					pos->x_piece = x + 1;
				if (y >= pos->y_piece || pos->y_piece == -1)
					pos->y_piece = y + 1;
			}
			x++;
		}
		y++;
	}
}
