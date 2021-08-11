/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:34:19 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/11 02:10:36 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int parsing(t_long *sl, char *argv)
{
    initvar(sl);
    checkcubextension(argv, sl);
    get_x_and_y(sl, argv);
    mallocmap(sl);
    stockmap(sl, argv);
    checkmap(sl);
    return(0);
}

int get_x_and_y(t_long *sl, char *filename)
{
    int fd;
    int ret;
    char *line;

    fd = open(filename, O_RDONLY);
    ret = get_next_line(fd, &line);
    while (line[numberblank(line)] == '1' || line[numberblank(line)] == '0')
    {
        sl->X = ft_strlen(line);
        if (ret != -1)
            free(line);
        ret = get_next_line(fd, &line);
        sl->Y++;
    }
    if (sl->Y == 0 || sl->X == 0)
        showerror(sl, "Map is not correct or not well formated");
    printf("X >> %d | Y >> %d", sl->X, sl->Y);
    sl->Yscreen = sl->Y * 64;
    sl->Xscreen = sl->X * 64;
    close(fd);
    return(0);
}

int stockmap(t_long *sl, char *filename)
{
    int fd;
    int ret;
    int nb;
    char *line;

    nb = 0;
    fd = open(filename, O_RDONLY);
    ret = get_next_line(fd, &line);
    while (line[numberblank(line)] == '1' || line[numberblank(line)] == '0')
    {
        stockline(sl, line, nb);
        if (ret != -1)
            free(line);
        ret = get_next_line(fd, &line);
        nb++;
    }
    return(0);
}

int stockline(t_long *sl, char *line, int nb)
{
    int index;

    index = 0;
    while (line[index])
    {
        sl->map[nb][index] = line[index];
        if (line[index] == 'P')
        {
            sl->playerset++;
            sl->player_x = index;
            sl->player_y = nb;
        }
        if (line[index] == 'E')
            sl->exitset++;
        if (line[index] == 'C')
            sl->collectibletotal++;
        if (line[index] != 'P' && line[index] != 'E' && line[index] != 'C' && line[index] != '1' && line[index] != '0')
            showerror(sl, "Wrong character in map");
        index++;
    }
    return(0);
}

int     initvar(t_long *sl)
{
    sl->keyboard[BACK] = 0;
	sl->keyboard[RED_BUTTON] = 0;
	sl->keyboard[ESC] = 0;
	sl->keyboard[LEFT] = 0;
	sl->keyboard[RIGHT] = 0;
	sl->keyboard[ADVANCE] = 0;
    sl->bpp = 0;
    sl->Y = 0;
    sl->X = 0;
    sl->collectible = 0;
    sl->collectibletotal = 0;
	sl->s_line = 0;
    sl->maptofree = -1;
    sl->move = 0;
    sl->playerset = 0;
    sl->collectibleset = 0;
    sl->exitset = 0;
    sl->mlx_ptr = NULL;
    return(0);
}

int			mallocmap(t_long *sl)
{
	int i;

	i = 0;
	sl->map = malloc(sizeof(char*) * sl->Y);
	while (i < sl->Y)
	{
		sl->map[i] = malloc(sizeof(char) * (sl->X + 1));
		i++;
	}
    sl->maptofree = 1;
	return (1);
}

