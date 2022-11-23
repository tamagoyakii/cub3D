#include "cub3d.h"
#include <stdlib.h>

void	init_cub(t_cub *c)
{
	c->no = NULL;
	c->so = NULL;
	c->ea = NULL;
	c->we = NULL;
	c->map = NULL;
	c->fl = UNDEF;
	c->ce = UNDEF;
	c->h = 0;
	c->w = 0;
}

void	init_vec(t_vec *v, char p)
{
	v->pos_x = 10;
	v->pos_y = 10;
	if (p == 'N' || p == 'S')
	{
		v->dir_x = 0;
		v->dir_y = 1;
		v->pln_x = 0.66;
		v->pln_y = 0;
		if (p == 'N')
		{
			v->dir_y *= -1;
			v->pln_x *= -1;
		}
	}
	if (p == 'E' || p == 'W')
	{
		v->dir_x = 1;
		v->dir_y = 0;
		v->pln_x = 0;
		v->pln_y = 0.66;
		if (p == 'E')
			v->dir_x *= -1;
		if (p == 'W')
			v->pln_y *= -1;
	}
}

static int	init_texture(t_mlx *m, t_cub *c)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		m->texture[i] = malloc(sizeof(int) * PIX * PIX);
		if (m->texture[i] == NULL)
			return (FAIL);
		ft_bzero(m->texture[i], sizeof(int) * PIX * PIX);
	}
	my_xpm_to_img(m, 0, c->ea);
	my_xpm_to_img(m, 1, c->we);
	my_xpm_to_img(m, 2, c->no);
	my_xpm_to_img(m, 3, c->so);
	m->img.img_ptr = mlx_new_image(m->mlx_ptr, \
		WIN_X, WIN_Y);
	m->img.data = (unsigned int *)mlx_get_data_addr(m->img.img_ptr, \
		&m->img.bpp, &m->img.size_l, &m->img.endian);
	return (SUCCESS);
}

static int	init_tmp(t_mlx *m)
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

int init_mlx(t_game *g)
{
	int	err;
	int	i;

	i = -1;
	err = init_tmp(g->mlx);
	if (!err)
		err = init_texture(g->mlx, g->cub);
	if (err)
	{
		free_double_int(g->mlx->tmp);
		while (g->mlx->texture[++i])
			free(g->mlx->texture[i]);
	}
	return (err);
}
