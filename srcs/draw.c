#include "cub3d.h"
#include <math.h>

static double	calc_dis(t_vec *v, t_ray *r)
{
	if (r->side == 0 || r->side == 1)
	{
		r->wall_dist = (r->map_x - v->pos_x + \
			(1 - r->step_x) / 2) / r->raydir_x;
		if (r->wall_dist <= 0.000001)
			r->wall_dist = 0.00001;
		return (v->pos_y + r->wall_dist * r->raydir_y);
	}
	r->wall_dist = (r->map_y - v->pos_y + \
		(1 - r->step_y) / 2) / r->raydir_y;
	if (r->wall_dist <= 0.000001)
		r->wall_dist = 0.00001;
	return (v->pos_x + r->wall_dist * r->raydir_x);
}

static void	calc_wall(t_vec *v, t_ray *r, t_wall *w)
{
	double	wall_x;

	wall_x = calc_dis(v, r);
	wall_x -= floor(wall_x);
	w->line_h = (WIN_Y / r->wall_dist);
	w->side = r->side;
	w->tex_x = (int)(wall_x * (double)PIX);
	if (((r->side == 0) || (r->side == 1)) && r->raydir_x < 0)
		w->tex_x = PIX - w->tex_x - 1;
	if (((r->side == 2) || (r->side == 3)) && r->raydir_y > 0)
		w->tex_x = PIX - w->tex_x - 1;
	w->draw_start = -w->line_h / 2 + WIN_Y / 2;
	if (w->draw_start < 0)
		w->draw_start = 0;
	w->draw_end = w->line_h / 2 + WIN_Y / 2;
	if (w->draw_end >= WIN_Y)
		w->draw_end = WIN_Y - 1;
}

void	map_line(t_game *g, t_wall w, int x)
{
	double	step;
	double	tex_pos;
	int		i;
	int		tex_y;
	int		color;

	step = 1.0 * PIX / w.line_h;
	tex_pos = (w.draw_start - WIN_Y / 2 + w.line_h / 2) * step;
	i = w.draw_start;
	while (i <= w.draw_end)
	{
		tex_y = (int)tex_pos & (PIX - 1);
		tex_pos += step;
		color = g->mlx->texture[w.side][PIX * tex_y + w.tex_x];
		g->mlx->tmp[i][x] = color;
		i++;
	}
}

void	draw(t_game *g)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
			g->mlx->img.data[y * WIN_X + x] = g->mlx->tmp[y][x];
	}
	mlx_put_image_to_window(g->mlx->mlx_ptr, \
		g->mlx->mlx_win, g->mlx->img.img_ptr, 0, 0);
}

int	draw_game(t_game *g)
{
	int		x;
	t_ray	r;
	t_wall	w;

	draw_floor_ceil(g);
	x = -1;
	while (++x < WIN_X)
	{
		calc_ray(g->vec, &r, x);
		dda(&r, g->cub);
		calc_wall(g->vec, &r, &w);
		map_line(g, w, x);
	}
	draw(g);
	return (0);
}
