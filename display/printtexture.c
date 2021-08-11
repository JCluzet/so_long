/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtexture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:47:31 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/11 02:24:36 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int loadtexture(t_long *sl)
{
	if ((sl->text[0] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/bottom-64.xpm", &sl->widthtext[0], &sl->heighttext[0])))
		sl->ptr_text[0] = mlx_get_data_addr(sl->text[0],
		&(sl->bpp_text[0]), &(sl->sline_text[0]), &(sl->ed_text[0]));
	if ((sl->text[1] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/dalle-64t.xpm", &sl->widthtext[1], &sl->heighttext[1])))
		sl->ptr_text[1] = mlx_get_data_addr(sl->text[1],
		&(sl->bpp_text[1]), &(sl->sline_text[1]), &(sl->ed_text[1]));
	if ((sl->text[3] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/player.xpm", &sl->widthtext[3], &sl->heighttext[3])))
		sl->ptr_text[3] = mlx_get_data_addr(sl->text[3],
		&(sl->bpp_text[3]), &(sl->sline_text[3]), &(sl->ed_text[3]));
	if ((sl->text[2] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/invader.xpm", &sl->widthtext[2], &sl->heighttext[2])))
		sl->ptr_text[2] = mlx_get_data_addr(sl->text[2],
		&(sl->bpp_text[2]), &(sl->sline_text[2]), &(sl->ed_text[2]));
	if ((sl->text[4] = mlx_xpm_file_to_image(sl->mlx_ptr, "./textures/exit.xpm", &sl->widthtext[4], &sl->heighttext[4])))
		sl->ptr_text[4] = mlx_get_data_addr(sl->text[4],
		&(sl->bpp_text[4]), &(sl->sline_text[4]), &(sl->ed_text[4]));
    return(0);
}

int printtexture(t_long *sl, int starter_X, int starter_Y)
{
	int x;
	int y;

    x = 0;
	y = 0;
	while (y < sl->heighttext[sl->actualtext])
	{
		while (x < sl->widthtext[sl->actualtext])
		{
			sl->color = *(unsigned int*) (sl->ptr_text[sl->actualtext] + sl->sline_text[sl->actualtext] * y + x * (sl->bpp_text[sl->actualtext] / 8));
			if (sl->color != 0) {
                mlx_pixel_put(sl->mlx_ptr, sl->mlx_win, starter_X * 64 + x, starter_Y * 64 + y, sl->color);
				// put_pxl(sl, starter_X * 64 + x, starter_Y * 64 + y, sl->color);
				if(x < 100)
					printf("Starter_X > %d\n", x);
			}
			x++;
		}
		x = 0;
		y++;
	}
    return(0);
}

int     gettextnum(int X, int Y, t_long *sl)
{
    if (sl->map[Y][X] == '0')
        sl->actualtext = 0;
    else if(sl->map[Y][X] == '1')
        sl->actualtext = 1;
    else if(sl->map[Y][X] == 'C')
        sl->actualtext = 2;
    else if (sl->map[Y][X] == 'E')
        sl->actualtext = 4;
    else if (sl->map[Y][X] == 'P')
        sl->actualtext = 0;
    return(0);
}
