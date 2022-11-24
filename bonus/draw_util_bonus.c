#include "cub3d_bonus.h"

void	my_xpm_to_img(t_mlx *m, int dir, char *wall)
{
	t_img	img;
	int		x;
	int		y;
	int		w;
	int		h;

	img.img_ptr = mlx_xpm_file_to_image(m->mlx_ptr, \
	wall, &w, &h);
	img.data = (unsigned int *)mlx_get_data_addr(img.img_ptr, \
		&img.bpp, &img.size_l, &img.endian);
	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
			m->texture[dir][w * y + x] = img.data[w * y + x];
	}
	mlx_destroy_image(m->mlx_ptr, img.img_ptr);
}

void	draw_floor_ceil(t_game *g)
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
