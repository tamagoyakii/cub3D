#include "cub3d.h"
#include <stdio.h>

/** print err msg & exit(1) !! */
void	err_exit(const char *str, t_game *game)
{
	printf("Error\n%s\n", str);
	if (game)
	{
		//game 구조체 존재 시 free 하는 함수 추후에 넣어줍시당.
		//game 구조체가 없을 경우 NULL을 넣습니다.
	}
	exit(1);
}

int	close_win(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	printf("See you later!\n");
	exit(0);
}

void	start_cub3d(t_game *g)
{
	g->mlx->mlx_ptr = mlx_init();
	// mlx_init() 실패시 처리 필요;
	g->mlx->mlx_win = mlx_new_window(g->mlx->mlx_ptr, WIN_X, WIN_Y, "cub3D");
	// size는 e_size 에서 설정 가능. window() 실패시 처리 필요;
	//init_mlx(g);
	mlx_loop_hook(g->mlx->mlx_ptr, &draw_game, g);
	mlx_hook(g->mlx->mlx_win, ON_KEYDOWN, 0, key_press, g);			// 키 조작
	mlx_hook(g->mlx->mlx_win, ON_DESTROY, 0, close_win, g->mlx);	// x 버튼 클릭 시 윈도우 종료
	mlx_loop(g->mlx->mlx_ptr);
}

int main(int argc, char **argv)
{
	t_game	game;
	t_cub	cub;
	t_mlx	mlx;

	game.cub = &cub;
	game.mlx = &mlx;
	if (argc != 2)
		err_exit("Need 2 arguments", NULL);
	// t_game 전체 init 필요
	parse(argv[1], &cub);
	start_cub3d(&game);	// draw & move
	return (0);
}
