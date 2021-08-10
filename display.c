/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:47:31 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/10 02:14:11 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int display(t_long *sl)
{
    createwindow(sl);
    // render_calcul(sl);
    initplayer(sl);
    loadtexture(sl);
    render(sl);
    mlx_put_image_to_window(sl->mlx_ptr,
		sl->mlx_win, sl->img, 0, 0);
    pos_player(sl);
    go_hooking(sl);
    return(0);
}

int go_hooking(t_long *sl)
{
    mlx_do_key_autorepeatoff(sl->mlx_ptr);
	mlx_hook(sl->mlx_win, 2, 1L, ft_key_hit, sl);
	mlx_hook(sl->mlx_win, 3, 2L, ft_key_release, sl);
	mlx_hook(sl->mlx_win, CLOSERED, 1L << 17, closebyredbutton, sl);
	// mlx_hook(sl->mlx_win, 12, 0, ft_expose, display);
	mlx_loop_hook(sl->mlx_ptr, key_loop, sl);
	mlx_loop(sl->mlx_ptr);
    return(0);
}

int		key_loop(t_long *sl)
{
    ft_keyboard(sl);
	if (sl->keyboard[ESC] == 1 || sl->keyboard[RIGHT] == 1
	|| sl->keyboard[LEFT] == 1 || sl->keyboard[BACK] == 1
	|| sl->keyboard[ADVANCE] == 1)
    {
        render(sl);
        pos_player(sl);
        mlx_put_image_to_window(sl->mlx_ptr,
		sl->mlx_win, sl->img, 0, 0);
    }
    return(0);
}

int render(t_long *sl)
{
    int X;
    int Y;
    int text;

    Y = 0;
    X = 0;
    while(Y < sl->Y)
    {
        while(X < sl->X)
        {
            gettextnum(X, Y, sl);
            printtexture(sl, X, Y);
            X++;
        }
        X = 0;
        Y++;
    }
    return(0);
}

int initplayer(t_long *sl)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < sl->Y)
    {
        while (x < sl->X)
        {
            if (sl->map[y][x] == 'P')
            {
                sl->player_x = x;
                sl->player_y = y;
            }
            if (sl->map[y][x] == 'C')
                sl->collectibletotal++;
            x++;
        }
        x = 0;
        y++;
    }
    return(0);
}

int pos_player(t_long *sl)
{
    sl->actualtext = 3;
    // printf("POS PLAYER > X=%d et Y=%d", sl->player_x,sl->player_y);
    printtexture(sl, sl->player_x, sl->player_y);
    return(0);
}

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
			if (sl->color != 0)
                mlx_pixel_put(sl->mlx_ptr, sl->mlx_win, starter_X * 64 + x, starter_Y * 64 + y, sl->color);
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

int createwindow(t_long *sl)
{
    sl->mlx_ptr = mlx_init();
    sl->img = mlx_new_image(sl->mlx_ptr, sl->X, sl->Y);
    sl->pxl = mlx_get_data_addr(sl->img,
		&(sl->bpp), &(sl->s_line),
		&(sl->ed));
    sl->mlx_win = mlx_new_window(sl->mlx_ptr, sl->Xscreen,
						sl->Yscreen, "42 so_long JCluzet");
    return(0);
}