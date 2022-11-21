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

void	raycasting(t_game *g)
{
	int	x;
	t_ray	r;

	x = -1;
	// draw_floor_ceil();
	while (++x < WIN_X)
	{
		calc_ray(g->vec, &r, x);
		//dda();
	}
}

int draw_game(t_game *g)
{
	raycasting(g);
	//drawing !
	return (0);
}
