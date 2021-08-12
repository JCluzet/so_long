/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:48:57 by mojacque          #+#    #+#             */
/*   Updated: 2021/08/12 15:23:10 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
char			*ft_alloc(size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strcpy(char *dest, char *src);
int get_this_line(char **line, size_t a, char *lines);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
