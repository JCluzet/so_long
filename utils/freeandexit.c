/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeandexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 23:22:24 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/12 16:06:46 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	freeandexit(t_long *sl)
{
	if (sl->mlx_ptr != NULL)
		mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
	freemap(sl);
	write(1, "\n\033[31m[ so_long closed Successfully ]\n", 39);
	exit(0);
}

int	freemap(t_long *sl)
{
	int	i;

	i = 0;
	if (sl->maptofree == -1)
		return (1);
	while (i < sl->y)
	{
		free(sl->map[i]);
		i++;
	}
	if (sl->map)
		free(sl->map);
	return (1);
}

int	showerror(t_long *sl, char *str)
{
	write(1, "\033[31mError\n\033[0;37m", 12);
	ft_putstr(str);
	write(1, "\n", 1);
	freeandexit(sl);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
