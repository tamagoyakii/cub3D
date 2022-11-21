#include "cub3d.h"
#include <math.h>

void	init_ray(t_vec *v, t_ray *r, int x)
{
	r->cam_x = 2 * x /(double)WIN_X - 1;
	r->raydir_x = v->dir_x + v->pln_x * r->cam_x;
	r->raydir_y = v->dir_y + v->pln_y * r->cam_x;
	r->map_x = (int)v->pos_x;
	r->map_y = (int)v->pos_y;
	r->deltadist_x = fabs(1/r->raydir_x);
	r->deltadist_y = fabs(1/r->raydir_y);
	r->hit = 0;
}

void	calc_ray(t_vec *v, t_ray *r, int x)
{
	init_ray(v, r, x);
	if (r->raydir_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (v->pos_x - r->map_x) * r->deltadist_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = (r->map_x + 1.0 - v->pos_x) * r->deltadist_x;
	}
	if(r->raydir_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (v->pos_y - r->map_y) * r->deltadist_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = (r->map_y + 1.0 - v->pos_y) * r->deltadist_y;
	}
}

void	dda(t_ray* r, t_cub *cub)
{
	while(r->hit == 0)
	{
		if (r->sidedist_x < r->sidedist_y)
		{
			r->sidedist_x += r->deltadist_x;
			r->map_x += r->step_x;
			if (r->step_x == 1)
				r->side = 0; //W
			else
				r->side = 1; //E
		}
		else
		{
			r->sidedist_y += r->deltadist_y;
			r->map_y += r->step_y;
			if (r->step_y == 1)
				r->side = 0; //S
			else
				r->side = 1; //N
		}
		if (cub->map[r->map_x][r->map_y] > 0) 
			r->hit = 1;
	}
}

void draw_floor_ceil(t_game *g)
{
	int	i;

	i = -1;
	while (++i < WIN_Y / 2)
		ft_memset(g->mlx->tmp[i], g->cub->ce, sizeof(int) * WIN_X);
	i--;
	while (++i < WIN_Y)
		ft_memset(g->mlx->tmp[i], g->cub->fl, sizeof(int) * WIN_X);
}

void	raycasting(t_game *g)
{
	int	x;
	t_ray	r;

	x = -1;
	draw_floor_ceil(g);
	while (++x < WIN_X)
	{
		calc_ray(g->vec, &r, x);
		dda(&r, g->cub);
	}
}

int draw_game(t_game *g)
{
	raycasting(g);
	//drawing !
	return (0);
}