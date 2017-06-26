/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:58:25 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/16 18:01:32 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Get the piece and the board.
*/

static void		check_piece(t_game *game, char *str, char **tab)
{
	tab = ft_strsplit(str, ' ');
	game->y_piece = ft_atoi(tab[1]);
	game->x_piece = ft_atoi(tab[2]);
	ft_tabdel(&tab);
	get_piece(game);
}

static void		check_board(t_game *game, char *str, char **tab)
{
	tab = ft_strsplit(str, ' ');
	game->y_board = ft_atoi(tab[1]);
	game->x_board = ft_atoi(tab[2]);
	ft_tabdel(&tab);
	get_map(game);
}

static int		start(t_game *game, char *str, char **tab, int count)
{
	while (get_next_line(0, &str) == 1)
	{
		if (count == 1)
		{
			if (ft_strncmp("$$$ exec ", str, 8) == 0)
				game->player = str[10];
			else
			{
				ft_memdel((void**)&str);
				return (1);
			}
		}
		else if (ft_strncmp("Plateau ", str, 8) == 0)
			check_board(game, str, tab);
		else if (ft_strncmp("Piece ", str, 6) == 0)
		{
			check_piece(game, str, tab);
			start_the_game(game);
		}
		ft_memdel((void**)&str);
		count++;
	}
	return (0);
}

int				main(void)
{
	char	*str;
	char	**tab;
	t_game	game;

	str = NULL;
	tab = NULL;
	game.piece = NULL;
	game.board = NULL;
	game.y_board = 0;
	game.x_board = 0;
	game.x_min_piece = 0;
	game.y_min_piece = 0;
	game.y_piece = 0;
	game.x_piece = 0;
	game.x = 0;
	game.y = 0;
	game.distance = -1;
	if (start(&game, str, tab, 1))
		ft_putendl("An error was occured, please check the file..");
	return (0);
}
