/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:58:25 by jcharloi          #+#    #+#             */
/*   Updated: 2017/05/19 16:58:47 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* 
** Recuperer la piece et le plateau.
*/

void	pieceformap(t_env *env)
{
	char	*str;
	int		i;

	i = 0;
	if (!(env->piece = (char**)malloc(sizeof(char*) * env->y_piece)))
		return ;
	while (i < env->y_piece)
	{
		get_next_line(0, &str);
		if (!(env->piece[i] = (char*)malloc(sizeof(char) * env->x_piece + 1)))
			return ;
		env->piece[i] = ft_strcpy(env->piece[i], &(str[0]));
		i++;
	}
	ft_memdel((void**)&str);
	// i = 0;
	// while (i < env->y_piece)
	// {
	// 	ft_putendl_fd(env->piece[i], 2);
	//  i++;
	// }
}

void	boardformap(t_env *env)
{
	char	*str;
	int		i;

	i = 0;
	if (!(env->board = (char**)malloc(sizeof(char*) * env->y_board)))
		return ;
	while (i < env->y_board)
	{
		get_next_line(0, &str);
		if (ft_isdigit(str[0]))
		{
			if (!(env->board[i] = (char*)malloc(sizeof(char) * env->x_board + 1)))
				return ;
			env->board[i] = ft_strcpy(env->board[i], &(str[4]));
			i++;
		}
	}
	ft_memdel((void**)&str);
	// i = 0;
	// while (i < env->y_board)
	// {
	// 	ft_putendl_fd(env->board[i], 2);
	// 	i++;
	// }
}

void	init_dimension(t_env *env)
{
	char	*str;
	char	**tab;

	while (get_next_line(0, &str) == 1)
	{
		if (str[0] == '$')
			env->player = str[10];
		if (ft_isalpha(str[0]))
		{
			tab = ft_strsplit(str, ' ');
			if (str[1] == 'l')
			{
				env->y_board = ft_atoi(tab[1]);
				env->x_board = ft_atoi(tab[2]);
				boardformap(env);
			}
			else
			{
				env->y_piece = ft_atoi(tab[1]);
				env->x_piece = ft_atoi(tab[2]);
				pieceformap(env);
				if (env->player == '1')
					check_piece1(env);
				//else
					//check_piece2(env);
				
			}
			ft_tabdel((void***)&tab);
		}
		ft_memdel((void**)&str);
	}
}

int		main()
{
	t_env	env;

	env.y_board = 0;
	env.x_board = 0;
	env.x_min_piece = 0;
	env.y_min_piece = 0;
	env.y_piece = 0;
	env.x_piece = 0;
	env.x = 0;
	env.y = 0;
	while (1)
		init_dimension(&env);
	
	return (0);
}
