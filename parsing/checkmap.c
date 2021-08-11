/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:09:55 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/11 15:56:49 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"

int checkmap(t_long *sl)
{
    if (sl->playerset < 1)
        showerror(sl, "You must set a player 'P'");
    if (sl->playerset > 1)
        showerror(sl, "Multiplayer mode unavailable");
    if (sl->exitset < 1)
        showerror(sl, "You must set an exit 'E'");
    if (sl->exitset > 1)
        showerror(sl, "Only 1 exit is permitted");
    if (sl->collectibletotal == 0)
        showerror(sl, "You must set a collectible 'C'");
    checkthewall(sl);
    return(0);
}

int	checkcubextension(char *str, t_long *sl)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e'
	&& str[i - 3] == 'b' && str[i - 4] == '.')
	{
		if ((i = open(str, O_RDONLY)) == -1)
			showerror(sl, "File Name is not correct");
        else
            close(i);
		return (0); 
	}
	showerror(sl, "Files without .ber extension is not accepted");
	return (0);
}

int		floodandfill(t_long *sl, int mapy, int mapx)
{
	if (sl->map[mapy][mapx] == 'a' ||
	sl->map[mapy][mapx] == 'c' || sl->map[mapy][mapx] == 'd'
	|| sl->map[mapy][mapx] == 'e')
	{
		if (checkaround(mapx, mapy, sl) == 0)
			showerror(sl, "Map is not surrounded/closed by wall");
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
        floodandfill(sl, mapy, mapx + 1);
		floodandfill(sl, mapy, mapx - 1);
		floodandfill(sl, mapy + 1, mapx);
		floodandfill(sl, mapy - 1, mapx);
	}
	return (1);
}

int		checkifgood(char c)
{
	if (c != '0' && c != 'a' && c != '1' && c != 'P' && c != 'c' && c != 'E'
	&& c != 'd' && c != 'C' && c != 'e')
		return (0);
	return (1);
}

int		checkaround(int mapx, int mapy, t_long *sl)
{
	if (mapy == 0 || mapy == sl->Y - 1
	|| mapx == 0 || mapx == sl->X - 1)
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

int		checkthewall(t_long *sl)
{
	int mapx;
	int mapy;

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
	// mapx = 0;
	// mapy = 0;
	return (0);
}
