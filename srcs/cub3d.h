#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2


typedef struct s_mlx t_mlx;
typedef struct s_map t_map;

typedef struct s_game {
	t_map *map;
	t_mlx *mlx;
} t_game;

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*mlx_win;
} t_mlx;

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

#endif
