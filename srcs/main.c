#include "cub3d.h"

/** print err msg & exit(1) !! */
void print_err(const char *str)
{
	printf("Error\n%s\n", str);
	exit(1);
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
		print_err("Need 2 arguments");
	/*
		map_parsing 받아주세요 ~
	*/

	/*
	* mlx 돌기 ~
	*/
	return (0);
}
