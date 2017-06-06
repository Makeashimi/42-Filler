/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:58:25 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/06 17:22:06 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Recuperer la piece et le plateau.
*/

static void		pieceformap(t_game *game)
{
	char	*str;
	int		i;

	i = 0;
	if (!(game->piece = (char**)malloc(sizeof(char*) * game->y_piece)))
		return ;
	while (i < game->y_piece)
	{
		get_next_line(0, &str);
		if (!(game->piece[i] = (char*)malloc(sizeof(char) * game->x_piece + 1)))
			return ;
		game->piece[i] = ft_strcpy(game->piece[i], &(str[0]));
		i++;
	}
	ft_memdel((void**)&str);
}

static void		boardformap(t_game *game)
{
	char	*str;
	int		i;

	i = 0;
	if (!(game->board = (char**)malloc(sizeof(char*) * game->y_board)))
		return ;
	while (i < game->y_board)
	{
		get_next_line(0, &str);
		if (ft_isdigit(str[0]))
		{
			if (!(game->board[i] = (char*)malloc(sizeof(char) *
													game->x_board + 1)))
				return ;
			game->board[i] = ft_strcpy(game->board[i], &(str[4]));
			i++;
		}
	}
	ft_memdel((void**)&str);
}

void			start(t_game *game, t_env *env, char *str, char **tab)
{
	while (get_next_line(0, &str) == 1)
	{
		if (str[0] == '$')
			game->player = str[10];
		if (ft_isalpha(str[0]))
		{
			tab = ft_strsplit(str, ' ');
			if (str[1] == 'l')
			{
				game->y_board = ft_atoi(tab[1]);
				game->x_board = ft_atoi(tab[2]);
				boardformap(game);
			}
			else
			{
				game->y_piece = ft_atoi(tab[1]);
				game->x_piece = ft_atoi(tab[2]);
				pieceformap(game);
				start_the_game(game, env);
			}
			ft_tabdel((void***)&tab);
		}
		ft_memdel((void**)&str);
	}
}

int				main(void)
{
	char	*str;
	char	**tab;
	t_game	game;
	t_env	env;

	str = NULL;
	tab = NULL;
	game.y_board = 0;
	game.x_board = 0;
	game.x_min_piece = 0;
	game.y_min_piece = 0;
	game.y_piece = 0;
	game.x_piece = 0;
	game.x = 0;
	game.y = 0;
	game.distance = -1;
	start(&game, &env, str, tab);
	return (0);
}
