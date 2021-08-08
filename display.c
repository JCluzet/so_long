/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:47:31 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/08 23:26:40 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int display(t_long *sl)
{
    createwindow(sl);
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
}

int		key_loop(t_long *sl)
{
    ft_keyboard(sl);
    // modification a faire en fonction des touches
    	mlx_put_image_to_window(sl->mlx_ptr,
	sl->mlx_win, sl->img, 0, 0);
}

int createwindow(t_long *sl)
{
    sl->mlx_ptr = mlx_init();
    sl->img = mlx_new_image(sl->mlx_ptr, sl->X, sl->Y);
    if ((sl->mlx_win = mlx_new_window(sl->mlx_ptr, sl->X*100,
						sl->Y*100, "42 so_long JCluzet")) == 0)
			return (0);
            
    return(0);
}