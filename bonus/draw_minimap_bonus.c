#include "cub3d_bonus.h"

static void	set_minimap(t_mlx *m, int y, int x, char op)
{
	int color;
	int i;
	int j;

	if (op == '2')
		color = 0x00fd00;
	if (op == '1')
		color = 0X000000;
	if (op == '0')
		color = 0Xffffff;
	if (op == ' ')
		color = 0X727272;
	if (op == 'p')
		color = 0xff0000;
	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
			m->tmp[(y * 5) + i][(x * 5) + j] = color;
	}
}

void	draw_minimap(t_game *g)
{
	int		y;
	int 	x;

	y = -1;
	while (++y < g->cub->h)
	{
		x = -1;
		while (++x < g->cub->w)
		{
			if (y == (int)g->vec->pos_y && x == (int)g->vec->pos_x)
				set_minimap(g->mlx, y, x, 'p');
			else
				set_minimap(g->mlx, y, x, g->cub->map[y][x]);

		}
	}
}