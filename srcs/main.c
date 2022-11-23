#include "cub3d.h"
#include <stdio.h>

/** print err msg & exit(1) !! */
void	err_exit(const char *str, t_game *g, int err)
{
	if (str)
		printf("Error\n%s\n", str);
	if (err & E_PARSE)
		free_cub(g->cub);
	// 이후의 에러들과 그에 따른 free 추가
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
		err_exit("mlx failed", g, E_PARSE);
	g->mlx->mlx_win = mlx_new_window(g->mlx->mlx_ptr, WIN_X, WIN_Y, "cub3D");
	if (!g->mlx->mlx_win)
		err_exit("mlx failed", g, E_PARSE);
	if (init_mlx(g))
		err_exit("mlx failed", g, E_PARSE);
	mlx_loop_hook(g->mlx->mlx_ptr, &draw_game, g);
	mlx_hook(g->mlx->mlx_win, ON_KEYDOWN, 0, &key_press, g);			// 키 조작
	mlx_hook(g->mlx->mlx_win, ON_DESTROY, 0, &close_win, g->mlx);	// x 버튼 클릭 시 윈도우 종료
	mlx_loop(g->mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_cub	cub;
	t_mlx	mlx;
	t_vec	vec;

	if (argc != 2)
		err_exit("Wrong arguments", 0, 0);
	game.cub = &cub;
	game.vec = &vec;
	game.mlx = &mlx;
	init_cub(&cub);
	init_vec(&vec);
	if (parse(argv[1], game.cub))
		err_exit("Parsing failed", &game, E_PARSE);
	/***test */
	vec.pos_x = 3.5;
	vec.pos_y = 3.5;
	vec.dir_x = 0;
	vec.dir_y = -1;
	vec.pln_x = -0.66;
	vec.pln_y = 0;
	/****test */
	start_cub3d(&game);
	return (0);
}
