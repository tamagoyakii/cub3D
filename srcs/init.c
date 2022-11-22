#include "cub3d.h"
#include <stdlib.h>

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
	v->dir_x = 0;
	v->dir_y = 0;
	v->pln_x = 0;
	v->pln_y = 0;
	v->pos_x = 0;
	v->pos_y = 0;
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
	g->mlx->img.img_ptr = mlx_new_image(g->mlx->mlx_ptr, \
		WIN_X, WIN_Y);
	g->mlx->img.data = (unsigned int *)mlx_get_data_addr(g->mlx->img.img_ptr, \
		&g->mlx->img.bpp, &g->mlx->img.size_l, &g->mlx->img.endian);
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
	return (SUCCESS);
}
