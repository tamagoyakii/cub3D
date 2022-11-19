#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <math.h>

typedef enum e_keys {
	KEY_PRESS = 2,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_R = 39,
	KEY_L = 37,
	KEY_ESC = 53,
}	t_keys;

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

#endif
