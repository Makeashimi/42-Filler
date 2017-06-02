/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:09:40 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/02 21:43:06 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Vérifications pour déterminer une position :
** (Tous les . + toutes les * = pièce)
** (Tous les points que si on fait i++ dans la pièce, on touche une étoile = la forme)
** - Checker pour la pièce que l'endroit où on veut la poser ne depasse pas de la map.
** - Qu'une seule étoile ne touche qu'un seul petit o/x et qu'elle ne touche aucun x.
** - Parcourir mon pos->board[x], trouver un o/x, vérifier qu'il n'y ait aucun
** autre o/x de placé, qu'elle touche une fois le petit o/x, qu'elle ne dépasse pas de la map.
** Pour vérifier que cela rentre dans la map, la pièce doit être calculée jusqu'a ce
** qu'il n'y ait plus de '*' dans la pièce entière.
*/

void	placepiece(t_pos *pos)
{
	ft_putnbr(pos->y);
	ft_putchar(' ');
	ft_putnbr(pos->x);
	ft_putchar('\n');
}

int		check_sup(t_pos *pos, int yboard, int xboard, char me, char ennemy)
{
	int		ypiece;
	int		xpiece;
	int		count;

	ypiece = 0;
	count = 0;
	while (ypiece < pos->y_piece)
	{
		xpiece = 0;
		while (pos->piece[ypiece][xpiece] != '\0')
		{
			if (pos->piece[ypiece][xpiece] == '*' && pos->board[yboard + ypiece][xboard + xpiece] == me)
				count++;
			if (pos->piece[ypiece][xpiece] == '*' && pos->board[yboard + ypiece][xboard + xpiece] == ennemy)
				return (0);
			xpiece++;
		}
		ypiece++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int		check_ennemy(t_pos *pos, int yboard, int xboard)
{
	char	me;
	char	ennemy;
	int		ok;

	if (pos->player == '1')
	{
		me = 'O';
		ennemy = 'X';
	}
	if (pos->player == '2')
	{
		me = 'X';
		ennemy = 'O';
	}
	ok = check_sup(pos, yboard, xboard, me, ennemy);
	return (ok);
}

int		check_size(t_pos *pos, int y, int x)
{
	if (x + pos->x_piece <= pos->x_board && y + pos->y_piece <= pos->y_board)
		return (0);
	return (1);
}



void	piece(t_pos *pos, t_env *env)
{
	int		x;
	int		y;
	int		close;

	y = 0;
	close = -2;
	(void)env;
	count_min_piece(pos);

	// ft_putchar_fd('\n', 2);
	// ft_putstr_fd("pos->y_min_piece : ", 2);
	// ft_putnbr_fd(pos->y_min_piece, 2);
	// ft_putchar_fd('\n', 2);
	// ft_putstr_fd("pos->x_min_piece: ", 2);
	// ft_putnbr_fd(pos->x_min_piece, 2);
	// ft_putchar_fd('\n', 2);

	if (pos->x_min_piece != 0 || pos->y_min_piece != 0)
		piece_to_top(pos);

	// ft_putchar_fd('\n', 2);
	// int i = 0;
	// while (i < pos->y_piece)
	// {
	// 	ft_putendl_fd(pos->piece[i], 2);
	//  	i++;
	// }

	count_max_piece(pos);

	// ft_putchar_fd('\n', 2);
	// ft_putstr_fd("pos->y_piece : ", 2);
	// ft_putnbr_fd(pos->y_piece, 2);
	// ft_putchar_fd('\n', 2);
	// ft_putstr_fd("pos->x_piece: ", 2);
	// ft_putnbr_fd(pos->x_piece, 2);
	// ft_putchar_fd('\n', 2);

	while (y < pos->y_board)
	{
		x = 0;
		while (x < pos->x_board)
		{
			if (check_size(pos, y, x) == 0 && check_ennemy(pos, y, x) == 1)
			{
				pos->xbefore = x - pos->x_min_piece;
				pos->ybefore = y - pos->y_min_piece;
				find_the_ennemy(pos);
				if (pos->distance < close || close == -2)
				{
					close = pos->distance;
					pos->x = pos->xbefore;
					pos->y = pos->ybefore;
				}
			}
			//write_image(env, pos);
			x++;
		}
		y++;
	}
	placepiece(pos);
}
