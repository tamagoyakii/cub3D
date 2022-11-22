#include "cub3d.h"
#include <stdio.h>

static void	init_cub(t_cub *c)
{
	c->no = NULL;
	c->so = NULL;
	c->ea = NULL;
	c->we = NULL;
	c->fl = UNDEFINED;
	c->ce = UNDEFINED;
	c->h = 0;
	c->w = 0;
}

static void	init_vec(t_vec *v)
{
	v->dir_x = UNDEFINED;
	v->dir_y = UNDEFINED;
	v->pln_x = UNDEFINED;
	v->pln_y = UNDEFINED;
	v->pos_x = UNDEFINED;
	v->pos_y = UNDEFINED;
}

static int	init_mlx(t_mlx *m)
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

int	init_struct(t_game *g)
{
	t_cub	cub;
	t_mlx	mlx;
	t_vec	vec;

	init_cub(&cub);
	init_vec(&vec);
	if (init_mlx(&mlx))
		return (FAIL);
	g->cub = &cub;
	g->vec = &vec;
	g->mlx = &mlx;
	return (SUCCESS);
}