/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 19:54:37 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/09 00:31:37 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int		ft_key_hit(int keycode, t_long *sl)
{
	sl->keyboard[keycode] = 1;
	return (0);
}

int		ft_key_release(int keycode, t_long *sl)
{
	sl->keyboard[keycode] = 0;
	return (0);
}

int		ft_keyboard(t_long *sl)
{
	// if (display->keyboard[ADVANCE])
	// 	moveplayer(1, display);
	// if (display->keyboard[BACK])
	// 	moveplayer(-1, display);
	// if (display->keyboard[LEFT])
	// 	moveplayer(2, display);
	// if (display->keyboard[RIGHT])
	// 	moveplayer(3, display);
	if (sl->keyboard[ESC] == 1 || sl->keyboard[RED_BUTTON] == 1)
		freeandexit(sl);
	return (0);
}

int		closebyredbutton(t_long *sl)
{
	freeandexit(sl);
	sl->keyboard[79] = 1;
	return (0);
}
