/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:21:29 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/11 22:59:57 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int main(int argc, char **argv)
{
    t_long      solong;

    initvar(&solong);
    if (argc == 1)
		  showerror(&solong, "Missing map (./so_long maps/intra.ber)");
    parsing(&solong, argv[1]);
    display(&solong);
    return(0);
}

