#include "cub3d.h"

void	my_xpm_to_img(t_mlx *m, int dir, char *wall)
{
	int	x;
	int	y;
	int	w;
	int	h;
	t_img	img;

	y = -1;
	img.img_ptr = mlx_xpm_file_to_image(m->mlx_ptr, \
	wall, &w, &h);
	img.data = (unsigned int *)mlx_get_data_addr(img.img_ptr,\
	&img.bpp, &img.size_l, &img.endian);
	while (++y < h)
	{
		x = -1;
		while (++x < w)
			m->texture[dir][w * y + x] = img.data[w * y + x];
	}
	mlx_destroy_image(m->mlx_ptr, img.img_ptr);
}
