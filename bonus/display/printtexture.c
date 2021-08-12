/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtexture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:47:31 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/12 20:11:44 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	loadtexture(t_long *sl)
{
	sl->text[0] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/bottom-64.xpm",
			&sl->widthtext[0], &sl->heighttext[0]);
	sl->ptr_text[0] = mlx_get_data_addr(sl->text[0],
			&(sl->bpp_text[0]), &(sl->sline_text[0]), &(sl->ed_text[0]));
	sl->text[1] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/dalle-64t.xpm",
			&sl->widthtext[1], &sl->heighttext[1]);
	sl->ptr_text[1] = mlx_get_data_addr(sl->text[1],
			&(sl->bpp_text[1]), &(sl->sline_text[1]), &(sl->ed_text[1]));
	sl->text[3] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/player.xpm",
			&sl->widthtext[3], &sl->heighttext[3]);
	sl->ptr_text[3] = mlx_get_data_addr(sl->text[3],
			&(sl->bpp_text[3]), &(sl->sline_text[3]), &(sl->ed_text[3]));
	sl->text[2] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/invader.xpm",
			&sl->widthtext[2], &sl->heighttext[2]);
	sl->ptr_text[2] = mlx_get_data_addr(sl->text[2],
			&(sl->bpp_text[2]), &(sl->sline_text[2]), &(sl->ed_text[2]));
	sl->text[4] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/exit.xpm",
			&sl->widthtext[4], &sl->heighttext[4]);
	sl->ptr_text[4] = mlx_get_data_addr(sl->text[4],
			&(sl->bpp_text[4]), &(sl->sline_text[4]), &(sl->ed_text[4]));
    loadtexture2(sl);
	return (0);
}

int	printtexture(t_long *sl, int starter_X, int starter_Y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < sl->heighttext[sl->actualtext])
	{
		while (x < sl->widthtext[sl->actualtext])
		{
			sl->color = *(unsigned int *)(sl->ptr_text[sl->actualtext]
					+ sl->sline_text[sl->actualtext] * y + x
					* (sl->bpp_text[sl->actualtext] / 8));
			if (sl->color != 0)
			{
				put_pxl(sl, starter_X * 64 + x, starter_Y * 64 + y, sl->color);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	gettextnum(int X, int Y, t_long *sl)
{
	if (sl->map[Y][X] == '0' || sl->map[Y][X] == 'a')
		sl->actualtext = 0;
	if (sl->map[Y][X] == '1')
		sl->actualtext = 1;
	if (sl->map[Y][X] == 'C')
		sl->actualtext = 2;
	if (sl->map[Y][X] == 'E')
		sl->actualtext = 4;
	if (sl->map[Y][X] == 'P')
		sl->actualtext = 0;
	return (0);
}

int	gettextnumbomb(t_long *sl)
{
    if (sl->spritebomb == 15)
        sl->spritebomb = 5;
    sl->actualtext = sl->spritebomb;
    sl->spritebomb++;
    return (0);
}

int	loadtexture2(t_long *sl)
{
	sl->text[5] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/sprites/1.xpm",
			&sl->widthtext[5], &sl->heighttext[5]);
	sl->ptr_text[5] = mlx_get_data_addr(sl->text[5],
			&(sl->bpp_text[5]), &(sl->sline_text[5]), &(sl->ed_text[5]));
	sl->text[6] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/sprites/2.xpm",
			&sl->widthtext[6], &sl->heighttext[6]);
	sl->ptr_text[6] = mlx_get_data_addr(sl->text[6],
			&(sl->bpp_text[6]), &(sl->sline_text[6]), &(sl->ed_text[6]));
	sl->text[7] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/sprites/3.xpm",
			&sl->widthtext[7], &sl->heighttext[7]);
	sl->ptr_text[7] = mlx_get_data_addr(sl->text[7],
			&(sl->bpp_text[7]), &(sl->sline_text[7]), &(sl->ed_text[7]));
	sl->text[8] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/sprites/4.xpm",
			&sl->widthtext[8], &sl->heighttext[8]);
	sl->ptr_text[8] = mlx_get_data_addr(sl->text[8],
			&(sl->bpp_text[8]), &(sl->sline_text[8]), &(sl->ed_text[8]));
	sl->text[9] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/sprites/5.xpm",
			&sl->widthtext[9], &sl->heighttext[9]);
	sl->ptr_text[9] = mlx_get_data_addr(sl->text[9],
			&(sl->bpp_text[9]), &(sl->sline_text[9]), &(sl->ed_text[9]));
	sl->text[10] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/sprites/6.xpm",
			&sl->widthtext[10], &sl->heighttext[10]);
	sl->ptr_text[10] = mlx_get_data_addr(sl->text[10],
			&(sl->bpp_text[10]), &(sl->sline_text[10]), &(sl->ed_text[10]));
	sl->text[11] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/sprites/7.xpm",
			&sl->widthtext[11], &sl->heighttext[11]);
	sl->ptr_text[11] = mlx_get_data_addr(sl->text[11],
			&(sl->bpp_text[11]), &(sl->sline_text[11]), &(sl->ed_text[11]));
	sl->text[12] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/sprites/8.xpm",
			&sl->widthtext[12], &sl->heighttext[12]);
	sl->ptr_text[12] = mlx_get_data_addr(sl->text[12],
			&(sl->bpp_text[12]), &(sl->sline_text[12]), &(sl->ed_text[12]));
	sl->text[13] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/sprites/9.xpm",
			&sl->widthtext[13], &sl->heighttext[13]);
	sl->ptr_text[13] = mlx_get_data_addr(sl->text[13],
			&(sl->bpp_text[13]), &(sl->sline_text[13]), &(sl->ed_text[13]));
	sl->text[14] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/sprites/10.xpm",
			&sl->widthtext[14], &sl->heighttext[14]);
	sl->ptr_text[14] = mlx_get_data_addr(sl->text[14],
			&(sl->bpp_text[14]), &(sl->sline_text[14]), &(sl->ed_text[14]));
	return (0);
}