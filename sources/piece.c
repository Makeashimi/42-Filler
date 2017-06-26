/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:16:38 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/06 17:36:10 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	count_min_piece(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	game->x_min_piece = -1;
	game->y_min_piece = -1;
	while (y < game->y_piece)
	{
		x = 0;
		while (game->piece[y][x] != '\0')
		{
			if (game->piece[y][x] == '*')
			{
				if (x < game->x_min_piece || game->x_min_piece == -1)
					game->x_min_piece = x;
				if (y < game->y_min_piece || game->y_min_piece == -1)
					game->y_min_piece = y;
			}
			x++;
		}
		y++;
	}
}

void	piece_to_top(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (y < game->y_piece)
	{
		x = 0;
		while (game->piece[y][x] != '\0')
		{
			if (game->piece[y][x] == '*')
			{
				game->piece[y - game->y_min_piece][x - game->x_min_piece] = '*';
				game->piece[y][x] = '.';
			}
			x++;
		}
		y++;
	}
}

void	count_max_piece(t_game *game)
{
	int		copy;
	int		y;
	int		x;

	y = 0;
	copy = game->y_piece;
	game->x_piece = -1;
	game->y_piece = -1;
	while (y < copy)
	{
		x = 0;
		while (game->piece[y][x] != '\0')
		{
			if (game->piece[y][x] == '*')
			{
				if (x >= game->x_piece || game->x_piece == -1)
					game->x_piece = x + 1;
				if (y >= game->y_piece || game->y_piece == -1)
					game->y_piece = y + 1;
			}
			x++;
		}
		y++;
	}
}
