#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <math.h>

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
