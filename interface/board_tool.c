/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:41:31 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/16 16:49:18 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurse.h"

void		get_color(t_vm *vm, int y, int x)
{
	if (vm->board[y][x] == 'X')
	{
		attron(A_BOLD);
		attron(COLOR_PAIR(1));
	}
	else if (vm->board[y][x] == 'O')
	{
		attron(A_BOLD);
		attron(COLOR_PAIR(2));
	}
	else if (vm->board[y][x] == 'o' || vm->board[y][x] == 'x')
	{
		attron(A_BOLD);
		attron(COLOR_PAIR(3));
	}
	else if (vm->board[y][x] == '.')
		attron(COLOR_PAIR(3));
}

void		remove_color(void)
{
	attroff(COLOR_PAIR(2));
	attroff(COLOR_PAIR(3));
	attroff(COLOR_PAIR(4));
	attroff(A_BOLD);
}
