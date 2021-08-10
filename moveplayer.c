/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:10:00 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/10 02:22:43 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int     moveplayer(int nb, t_long *sl)
{
    if (nb == 1)
        if (sl->map[sl->player_y - 1][sl->player_x] != '1')
        {
            sl->player_y--;
            sl->move++;
        }
    if (nb == -1)
        if (sl->map[sl->player_y + 1][sl->player_x] != '1')
        {
            sl->player_y++;
            sl->move++;
        }
    if (nb == 2)
        if (sl->map[sl->player_y][sl->player_x - 1] != '1')
        {
            sl->player_x--;
            sl->move++;
        }
    if (nb == 3)
        if (sl->map[sl->player_y][sl->player_x + 1] != '1')
        {
            sl->player_x++;
            sl->move++;
        }
    checkaremove(sl);
    return(0);
}

int     checkaremove(t_long *sl)
{
    if (sl->map[sl->player_y][sl->player_x] == 'C')
    {
        sl->collectible++;
        sl->map[sl->player_y][sl->player_x] = '0'; // For remove collectible when player on it BUT dont work ??
    }
    if (sl->map[sl->player_y][sl->player_x] == 'E')
    {
        if (sl->collectible == sl->collectibletotal)
            exit(0);
    }
    return(0);
}
