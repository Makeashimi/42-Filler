/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:11:28 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/01 11:06:36 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	write_image(t_env *env, t_pos *pos)
{
	if ((pos->x * 10) >= 0 && (pos->y * 10) >= 0 && (pos->x * 10) < 1000 && (pos->y * 10) < 1000)
		ft_memcpy(&env->data[((pos->y * env->size) + (pos->x * 4)) * 10], &env->color, 4);
}

static int	destroymouse(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
}

static int	destroykey(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	return (0);
}

void		drawtab(t_env *env, t_pos *pos)
{
	int		y;
	int		x;

	y = 0;
	env->zoom = 20;
	while (y < pos->y_board)
	{
		x = 0;
		while (pos->board[y][x] != '\0')
		{
			if (pos->board[y][x] == 'O')
			{
				env->color = 0xF8F8FF;
				if ((x * env->zoom) >= 0 && (y * env->zoom) >= 0 && (x * env->zoom) < 1000 && (y * env->zoom) < 1000)
					ft_memcpy(&env->data[((y * env->size) + (x * 4)) * env->zoom], &env->color, 4);
			}
			if (pos->board[y][x] == 'X')
			{
				env->color = 0xABC8E2;
				if ((x * env->zoom) >= 0 && (y * env->zoom) >= 0 && (x * env->zoom) < 1000 && (y * env->zoom) < 1000)
				{
					ft_memcpy(&env->data[((y * env->size) + (x * 4)) * env->zoom], &env->color, 4);
					ft_memcpy(&env->data[(((y + 1) * env->size) + ((x + 1)* 4))], &env->color, 4);
				}

			}
			else if (pos->board[y][x] == '.')
			{
				env->color = 0xA8ACA8;
				if ((x * env->zoom) >= 0 && (y * env->zoom) >= 0 && (x * env->zoom) < 1000 && (y * env->zoom) < 1000)
					ft_memcpy(&env->data[((y * env->size) + (x * 4)) * env->zoom], &env->color, 4);
			}
			x++;
		}
		y++;
	}
}

int			init_window(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		exit(-1);
	if (!(env->win = mlx_new_window(env->mlx, 1000, 1000,
												"Let's play a game !")))
		exit(-1);
	if (!(env->img = mlx_new_image(env->mlx, 1000, 1000)))
		exit(-1);
	env->data = mlx_get_data_addr(env->img, &(env->bits), &(env->size),
												&(env->endian));
	mlx_key_hook(env->win, destroykey, env);
	mlx_hook(env->win, 17, 1L << 17, destroymouse, env);
	return (0);
}
