#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>

#  define ADVANCE 13
#  define BACK 1
#  define RIGHT 2
#  define LEFT 0
#  define ESC 53
#  define RED_BUTTON 79
#  define CLOSERED 17

typedef struct		s_long
{
	char			**map;
	int				X;
	int				Y;

	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				keyboard[100000];
}					t_long;

int get_x_and_y(t_long *sl, char *argv);
int parsing(t_long *sl, int argc, char argv);
int stockmap(t_long *sl, char argv);
int			mallocmap(t_long *sl, char *argv);

int		ft_key_hit(int keycode, t_long *sl);
int		ft_key_release(int keycode, t_long *sl);
int		ft_keyboard(t_long *display);
int		closebyredbutton(t_long *sl);

int			freeandexit(t_long *sl);

# endif SO_LONG_H