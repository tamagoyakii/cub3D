#include "cub3d.h"

int	close_win(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	// printf("See you later!\n");
	exit(0);
}

int main(void)
{
	return (0);
}
