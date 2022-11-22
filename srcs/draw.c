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

static void	calc_wall(t_game *g, t_ray *r, t_wall *w)
{
	if (r->side == 0 || r->side == 1)
		r->wall_dist = (r->map_x - g->vec->pos_x + (1 - r->step_x) / 2) / r->raydir_x;
	else
		r->wall_dist = (r->map_y - g->vec->pos_y + (1 - r->step_y) / 2) / r->raydir_y;
	w->line_h = (WIN_Y / r->wall_dist);
	w->draw_start = -w->line_h / 2 + WIN_Y / 2;
	if(w->draw_start < 0)
		w->draw_start = 0;
	w->draw_end = w->line_h / 2 + WIN_Y / 2;
	if(w->draw_end >= WIN_Y)
		w->draw_end = WIN_Y - 1;
}

int draw_game(t_game *g)
{
	int	x;
	t_ray	r;
	t_wall	w;

	x = -1;
	draw_floor_ceil(g);
	//calculate ray strt and initialize tmp
	while (++x < WIN_X) 
	{
		calc_ray(g->vec, &r, x);
		dda(&r, g->cub);
		calc_wall(g, &r, &w);
	}
	//draw on map
	return (0);
}
