#include "cub3d.h"

static void draw_floor_ceil(t_game *g)
{
	int	i;

	i = -1;
	while (++i < WIN_Y / 2)
		ft_memset(g->mlx->tmp[i], g->cub->ce, sizeof(int) * WIN_X);
	i--;
	while (++i < WIN_Y)
		ft_memset(g->mlx->tmp[i], g->cub->fl, sizeof(int) * WIN_X);
}

static void	calc_walldist(t_game *g, t_ray *r)
{
	(void) g;
	(void) r;
}

int draw_game(t_game *g)
{
	int	x;
	t_ray	r;

	x = -1;
	draw_floor_ceil(g);
	while (++x < WIN_X)
	{
		calc_ray(g->vec, &r, x);
		dda(&r, g->cub);
		calc_walldist(g, &r);
	}
	//drawing ~
	return (0);
}
