/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:43:29 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/16 17:27:36 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurse.h"

static void		put_board(t_vm *vm, int i, int y, int x)
{
	int xcopy;

	while (y < vm->y)
	{
		x = 0;
		xcopy = 0;
		while (vm->board[y][x] != '\0')
		{
			get_color(vm, y, x);
			if (x < 4)
				mvprintw(i, (COLS / 2) - (vm->x + 4 / 2) + x, "%c",
					vm->board[y][x]);
			else
				mvprintw(i, (COLS / 2) - (vm->x + 4 / 2) + xcopy, "%c",
					vm->board[y][x]);
			refresh();
			x++;
			xcopy++;
			if (x > 4)
				xcopy++;
			remove_color();
		}
		i++;
		y++;
	}
}

static void		init_win2(t_vm *vm, int size)
{
	int half;

	half = (COLS / 2) - (size / 2);
	size = ft_strlen("     __           _____");
	mvprintw(6, (COLS / 2) - (size / 2) + 1,
		"     __           _____");
	size = ft_strlen(vm->player[0]);
	mvprintw(7, half - ((half / 2) - (size / 2)),
		"Player 1 : %s", vm->player[0]);
	size = ft_strlen(" /\\ / _  /\\ ||\\ |(_  | ");
	mvprintw(7, (COLS / 2) - (size / 2) + 1,
		" /\\ / _  /\\ ||\\ |(_  | ");
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(1));
	size = ft_strlen("/--\\\\__)/--\\|| \\|__) | ");
	mvprintw(8, (COLS / 2) - (size / 2) + 1,
		"/--\\\\__)/--\\|| \\|__) | ");
	size = ft_strlen(vm->player[1]);
	half = (COLS / 2) - (size / 2);
	mvprintw(8, half + ((half / 2) - (size / 2)),
		"Player 2 : %s", vm->player[1]);
}

static void		init_win(t_vm *vm)
{
	int		size;

	attron(A_BOLD);
	size = ft_strlen("____  ____  __    __    ____  ____");
	mvprintw(1, (COLS / 2) - (size / 2), "%s",
		"____  ____  __    __    ____  ____");
	size = ft_strlen("( ___)(_  _)(  )  (  )  ( ___)(  _ \\");
	mvprintw(2, (COLS / 2) - (size / 2), "%s",
		"( ___)(_  _)(  )  (  )  ( ___)(  _ \\");
	size = ft_strlen(" )__)  _)(_  )(__  )(__  )__)  )   /");
	mvprintw(3, (COLS / 2) - (size / 2), "%s",
		" )__)  _)(_  )(__  )(__  )__)  )   /");
	size = ft_strlen("(__)  (____)(____)(____)(____)(_)\\_)");
	mvprintw(4, (COLS / 2) - (size / 2), "%s",
		"(__)  (____)(____)(____)(____)(_)\\_)");
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(2));
	init_win2(vm, size);
}

static void		get_board(t_vm *vm, char *str, int i)
{
	if (vm->board != NULL)
		ft_tabdel(&(vm->board));
	attron(COLOR_PAIR(3));
	init_win(vm);
	attroff(COLOR_PAIR(1));
	attroff(A_BOLD);
	refresh();
	if (!(vm->board = (char**)malloc(sizeof(char*) * vm->y + 1)))
		return ;
	while (i < vm->y)
	{
		get_next_line(0, &str);
		if (ft_isdigit(str[0]) || str[0] == ' ')
		{
			if (!(vm->board[i] = (char*)malloc(sizeof(char) * vm->x + 5)))
				return ;
			vm->board[i] = ft_strcpy(vm->board[i], &(str[0]));
			i++;
		}
		ft_memdel((void**)&str);
	}
	vm->board[i] = 0;
	put_board(vm, 10, 0, 0);
}

void			board(t_vm *vm, char *str, char **tab)
{
	tab = ft_strsplit(str, ' ');
	vm->y = ft_atoi(tab[1]) + 1;
	vm->x = ft_atoi(tab[2]);
	ft_tabdel(&tab);
	get_board(vm, NULL, 0);
}
