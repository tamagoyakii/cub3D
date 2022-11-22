#include "cub3d.h"
#include <stdio.h>

static void	init_cub(t_cub *c)
{
	ft_bzero(c, sizeof(t_cub));
	c->fl = -1;
	c->ce = -1;
	c->h = 0;
	c->w = 0;
}

static void	init_vec(t_vec *v)
{
	ft_bzero(v, sizeof(t_vec));
}

static int	init_mlx(t_mlx *m)
{
	int		i;

	ft_bzero(m, sizeof(t_mlx));
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