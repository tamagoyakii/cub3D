#include "cub3d.h"
#include <stdio.h>
# define PIX 16

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

void	init_texture(t_game *g)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		g->mlx->texture[i] = malloc(sizeof(int) * PIX * PIX);
		//null처리
		//return int로 바꾸기
	}
	//0으로 초기화
	my_xpm_to_img(g, 0, g->cub->ea);
	my_xpm_to_img(g, 1, g->cub->we);
	my_xpm_to_img(g, 2, g->cub->no);
	my_xpm_to_img(g, 3, g->cub->so);
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
