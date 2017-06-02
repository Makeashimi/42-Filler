/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:58:25 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/02 21:42:21 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Recuperer la piece et le plateau.
*/

void	pieceformap(t_pos *pos)
{
	char	*str;
	int		i;

	i = 0;
	if (!(pos->piece = (char**)malloc(sizeof(char*) * pos->y_piece)))
		return ;
	while (i < pos->y_piece)
	{
		get_next_line(0, &str);
		if (!(pos->piece[i] = (char*)malloc(sizeof(char) * pos->x_piece + 1)))
			return ;
		pos->piece[i] = ft_strcpy(pos->piece[i], &(str[0]));
		i++;
	}
	ft_memdel((void**)&str);
	// int i = 0;
	// while (i < pos->y_piece)
	// {
	// 	ft_putendl_fd(pos->piece[i], 2);
	//  i++;
	// }
}

void	boardformap(t_pos *pos)
{
	char	*str;
	int		i;

	i = 0;
	if (!(pos->board = (char**)malloc(sizeof(char*) * pos->y_board)))
		return ;
	while (i < pos->y_board)
	{
		get_next_line(0, &str);
		if (ft_isdigit(str[0]))
		{
			if (!(pos->board[i] = (char*)malloc(sizeof(char) *
													pos->x_board + 1)))
				return ;
			pos->board[i] = ft_strcpy(pos->board[i], &(str[4]));
			i++;
		}
	}
	ft_memdel((void**)&str);
	// int i = 0;
	// while (i < pos->y_board)
	// {
	// 	ft_putendl_fd(pos->board[i], 2);
	// 	i++;
	// }
}

void	init_dimension(t_pos *pos, t_env *env)
{
	char	*str;
	char	**tab;

	//init_window(env);
	while (get_next_line(0, &str) == 1)
	{
		if (str[0] == '$')
			pos->player = str[10];
		if (ft_isalpha(str[0]))
		{
			tab = ft_strsplit(str, ' ');
			if (str[1] == 'l')
			{
				pos->y_board = ft_atoi(tab[1]);
				pos->x_board = ft_atoi(tab[2]);
				boardformap(pos);
			}
			else
			{
				pos->y_piece = ft_atoi(tab[1]);
				pos->x_piece = ft_atoi(tab[2]);
				pieceformap(pos);
				piece(pos, env);
			}
			ft_tabdel((void***)&tab);
		}
		ft_memdel((void**)&str);
	}
	//drawtab(env, pos);
	//mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	//mlx_loop(env->mlx);
}

int		main(void)
{
	t_pos	pos;
	t_env	env;

	pos.y_board = 0;
	pos.x_board = 0;
	pos.x_min_piece = 0;
	pos.y_min_piece = 0;
	pos.y_piece = 0;
	pos.x_piece = 0;
	pos.x = 0;
	pos.y = 0;
	pos.distance = -1;
	env.color = 0xFF8C00;
	init_dimension(&pos, &env);
	return (0);
}
