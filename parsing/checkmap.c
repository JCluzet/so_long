/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:09:55 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/11 02:16:17 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"

int checkmap(t_long *sl)
{
    if (sl->playerset < 1)
        showerror(sl, "Player missing in MAP");
    if (sl->playerset > 1)
        showerror(sl, "Multiplayer mode unavailable");
    if (sl->exitset < 1)
        showerror(sl, "You must place an exit 'E' in MAP");
    if (sl->exitset > 1)
        showerror(sl, "Only 1 exit is permitted");
    // filland
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

// int		checkthewall(t_long *sl)
// {
// 	int mapx;
// 	int mapy;

// 	mapy = (int)sl->player_x;
// 	mapx = (int)sl->player_y;
// 	floodandfill(display, mapx, mapy + 1);
// 	floodandfill(display, mapx, mapy - 1);
// 	floodandfill(display, mapx + 1, mapy);
// 	floodandfill(display, mapx, mapy - 1);
// 	mapx = 0;
// 	mapy = 0;
// 	return (0);
// }
