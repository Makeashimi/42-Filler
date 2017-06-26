/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_everything.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:00:11 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/16 17:01:19 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_piece(t_game *game)
{
	char	*str;
	int		i;

	i = 0;
	if (game->piece != NULL)
		ft_tabdel(&(game->piece));
	if (!(game->piece = (char**)malloc(sizeof(char*) * game->y_piece + 1)))
		return ;
	while (i < game->y_piece)
	{
		get_next_line(0, &str);
		if (!(game->piece[i] = (char*)malloc(sizeof(char) * game->x_piece + 1)))
			return ;
		game->piece[i] = ft_strcpy(game->piece[i], &(str[0]));
		i++;
		ft_memdel((void**)&str);
	}
	game->piece[i] = 0;
}

void		get_map(t_game *game)
{
	char	*str;
	int		i;

	i = 0;
	if (game->board != NULL)
		ft_tabdel(&(game->board));
	if (!(game->board = (char**)malloc(sizeof(char*) * game->y_board + 1)))
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
		ft_memdel((void**)&str);
	}
	game->board[i] = 0;
}
