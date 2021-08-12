/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:34:19 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/12 01:28:50 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	parsing(t_long *sl, char *argv)
{
	checkcubextension(argv, sl);
	get_x_and_y(sl, argv);
	mallocmap(sl);
	stockmap(sl, argv);
	checkmap(sl);
	return (0);
}

int	get_x_and_y(t_long *sl, char *filename)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(filename, O_RDONLY);
	ret = get_next_line(fd, &line);
	sl->oldx = ft_strlen(line);
	while (line[numberblank(line)] == '1' || line[numberblank(line)] == '0')
	{
		sl->x = ft_strlen(line);
		if (sl->x != sl->oldx)
			showerror(sl, "Map is not rectangular");
		sl->oldx = sl->x;
		if (ret != -1)
			free(line);
		ret = get_next_line(fd, &line);
		sl->y++;
	}
	if (sl->y == 0 || sl->x == 0)
		showerror(sl, "Map is not correct or not well formated");
	sl->yscreen = sl->y * 64;
	sl->xscreen = sl->x * 64;
	close(fd);
	return (0);
}

char	replacechar(char c)
{
	if (c == '0')
		return ('a');
	if (c == '1')
		return ('1');
	if (c == 'P')
		return ('c');
	if (c == 'E')
		return ('d');
	if (c == 'C')
		return ('e');
	return (0);
}

int	initvar(t_long *sl)
{
	sl->keyboard[BACK] = 0;
	sl->keyboard[RED_BUTTON] = 0;
	sl->keyboard[ESC] = 0;
	sl->keyboard[LEFT] = 0;
	sl->keyboard[RIGHT] = 0;
	sl->keyboard[ADVANCE] = 0;
	sl->bpp = 0;
	sl->casein = 0;
	sl->casetotal = 0;
	sl->y = 0;
	sl->x = 0;
	sl->collectible = 0;
	sl->collectibletotal = 0;
	sl->s_line = 0;
	sl->maptofree = -1;
	sl->move = 0;
	sl->playerset = 0;
	sl->collectibleset = 0;
	sl->exitset = 0;
	sl->lastplayer_x = -1;
	sl->lastplayer_y = -1;
	sl->mlx_ptr = NULL;
	return (0);
}
