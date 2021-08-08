/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:34:19 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/08 23:19:49 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int parsing(t_long *sl, int argc, char argv)
{
    sl->Y = 5;  // to remove
    sl->X = 10; // to remove
    mallocmap(sl, argv);
    stockmap(sl, argv);
    return(0);
}

int get_x_and_y(t_long *sl, char *argv)
{
    // put the file(argv) in a GET_NEXT_LINE (change it to get X and Y of map) 
    // stock X & Y of the map in sl->X || sl->Y
    return(0);
}

int stockmap(t_long *sl, char argv)
{
    sl->map[0] = "1111111111";
    sl->map[1] = "10010000C1";
    sl->map[2] = "1000011001";
    sl->map[3] = "1P000110E1";
    sl->map[4] = "1111111111";
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
		sl->map[i] = malloc(sizeof(char) * sl->X + 1);
		i++;
	}
	return (1);
}