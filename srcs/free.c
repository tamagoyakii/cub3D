#include "cub3d.h"

void	free_double_ptr(void **ptr)
{
	int	i = -1;

	if (!ptr)
		return;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

void	free_cub(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->no)
		free(cub->no);
	if (cub->so)
		free(cub->so);
	if (cub->we)
		free(cub->we);
	if (cub->ea)
		free(cub->ea);
	free_double_ptr((void **)cub->map);
}