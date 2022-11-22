#include "cub3d.h"

void	init_cub(t_cub *c)
{
	c->no = NULL;
	c->so = NULL;
	c->ea = NULL;
	c->we = NULL;
	c->fl = UNDEF;
	c->ce = UNDEF;
	c->h = 0;
	c->w = 0;
}

void	init_vec(t_vec *v)
{
	v->dir_x = UNDEF;
	v->dir_y = UNDEF;
	v->pln_x = UNDEF;
	v->pln_y = UNDEF;
	v->pos_x = UNDEF;
	v->pos_y = UNDEF;
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
