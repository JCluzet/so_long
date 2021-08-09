/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:47:31 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/09 01:28:15 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int display(t_long *sl)
{
    createwindow(sl);
    render_calcul(sl);
    render(sl);
    mlx_put_image_to_window(sl->mlx_ptr,
		sl->mlx_win, sl->img, 0, 0);
    go_hooking(sl);
    return(0);
}

int go_hooking(t_long *sl)
{
    mlx_do_key_autorepeatoff(sl->mlx_ptr);
	mlx_hook(sl->mlx_win, 2, 1L, ft_key_hit, display);
	mlx_hook(sl->mlx_win, 3, 2L, ft_key_release, display);
	mlx_hook(sl->mlx_win, CLOSERED, 1L << 17, closebyredbutton, display);
	// mlx_hook(sl->mlx_win, 12, 0, ft_expose, display);
	mlx_loop_hook(sl->mlx_ptr, key_loop, display);
	mlx_loop(sl->mlx_ptr);
    return(0);
}

int		key_loop(t_long *sl)
{
    ft_keyboard(sl);
    render(sl);
    // mlx_put_image_to_window(sl->mlx_ptr,
	// 	sl->mlx_win, sl->img, 0, 0);
    // modification a faire en fonction des touches
    return(0);
}

int render(t_long *sl)
{
    int X;
    int Y;

    Y = 0;
    X = 0;
    while(Y * sl->Ycase < sl->Yscreen)
    {
        while(X * sl->Xcase < sl->Xscreen)
        {
            // put_pxl(sl, X, Y, 10101011);
            printtexture(sl, X, Y);
            mlx_pixel_put(sl->mlx_ptr, sl->mlx_win, X * sl->Xcase, Y * sl->Ycase, 10101011);
            X++;
        }
        X = 0;
        Y++;
    }
    return(0);
}

int printtexture(t_long *sl, int X, int Y)
{
    
    return(0);
}

int render_calcul(t_long *sl)
{
    sl->Xcase = sl->Xscreen / sl->X;
    sl->Ycase = sl->Yscreen / sl->Y;
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