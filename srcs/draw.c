#include "cub3d.h"
#include <math.h>

static void draw_floor_ceil(t_game *g)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_X)
	{
		y = -1;
		while (++y < WIN_Y / 2)
		{
			g->mlx->tmp[y][x] = g->cub->ce;
			g->mlx->tmp[WIN_Y - y - 1][x] = g->cub->fl;
		}
	}
}

static void	calc_wall(t_game *g, t_ray *r, t_wall *w)
{
	double	wall_x;

	if (r->side == 0 || r->side == 1)
		r->wall_dist = (r->map_x - g->vec->pos_x + (1 - r->step_x) / 2) / r->raydir_x;
	else
		r->wall_dist = (r->map_y - g->vec->pos_y + (1 - r->step_y) / 2) / r->raydir_y;
	w->line_h = (WIN_Y / r->wall_dist);

	w->draw_start = -w->line_h / 2 + WIN_Y / 2;
	if (w->draw_start < 0)
		w->draw_start = 0;

	w->draw_end = w->line_h / 2 + WIN_Y / 2;
	if (w->draw_end >= WIN_Y)
		w->draw_end = WIN_Y - 1;

	w->side = r->side;
	if (r->side == 0 || r->side == 1)
		wall_x = g->vec->pos_y + r->wall_dist * r->raydir_y;
	else
		wall_x = g->vec->pos_x + r->wall_dist * r->raydir_x;
	wall_x -= floor(wall_x);
	w->tex_x = (int)(wall_x * (double)PIX);
	if (((r->side == 0) || (r->side == 1)) && r->raydir_x > 0)
		w->tex_x = PIX - w->tex_x - 1;
	if (((r->side == 2) || (r->side == 3)) && r->raydir_y < 0)
		w->tex_x = PIX - w->tex_x - 1;
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
	while (i < w.draw_end)
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
	int x;
	int y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
			g->mlx->img.data[y * WIN_X + x] = g->mlx->tmp[y][x];
	}
	mlx_put_image_to_window(g->mlx->mlx_ptr, \
		g->mlx->mlx_win, g->mlx->img.img_ptr, 0, 0);
}

int draw_game(t_game *g)
{
	int		x;
	t_ray	r;
	t_wall	w;

	x = -1;
	draw_floor_ceil(g);
	while (++x < WIN_X)
	{
		calc_ray(g->vec, &r, x);
		dda(&r, g->cub);
		calc_wall(g, &r, &w);
		map_line(g, w, x);
	}
	draw(g);
	return (0);
}
