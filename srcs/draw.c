#include "cub3d.h"
#include <stdio.h>

static void draw_floor_ceil(t_game *g)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_X)
	{
		y = -1;
		while (++y < WIN_Y)
		{
			g->mlx->tmp[y][x] = g->cub->ce;
			g->mlx->tmp[WIN_Y - y - 1][x] = g->cub->fl;
		}
	}
}

static void	calc_wall(t_game *g, t_ray *r, t_wall *w)
{
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
	//texture 추가 전 color로 테스트 중입니다.
	w->color = 16711680;
	if (r->side > 1) w->color = w->color / 2; 
}

void	map_line(t_game *g, t_wall w, int x)
{
	int y;
	
	y = w.draw_start;
	while (y < w.draw_end)
	{
		g->mlx->tmp[y][x] = w.color;
		y++;
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
			mlx_pixel_put(g->mlx->mlx_ptr, g->mlx->mlx_win, x, y, g->mlx->tmp[y][x]);
	}
}

int draw_game(t_game *g)
{
	int	x;
	t_ray		r;
	t_wall	w;

	x = -1;
	draw_floor_ceil(g);
	/*****test******/
	// printf("%d", g->cub->ce);
	// for (int y = 0 ; y < WIN_Y ; y++){
	// 	for(int x = 0 ; x < WIN_X; x++)
	// 		printf("%d ", g->mlx->tmp[y][x]);
	// 	printf("\n");
	// }
	/*****test******/
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
