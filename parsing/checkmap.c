/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:09:55 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/12 01:21:33 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	checkcubextension(char *str, t_long *sl)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e'
		&& str[i - 3] == 'b' && str[i - 4] == '.')
	{
		i = open(str, O_RDONLY);
		if (i == -1)
			showerror(sl, "File Name is not correct");
		else
			close(i);
		return (0);
	}
	showerror(sl, "Files without .ber extension is not accepted");
	return (0);
}

int	floodandfill(t_long *sl, int mapy, int mapx)
{
	if (sl->map[mapy][mapx] == 'a' ||
	sl->map[mapy][mapx] == 'c' || sl->map[mapy][mapx] == 'd'
	|| sl->map[mapy][mapx] == 'e')
	{
		if (checkaround(mapx, mapy, sl) == 0)
			showerror(sl, "Map is not surrounded/closed by wall");
		floodandfill2(sl, mapy, mapx);
		floodandfill(sl, mapy, mapx + 1);
		floodandfill(sl, mapy, mapx - 1);
		floodandfill(sl, mapy + 1, mapx);
		floodandfill(sl, mapy - 1, mapx);
	}
	return (1);
}

void	floodandfill2(t_long *sl, int mapy, int mapx)
{
	if (sl->map[mapy][mapx] == 'a')
		sl->map[mapy][mapx] = '0';
	if (sl->map[mapy][mapx] == 'c')
		sl->map[mapy][mapx] = 'P';
	if (sl->map[mapy][mapx] == 'd')
	{
		sl->map[mapy][mapx] = 'E';
		sl->exitparse++;
	}
	if (sl->map[mapy][mapx] == 'e')
	{
		sl->map[mapy][mapx] = 'C';
		sl->collectibleparse++;
	}
}

int	checkaround(int mapx, int mapy, t_long *sl)
{
	if (mapy == 0 || mapy == sl->y - 1
		|| mapx == 0 || mapx == sl->x - 1)
		showerror(sl, "Map is not surrounded/closed by walls");
	if (checkifgood(sl->map[mapy + 1][mapx]) == 0)
		return (0);
	if (checkifgood(sl->map[mapy - 1][mapx]) == 0)
		return (0);
	if (checkifgood(sl->map[mapy][mapx + 1]) == 0)
		return (0);
	if (checkifgood(sl->map[mapy][mapx - 1]) == 0)
		return (0);
	return (1);
}

int	checkthewall(t_long *sl)
{
	int	mapx;
	int	mapy;

	mapy = (int)sl->player_x;
	mapx = (int)sl->player_y;
	sl->collectibleparse = 0;
	sl->exitparse = 0;
	floodandfill(sl, mapx, mapy + 1);
	floodandfill(sl, mapx, mapy - 1);
	floodandfill(sl, mapx + 1, mapy);
	floodandfill(sl, mapx, mapy - 1);
	if (sl->collectibleparse != sl->collectibletotal)
		showerror(sl, "Some collectible are out of the map");
	if (sl->exitparse == 0)
		showerror(sl, "Exit is out of the map");
	return (0);
}
