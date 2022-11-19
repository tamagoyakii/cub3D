#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <math.h>

typedef enum e_keycode {
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_R = 39,
	KEY_L = 37,
	KEY_ESC = 53,
}	t_keycode;

typedef enum e_x_event {
	ON_KEYDOWN = 2,
	ON_DESTROY = 17,
}	t_x_event;

typedef enum e_size {
	PIX = 16,
	WIN = 600
}	t_size;

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*mlx_win;
}	t_mlx;

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		fl;
	int		ce;
	char	**map;
	int		h;
	int		w;
}	t_map;

typedef struct s_game {
	struct s_map	*map;
	struct s_mlx	*mlx;
}	t_game;

/**********
* main.c  *
**********/
void	err_exit(const char *str, t_game *game);
int		close_win(t_mlx *mlx);

/**********
* move.c  *
**********/
int		key_press(int keycode, t_game *g);

#endif
