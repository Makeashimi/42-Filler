/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:26:44 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/02 21:42:10 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Parcourir ma map, retenir le x, y du premier X/O qu'il trouve;
** Determiner la distance entre ce x et mon point testé;
** ECRIS LE RESTE.
*/

int		get_distance(t_pos *pos, int y, int x)
{
	int		distance;

	distance = ft_abs(pos->ennemy_y - y) + ft_abs(pos->ennemy_x - x);
	return (distance);
}

void		find_the_ennemy(t_pos *pos)
{
	char	ennemy;
	int		ypiece;
	int		xpiece;
	int		count;
	int		i;
	int		j;
	
	i = 0;
	pos->distance = -1;
	if (pos->player == '1')
		ennemy = 'X';
	else
		ennemy = 'O';
	while (i < pos->y_board)
	{
		j = 0;
		while (pos->board[i][j] != '\0')
		{
			if (pos->board[i][j] == ennemy)
			{
				pos->ennemy_y = i;
				pos->ennemy_x = j;
				ypiece = 0;
				count = 0;
				while (ypiece < pos->y_piece)
				{
					xpiece = 0;
					while (pos->piece[ypiece][xpiece] != '\0')
					{
						if (pos->piece[ypiece][xpiece] == '*')
							count = count + get_distance(pos, pos->ybefore + ypiece, pos->xbefore + xpiece);
						xpiece++;
					}
					ypiece++;
				}
				if (count < pos->distance || pos->distance == -1)
					pos->distance = count;
			}
			j++;
		}
		i++;
	}
}
