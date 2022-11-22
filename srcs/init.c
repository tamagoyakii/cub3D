#include "cub3d.h"

void	init_cub(t_cub *cub)
{
	cub->no = NULL;
	cub->so = NULL;
	cub->ea = NULL;
	cub->we = NULL;
	cub->fl = UNDEF;
	cub->ce = UNDEF;
	cub->h = 0;
	cub->w = 0;
}

void	init_vec(t_vec *vec)
{
	vec->dir_x = UNDEF;
	vec->dir_y = UNDEF;
	vec->pln_x = UNDEF;
	vec->pln_y = UNDEF;
	vec->pos_x = UNDEF;
	vec->pos_y = UNDEF;
}

int	init_mlx(t_mlx *m)
{
	int		i;

	m->tmp = malloc(sizeof(int *) * WIN_Y);
	if (m->tmp == NULL)
		return (FAIL);
	i = -1;
	while (++i < WIN_Y)
	{
		m->tmp[i] = malloc(sizeof(int) * WIN_X);
		if (m->tmp[i] == NULL)
			return (FAIL);
		ft_bzero(m->tmp[i], sizeof(int) * WIN_X);
	}
	//texture init();
	//image init();
	return (SUCCESS);
}
