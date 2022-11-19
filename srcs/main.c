#include "cub3d.h"
# include <stdio.h>

/** print err msg & exit(1) !! */
void err_exit(const char *str, t_game *game)
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
	// printf("See you later!\n");
	exit(0);
}

int main(int argc, char **argv)
{
	printf("%s\n", argv[0]); // warning 때문에 잠시 넣었습니다. 나중에 argv 사용 시 지워주세요!
	t_game	game;
	t_map	map;
	t_mlx	mlx;

	game.map = &map;
	game.mlx = &mlx;
	if (argc != 2)
		err_exit("Need 2 arguments", NULL);
	/*
		인자 체크 후
		map_parsing 받아주세요 ~ 😘
	*/

	/*
	* draw와 move 합시닷 🥴
	*/
	start_cub3d(&game);
	return (0);
}
