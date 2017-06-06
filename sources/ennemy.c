/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:26:44 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/06 17:22:41 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Parcourir ma map, retenir le x, y du premier X/O qu'il trouve;
** Determiner la distance entre ce x et mon point testé;
** C
*/

static int		get_distance(t_game *game, int y, int x)
{
	int		distance;

	distance = ft_abs(game->ennemy_y - y) + ft_abs(game->ennemy_x - x);
	return (distance);
}

static int		check_sup(t_game *game, int yboard, int xboard)
{
	int		ypiece;
	int		xpiece;
	int		count;

	ypiece = 0;
	count = 0;
	while (ypiece < game->y_piece)
	{
		xpiece = 0;
		while (game->piece[ypiece][xpiece] != '\0')
		{
			if (game->piece[ypiece][xpiece] == '*' &&
					game->board[yboard + ypiece][xboard + xpiece] == game->me)
				count++;
			if (game->piece[ypiece][xpiece] == '*' &&
				game->board[yboard + ypiece][xboard + xpiece] == game->ennemy)
				return (0);
			xpiece++;
		}
		ypiece++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int				who_is_my_ennemy(t_game *game, int yboard, int xboard)
{
	int		ok;

	if (game->player == '1')
	{
		game->me = 'O';
		game->ennemy = 'X';
	}
	if (game->player == '2')
	{
		game->me = 'X';
		game->ennemy = 'O';
	}
	ok = check_sup(game, yboard, xboard);
	return (ok);
}

void			strategy(t_game *game)
{
	int		count;
	int		ypiece;
	int		xpiece;

	ypiece = 0;
	count = 0;
	while (ypiece < game->y_piece)
	{
		xpiece = 0;
		while (game->piece[ypiece][xpiece] != '\0')
		{
			if (game->piece[ypiece][xpiece] == '*')
				count = count + get_distance(game, game->ybefore +
										ypiece, game->xbefore + xpiece);
			xpiece++;
		}
		ypiece++;
	}
	if (count < game->distance || game->distance == -1)
		game->distance = count;
}

void			find_the_ennemy(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	game->distance = -1;
	while (i < game->y_board)
	{
		j = 0;
		while (game->board[i][j] != '\0')
		{
			if (game->board[i][j] == game->ennemy)
			{
				game->ennemy_y = i;
				game->ennemy_x = j;
				strategy(game);
			}
			j++;
		}
		i++;
	}
}
