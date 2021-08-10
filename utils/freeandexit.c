/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeandexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 23:22:24 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/09 00:29:57 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int			freeandexit(t_long *sl)
{
	mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
	freemap(sl);
	write(1, "\n\033[31m[ so_long closed Successfully ]\n", 39);
	exit(0);
}

int			freemap(t_long *sl)
{
	int i;

	i = 0;
	if (sl->maptofree == -1)
		return (1);
	while (i < sl->Y)
	{
		free(sl->map[i]);
		i++;
	}
	if (sl->map)
		free(sl->map);
	return (1);
}