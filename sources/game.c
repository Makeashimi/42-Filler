/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:09:40 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/15 16:31:35 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Vérifications pour déterminer une position :
** (Tous les . + toutes les * = pièce)
** (Tous les points que si on fait i++ dans la pièce, on touche une étoile =
** la forme)
** - Checker pour la pièce que l'endroit où on veut la poser ne depasse pas
** de la map.
** - Qu'une seule étoile ne touche qu'un seul petit o/x et qu'elle ne touche
** aucun x/o ennemi.
*/

static void		placepiece(t_game *game)
{
	ft_putnbr(game->y);
	ft_putchar(' ');
	ft_putnbr(game->x);
	ft_putchar('\n');
}

static int		check_size(t_game *game, int y, int x)
{
	if (x + game->x_piece <= game->x_board &&
								y + game->y_piece <= game->y_board)
		return (0);
	return (1);
}

static void		play(t_game *game, int close, int y)
{
	int x;

	while (y < game->y_board)
	{
		x = 0;
		while (x < game->x_board)
		{
			if (check_size(game, y, x) == 0 && who_is_my_enemy(game, y, x))
			{
				game->xbefore = x - game->x_min_piece;
				game->ybefore = y - game->y_min_piece;
				find_the_enemy(game);
				if (game->distance < close || close == -2)
				{
					close = game->distance;
					game->x = game->xbefore;
					game->y = game->ybefore;
				}
			}
			x++;
		}
		y++;
	}
}

void			start_the_game(t_game *game)
{
	int		y;
	int		close;

	y = 0;
	close = -2;
	count_min_piece(game);
	if (game->x_min_piece != 0 || game->y_min_piece != 0)
		piece_to_top(game);
	count_max_piece(game);
	play(game, close, y);
	placepiece(game);
}
