/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 11:33:24 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/16 18:15:39 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurse.h"

static void		show_winner(t_vm *vm)
{
	if (vm->win[0] == -1 || vm->win[1] == -1)
		mvprintw(vm->y + 11, 0, "-> filler_vm has aborted, RIP !\n");
	else
	{
		attron(A_BOLD);
		attron(COLOR_PAIR(2));
		mvprintw(vm->y + 11, 0, "-> %s got %d points, GGWP !\n",
		vm->player[0], vm->win[0]);
		attron(COLOR_PAIR(1));
		mvprintw(vm->y + 12, 0, "-> %s got %d points, GGWP !\n",
		vm->player[1], vm->win[1]);
		attroff(COLOR_PAIR(1));
		attroff(COLOR_PAIR(2));
		attroff(A_BOLD);
	}
}

static void		get_winner(t_vm *vm, char *str, char **tab)
{
	if (str[3] == 'O')
	{
		tab = ft_strsplit(str, ' ');
		vm->win[0] = ft_atoi(tab[3]);
		ft_tabdel(&tab);
	}
	else if (str[3] == 'X')
	{
		tab = ft_strsplit(str, ' ');
		vm->win[1] = ft_atoi(tab[3]);
		ft_tabdel(&tab);
	}
}

static void		get_player(t_vm *vm, char *str, int player)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (str[i - 1] != '/')
		i--;
	while (str[i] != '.')
	{
		count++;
		i++;
	}
	vm->player[player] = (char*)malloc(sizeof(char) * count + 1);
	i = i - count;
	while (str[i] != '.')
	{
		vm->player[player][j] = str[i];
		i++;
		j++;
	}
	vm->player[player][j] = '\0';
}

static int		start(t_vm *vm, char **tab, int count, int player)
{
	char	*str;

	curs_set(0);
	while (get_next_line(0, &str) == 1)
	{
		if (count == 6 || count == 8)
		{
			if (ft_strncmp("launched ", str, 9) == 0)
				get_player(vm, str, player++);
			else
			{
				ft_memdel((void**)&str);
				return (1);
			}
		}
		else if (ft_strncmp("Plateau ", str, 8) == 0)
			board(vm, str, tab);
		else if (ft_strncmp("== ", str, 3) == 0)
			get_winner(vm, str, tab);
		ft_memdel((void**)&str);
		count++;
	}
	return (0);
}

int				main(void)
{
	t_vm	vm;

	vm.player[0] = NULL;
	vm.player[1] = NULL;
	vm.board = NULL;
	vm.win[0] = -1;
	vm.win[1] = -1;
	initscr();
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	while (1)
	{
		if (start(&vm, NULL, 1, 0))
		{
			ft_putendl("An error was occured, please check the file..");
			break ;
		}
		show_winner(&vm);
		if (getch() != 410)
			break ;
	}
	curs_set(1);
	return (0);
}
