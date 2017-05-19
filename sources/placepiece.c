/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placepiece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:09:40 by jcharloi          #+#    #+#             */
/*   Updated: 2017/05/19 17:09:32 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Vérifications pour déterminer une position :
** (Tous les . + toutes les * = pièce)
** (Tous les points que si on fait i++ dans la pièce, on touche une étoile = la forme)
** - Checker pour la pièce que l'endroit où on veut la poser ne depasse pas de la map.
** - Qu'une seule étoile ne touche qu'un seul petit o/x et qu'elle ne touche aucun x.
** - Parcourir mon env->board[x], trouver un o/x, vérifier qu'il n'y ait aucun
** autre o/x de placé, qu'elle touche une fois le petit o/x, qu'elle ne dépasse pas de la map.
** Pour vérifier que cela rentre dans la map, la pièce doit être calculée jusqu'a ce
** qu'il n'y ait plus de '*' dans la pièce entière.
*/

void	placepiece(t_env *env)
{
	ft_putnbr(env->x);
	ft_putchar(' ');
	ft_putnbr(env->y);
	ft_putchar('\n');
}

int		check_size(t_env *env, int y, int x)
{
	// ft_putchar_fd('\n', 2);
	// ft_putstr_fd("y : ", 2);
	// ft_putnbr_fd(y, 2);
	// ft_putchar_fd('\n', 2);
	// ft_putstr_fd("x : ", 2);
	// ft_putnbr_fd(x, 2);
	// ft_putchar_fd('\n', 2);
	//ft_putstr_fd("env->y_piece : ", 2);
	// ft_putnbr_fd(env->y_piece, 2);
	// ft_putchar_fd('\n', 2);
	//ft_putstr_fd("env->x_piece : ", 2);
	//ft_putnbr_fd(env->x_piece, 2);
	//ft_putchar_fd('\n', 2);
	if (x + env->x_piece <= env->x_board && y + env->y_piece <= env->y_board)
		return (0);
	return (1);
}

int		check_sup(t_env *env, int y, int x)
{
	(void)env;
	(void)y;
	(void)x;
	return (0);
}

void	count_max_piece(t_env *env)
{
	int		copy;
	int		y;
	int		x;

 	y = 0;
	copy = env->y_piece;
	env->x_piece = -1;
	env->y_piece = -1;
	while (y < copy)
	{
		x = 0;
		while (env->piece[y][x] != '\0')
		{
			if (env->piece[y][x] == '*')
			{
				if (x >= env->x_piece || env->x_piece == -1)
					env->x_piece = x + 1;
				if (y >= env->y_piece || env->y_piece == -1)
					env->y_piece = y + 1;
			}
			x++;
		}
		y++;
	}
}

void	piece_to_top(t_env *env)
{
	int		y;
	int		x;
				
	y = 0;
	while (y < env->y_piece)
	{
		x = 0;
		while (env->piece[y][x] != '\0')
		{
			if (env->piece[y][x] == '*')
			{
				// ft_putstr_fd("y : ", 2);
				// ft_putnbr_fd(y, 2);
				// ft_putchar_fd('\n', 2);
				// ft_putstr_fd("x : ", 2);
				// ft_putnbr_fd(x, 2);
				// ft_putchar_fd('\n', 2);
				// ft_putstr_fd("env->y_min_piece : ", 2);
				// ft_putnbr_fd(env->y_min_piece, 2);
				// ft_putchar_fd('\n', 2);
				// ft_putstr_fd("env->x_min_piece: ", 2);
				// ft_putnbr_fd(env->x_min_piece, 2);
				// ft_putchar_fd('\n', 2);
				env->piece[y - env->y_min_piece][x - env->x_min_piece] = '*';
				env->piece[y][x] = '.';
			}
			x++;
		}
		y++;
	}
}

void	count_min_piece(t_env *env)
{
	int		y;
	int		x;

	y = 0;
	env->x_min_piece = -1;
	env->y_min_piece = -1;
	while (y < env->y_piece)
	{
		x = 0;
		while (env->piece[y][x] != '\0')
		{
			if (env->piece[y][x] == '*')
			{
				if (x < env->x_min_piece || env->x_min_piece == -1)
					env->x_min_piece = x;
				if (y < env->y_min_piece || env->y_min_piece == -1)
					env->y_min_piece = y;
			}
			x++;
		}
		y++;
	}
	
}

void	check_piece1(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	count_min_piece(env);

	ft_putchar_fd('\n', 2);
	ft_putstr_fd("env->y_min_piece : ", 2);
	ft_putnbr_fd(env->y_min_piece, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("env->x_min_piece: ", 2);
	ft_putnbr_fd(env->x_min_piece, 2);
	ft_putchar_fd('\n', 2);

	if (env->x_min_piece!= 0 || env->y_min_piece != 0)
		piece_to_top(env);
	
	ft_putchar_fd('\n', 2);
	int i = 0;
	while (i < env->y_piece)
	{
		ft_putendl_fd(env->piece[i], 2);
	 	i++;
	}

	count_max_piece(env);
	
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("env->y_piece : ", 2);
	ft_putnbr_fd(env->y_piece, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("env->x_piece: ", 2);
	ft_putnbr_fd(env->x_piece, 2);
	ft_putchar_fd('\n', 2);

	while (y < env->y_board)
	{
		x = 0;
		while (x < env->x_board)
		{
			/*if (*/check_size(env, y, x);/* == return 1 si ca ne marche plus)*/
				/*jesaispasencore*/
			/*if (*/check_sup(env, y, x);/* == 1)*/
			// if (env->board[y][x] == 'O')
			// {
			// 	check_boardfor1(env, y, x);
			// }
			x++;
		}
		y++;
	}
}

// int		check_boardfor2(t_env *env, int y, int x)
// {
// 	if (env->board[y][x] == '.')
// 	{

// 	}
// 	return (0);
// }

// void	check_piece2(t_env *env)
// {
// 	int		x;
// 	int		y;

// 	y = 0;
// 	while (y < env->y_board)
// 	{
// 		x = 0;
// 		while (x < env->x_board)
// 		{
// 			if (env->board[y][x] == 'X')
// 			{
// 				//check_boardfor1(env, y, x);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }
