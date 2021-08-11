/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:47:31 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/11 05:08:02 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int display(t_long *sl)
{
    createwindow(sl);
    loadtexture(sl);
    render(sl);
    // mlx_put_image_to_window(sl->mlx_ptr,
	// 	sl->mlx_win, sl->img, 0, 0);
    pos_player(sl);
    go_hooking(sl);
    return(0);
}

int go_hooking(t_long *sl)
{
    // mlx_do_key_autorepeatoff(sl->mlx_ptr);
	mlx_hook(sl->mlx_win, 2, 1L, ft_key_hit, sl);
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
        pos_player(sl);
        // mlx_put_image_to_window(sl->mlx_ptr,
		// sl->mlx_win, sl->img, 0, 0);
    }
    return(0);
}

int render(t_long *sl)
{
    int X;
    int Y;

    Y = 0;
    X = 0;
    while(Y < sl->Y)
    {
        while(X < sl->X)
        {
            sl->casein++;
            write(1, "\b\b\b\b\b\b", 7);
            ft_putnbr(sl->casein / sl->casetotal * 100);
            write(1, "% \n", 1);
            gettextnum(X, Y, sl);
            printtexture(sl, X, Y);
            X++;
        }
        X = 0;
        Y++;
    }
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
