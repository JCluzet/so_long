/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:47:31 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/13 04:48:38 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	display(t_long *sl)
{
	createwindow(sl);
	loadtexture(sl);
	render(sl);
	fixbomb(sl);
	write(1, "\033[32m[ so_long launch successfully ]\033[00m\n", 43);
	pos_player(sl);
	mlx_put_image_to_window(sl->mlx_ptr,
		sl->mlx_win, sl->img, 0, 0);
	go_hooking(sl);
	return (0);
}

int	go_hooking(t_long *sl)
{
	mlx_hook(sl->mlx_win, 2, 1L, ft_key_hit, sl);
	mlx_hook(sl->mlx_win, 15, 1L << 16, visible, sl);
	mlx_hook(sl->mlx_win, CLOSERED, 1L << 17, closebyredbutton, sl);
	mlx_loop_hook(sl->mlx_ptr, key_loop, sl);
	mlx_loop(sl->mlx_ptr);
	return (0);
}

int	key_loop(t_long *sl)
{
	char	*line;

	line = ft_itoa(sl->move);
	if ((sl->dropbomb % 5000) == 0)
	{
		fixbomb(sl);
		mlx_string_put(sl->mlx_ptr, sl->mlx_win, 10, 20,
			0xffffff, line);
		free(line);
	}
	sl->dropbomb++;
	ft_keyboard(sl);
	if (sl->keyboard[ESC] == 1 || sl->keyboard[RIGHT] == 1
		|| sl->keyboard[LEFT] == 1 || sl->keyboard[BACK] == 1
		|| sl->keyboard[ADVANCE] == 1)
	{
		pos_player(sl);
		mlx_put_image_to_window(sl->mlx_ptr,
			sl->mlx_win, sl->img, 0, 0);
		mlx_string_put(sl->mlx_ptr, sl->mlx_win, 10, 20, 0xffffff,
			line);
		free(line);
	}
	return (0);
}

int	render(t_long *sl)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < sl->y)
	{
		while (x < sl->x)
		{
			sl->casein++;
			gettextnum(x, y, sl);
			printtexture(sl, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	createwindow(t_long *sl)
{
	sl->mlx_ptr = mlx_init();
	sl->img = mlx_new_image(sl->mlx_ptr, sl->xscreen, sl->yscreen);
	sl->pxl = mlx_get_data_addr(sl->img,
			&(sl->bpp), &(sl->s_line),
			&(sl->ed));
	sl->mlx_win = mlx_new_window(sl->mlx_ptr, sl->xscreen,
			sl->yscreen, "42 so_long JCluzet");
	return (0);
}
