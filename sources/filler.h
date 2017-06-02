/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:57:51 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/02 21:42:31 by jcharloi         ###   ########.fr       */
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

typedef struct	s_pos
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
	char	*forme;
	int		xbefore;
	int		ybefore;
	int		x;
	int		y;
	int		ennemy_x;
	int		ennemy_y;
	int		distance;
}				t_pos;

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
void			drawtab(t_env *env, t_pos *pos);
void			piece(t_pos *pos, t_env *env);
void			count_min_piece(t_pos *pos);
void			piece_to_top(t_pos *pos);
void			count_max_piece(t_pos *pos);
void			find_the_ennemy(t_pos *pos);
void			write_image(t_env *env, t_pos *pos);
int				init_window(t_env *env);

#endif
