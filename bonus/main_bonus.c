#include "cub3d_bonus.h"
#include <stdio.h>

void	err_exit(const char *str)
{
	if (str)
		printf("Error\n%s\n", str);
	else
		perror("Error\n");
	exit(1);
}

int	close_win(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	printf("See you later!\n");
	exit(0);
}

static void	start_cub3d(t_game *g)
{
	g->mlx->mlx_ptr = mlx_init();
	if (!g->mlx->mlx_ptr)
		err_exit("mlx failed.");
	g->mlx->mlx_win = mlx_new_window(g->mlx->mlx_ptr, WIN_X, WIN_Y, "cub3D");
	if (!g->mlx->mlx_win)
		err_exit("mlx failed.");
	init_mlx(g);
	mlx_loop_hook(g->mlx->mlx_ptr, &draw_game, g);
	mlx_hook(g->mlx->mlx_win, ON_KEYDOWN, 0, &key_press, g);
	mlx_hook(g->mlx->mlx_win, ON_DESTROY, 0, &close_win, g->mlx);
	mlx_hook(g->mlx->mlx_win, ON_MOUSEMOVE, 0, &mouse_rotate, g);
	mlx_loop(g->mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_cub	cub;
	t_mlx	mlx;
	t_vec	vec;
	t_mouse	mouse;

	if (argc != 2)
		err_exit("TWO ARGUMENTS ONLY!!");
	game.cub = &cub;
	game.vec = &vec;
	game.mlx = &mlx;
	game.mouse = &mouse;
	ft_bzero(&mouse, sizeof(t_mouse));
	parse(argv[1], &game);
	start_cub3d(&game);
	return (0);
}
