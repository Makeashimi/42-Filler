/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:57:51 by jcharloi          #+#    #+#             */
/*   Updated: 2017/05/19 16:45:32 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_env
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
	int		x;
	int		y;
}				t_env;

void			filler();
void			check_piece1(t_env *env);
void			check_piece2(t_env *env);

#endif
