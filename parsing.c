/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:34:19 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/10 02:12:51 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int parsing(t_long *sl, int argc, char *argv)
{
    initvar(sl);
    mallocmap(sl, argv);
    stockmap(sl, argv);
    return(0);
}

int get_x_and_y(t_long *sl, char *argv)
{
    // put the file(argv) in a GET_NEXT_LINE (change it to get X and Y of map) 
    // stock X & Y of the map in sl->X || sl->Y
    sl->Y = 5;  // to remove
    sl->X = 10; // to remove
    sl->Yscreen = sl->Y * 64;
    sl->Xscreen = sl->X * 64;
    return(0);
}

int stockmap(t_long *sl, char *argv)
{
    sl->map[0] = "1111111111";
    sl->map[1] = "1001C00001";
    sl->map[2] = "1CC0011001";
    sl->map[3] = "1P000110E1";
    sl->map[4] = "1111111111";
    return(0);
}

int     initvar(t_long *sl)
{
    sl->keyboard[BACK] = 0;
	sl->keyboard[RED_BUTTON] = 0;
	sl->keyboard[ESC] = 0;
	sl->keyboard[LEFT] = 0;
	sl->keyboard[RIGHT] = 0;
	sl->keyboard[ADVANCE] = 0;
    sl->bpp = 0;
    sl->collectible = 0;
    sl->collectibletotal = 0;
	sl->s_line = 0;
    sl->move = 0;
    return(0);
}

int			mallocmap(t_long *sl, char *argv)
{
	int i;

	i = 0;
    get_x_and_y(sl, argv);
	sl->map = malloc(sizeof(char*) * sl->Y);
	while (i < sl->Y)
	{
		sl->map[i] = malloc(sizeof(char*) * sl->X + 1);
		i++;
	}
	return (1);
}