/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:57:51 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/06 17:21:57 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "../mlxE3/mlx.h"

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
	char	ennemy;
	int		xbefore;
	int		ybefore;
	int		x;
	int		y;
	int		ennemy_x;
	int		ennemy_y;
	int		distance;
}				t_game;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bits;
	int		size;
	int		endian;
	int		color;
	int		zoom;
	int		zoom_y;
}				t_env;

void			filler();
void			start_the_game(t_game *game, t_env *env);
int				who_is_my_ennemy(t_game *game, int yboard, int xboard);
void			count_min_piece(t_game *game);
void			piece_to_top(t_game *game);
void			count_max_piece(t_game *game);
void			find_the_ennemy(t_game *game);

#endif
