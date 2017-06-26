/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:57:51 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/16 17:02:04 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

/*
** player : Player 1 or 2.
** x/y_board : Size of board.
** x/ymin_piece : Number of . before * in my piece.
** x/y_piece : Number of * before . in my piece.
** board : Get the board.
** piece : Get the piece.
** me/ennemy : Check if I'm O or X.
** x/ybefore : Potential x/y to place.
** x/y : Definitive x/y to place.
** ennemy_x/y : Coordinate of my ennemy.
** distance : Distance between my potential piece and the ennemy.
*/

typedef struct	s_game
{
	char	player;
	int		y_board;
	int		x_board;
	int		x_min_piece;
	int		y_min_piece;
	int		y_piece;
	int		x_piece;
	char	**board;
	char	**piece;
	char	me;
	char	enemy;
	int		xbefore;
	int		ybefore;
	int		x;
	int		y;
	int		enemy_x;
	int		enemy_y;
	int		distance;
}				t_game;

void			filler();
void			get_map(t_game *game);
void			get_piece(t_game *game);
void			start_the_game(t_game *game);
int				who_is_my_enemy(t_game *game, int yboard, int xboard);
void			count_min_piece(t_game *game);
void			piece_to_top(t_game *game);
void			count_max_piece(t_game *game);
void			find_the_enemy(t_game *game);

#endif
