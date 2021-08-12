/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:58:24 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/13 01:03:35 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	put_pxl(t_long *sl, int x, int y, unsigned int c)
{
	char		*dest;

	if (y >= sl->yscreen || x >= sl->xscreen || x < 0 \
	|| y < 0)
		return (0);
	dest = sl->pxl + sl->s_line * y + x * (sl->bpp / 8);
	*(unsigned int *)dest = c;
	return (0);
}

int fixbomb(t_long *sl)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < sl->y)
    {
        while (x < sl->x)
        {
            if (sl->map[y][x] == 'B')
            {
                gettextnumbomb(sl);
                printtexture(sl, x, y);
            }
            x++;
        }
        x = 0;
        y++;
    }
	mlx_put_image_to_window(sl->mlx_ptr,
		sl->mlx_win, sl->img, 0, 0);
    mlx_string_put(sl->mlx_ptr,sl->mlx_win, 10, 20, 0xffffff, ft_itoa(sl->move));
    return(0);
}

int	visible(t_long *sl)
{
	render(sl);
	pos_player(sl);
	mlx_put_image_to_window(sl->mlx_ptr,
		sl->mlx_win, sl->img, 0, 0);
	return (0);
}