/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeandexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 23:22:24 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/08 23:23:52 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int			freeandexit(t_long *sl)
{
	mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
//	freemap(sl);
	printf("\n\033[31m[ so_long closed Successfully ]\n");
	exit(0);
}