/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:21:29 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/10 02:14:24 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int main(int argc, char **argv)
{
    t_long      solong;

    if (argc == 1)
		  return(0);
    parsing(&solong, argv[1]);
    display(&solong);
    return(0);
}

