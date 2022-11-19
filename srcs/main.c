#include "cub3d.h"
# include <stdio.h>

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
	//mlx_init() 실패시 처리 필요;
	g->mlx->mlx_win = mlx_new_window(g->mlx->mlx_ptr, WIN, WIN, "cub3D");
	// size는 임의로 600*600 했음. window() 실패시 처리 필요;

	/**
	 * Dear. jihyukim 😘
	 * 여기에 
	 * 
	 * mlx_loop_hook(); --> 내 파트
	 * mlx_hook(); --> 언니파트
	 * 
	 * 이렇게 하면 되겠당 ~~
	*/
	mlx_hook(g->mlx->mlx_win, ON_KEYDOWN, 0, key_press, g);			// 키 조작
	mlx_hook(g->mlx->mlx_win, ON_DESTROY, 0, close_win, g->mlx);	// x 버튼 클릭 시 윈도우 종료
	mlx_loop(g->mlx->mlx_ptr);
}

int main(int argc, char **argv)
{
	t_game	game;
	t_map	map;
	t_mlx	mlx;

	game.map = &map;
	game.mlx = &mlx;
	if (argc != 2)
		err_exit("Need 2 arguments", NULL);
	parse(argv[1], &map);
	start_cub3d(&game);	// draw & move
	return (0);
}
