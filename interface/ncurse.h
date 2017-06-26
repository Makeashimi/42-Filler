/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:16:32 by jcharloi          #+#    #+#             */
/*   Updated: 2017/06/16 17:20:08 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSE_H
# define NCURSE_H

# include <curses.h>
# include <stdio.h>
# include "../sources/filler.h"

typedef struct s_vm	t_vm;

struct				s_vm
{
	char			*player[2];
	char			**board;
	int				y;
	int				x;
	int				win[2];
};

void				board(t_vm *vm, char *str, char **tab);
void				get_color(t_vm *vm, int y, int x);
void				remove_color(void);

#endif
