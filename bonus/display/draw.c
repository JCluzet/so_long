/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:58:24 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/13 03:05:43 by jcluzet          ###   ########.fr       */
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

int	fixbomb(t_long *sl)
{
	int	x;
	int	y;

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
	if (sl->dropbomb == 100000)
		sl->dropbomb = 0;
	mlx_put_image_to_window(sl->mlx_ptr,
		sl->mlx_win, sl->img, 0, 0);
	return (0);
}

int	visible(t_long *sl)
{
	render(sl);
	pos_player(sl);
	mlx_put_image_to_window(sl->mlx_ptr,
		sl->mlx_win, sl->img, 0, 0);
	return (0);
}

int	loadtexture3(t_long *sl)
{
	sl->ptr_text[10] = mlx_get_data_addr(sl->text[10],
			&(sl->bpp_text[10]), &(sl->sline_text[10]), &(sl->ed_text[10]));
	sl->text[11] = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./textures/sprites/7.xpm", &sl->widthtext[11],
			&sl->heighttext[11]);
	sl->ptr_text[11] = mlx_get_data_addr(sl->text[11],
			&(sl->bpp_text[11]), &(sl->sline_text[11]), &(sl->ed_text[11]));
	sl->text[12] = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./textures/sprites/8.xpm", &sl->widthtext[12],
			&sl->heighttext[12]);
	sl->ptr_text[12] = mlx_get_data_addr(sl->text[12],
			&(sl->bpp_text[12]), &(sl->sline_text[12]), &(sl->ed_text[12]));
	sl->text[13] = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./textures/sprites/9.xpm", &sl->widthtext[13],
			&sl->heighttext[13]);
	sl->ptr_text[13] = mlx_get_data_addr(sl->text[13],
			&(sl->bpp_text[13]), &(sl->sline_text[13]), &(sl->ed_text[13]));
	sl->text[14] = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./textures/sprites/10.xpm", &sl->widthtext[14],
			&sl->heighttext[14]);
	sl->ptr_text[14] = mlx_get_data_addr(sl->text[14],
			&(sl->bpp_text[14]), &(sl->sline_text[14]), &(sl->ed_text[14]));
	return (0);
}
