/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:03:20 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/12 19:48:49 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# if defined(__APPLE__) && defined(__MACH__)
#  define ADVANCE 13
#  define BACK 1
#  define RIGHT 2
#  define LEFT 0
#  define ESC 53
#  define RED_BUTTON 79
#  define CLOSERED 17
# else
#  define ADVANCE 119
#  define BACK 115
#  define RIGHT 100
#  define LEFT 97
#  define ESC 65307
#  define RED_BUTTON 79
#  define CLOSERED 33
# endif

typedef struct s_long
{
	char			**map;
	int				xscreen;
	int				yscreen;
	int				x;
	int				y;
	int				oldx;
	int				collectibleparse;
	int				exitparse;
	int				player_x;
	int				player_y;
	int				lastplayer_x;
	int				lastplayer_y;
	int				collectible;
	int				collectibletotal;
	int				move;
	int				playerset;
	int				exitset;
	int				collectibleset;

	char			*pxl;
	int				bpp;
	int				s_line;
	double			casetotal;
	double			casein;
	int				ed;
    int             spritebomb;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				keyboard[70000];
	int				maptofree;

	int				bpp_text[16];
	int				sline_text[16];
	int				ed_text[16];
	char			*ptr_text[16];
	void			*text[16];
	int				widthtext[16];
	int				heighttext[16];
	int				actualtext;
	unsigned int	color;
}					t_long;

char	*recurs(int depth, int *ret, int fd);
int		get_next_line(int fd, char **out);
size_t	ft_strlen(const char *s);

int		get_x_and_y(t_long *sl, char *argv);
int		visible(t_long *sl);
int fixbomb(t_long *sl);
int	gettextnumbomb(t_long *sl);
char	*ft_strcpy(char *dest, char *src);
int		parsing(t_long *sl, char *argv);
int	loadtexture2(t_long *sl);
int		stockmap(t_long *sl, char *argv);
int		mallocmap(t_long *sl);
int		render_calcul(t_long *sl);
int		render(t_long *sl);
void	floodandfill2(t_long *sl, int mapy, int mapx);
int		checkmap(t_long *sl);
int		numberblank(char *str);
int		get_next_line(int fd, char **line);
int		printtexture(t_long *sl, int starter_X, int starter_Y);
int		showerror(t_long *sl, char *str);
int		checkcubextension(char *str, t_long *sl);
int		pos_player(t_long *sl);
void	ft_putstr(char *str);
int		initplayer(t_long *sl);
int		loadtexture(t_long *sl);
int		gettextnum(int X, int Y, t_long *sl);
int		moveplayer(int nb, t_long *sl);
int		checkaremove(t_long *sl);
int		stockline(t_long *sl, char *line, int nb);
int		checkifgood(char c);
void	ft_putchar(char c);
char	replacechar(char c);
void	ft_putnbr(int nb);
int		checkthewall(t_long *sl);
int		floodandfill(t_long *sl, int mapy, int mapx);
int		displaymove(t_long *sl, int nb);
int		freemap(t_long *sl);
void	resetkeyboard(t_long *sl);
int		checkaround(int mapx, int mapy, t_long *sl);
int		ft_key_hit(int keycode, t_long *sl);
int		ft_key_release(int keycode, t_long *sl);
int		ft_keyboard(t_long *display);
int		closebyredbutton(t_long *sl);
int		freeandexit(t_long *sl);
int		display(t_long *sl);
int		go_hooking(t_long *sl);
int		createwindow(t_long *sl);
int		key_loop(t_long *sl);
int		put_pxl(t_long *sl, int x, int y, unsigned int c);
int		initvar(t_long *sl);

#endif
