/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:34:19 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/08 22:27:01 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int parsing(t_long *sl, int argc, char argv)
{
    mallocmap(sl, argv);
    sl->Y = 5;  // to remove
    sl->X = 10; // to remove
    stockmap(sl, argv);
    return(0);
}

int get_x_and_y(sl, argv)
{
    // put the file(argv) in a GET_NEXT_LINE (change it to get X and Y of map) 
    // stock X & Y of the map in sl->X || sl->Y
    return(0);
}

int stockmap(t_long sl, char argv)
{
    
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