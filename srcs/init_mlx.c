#include "cub3d.h"
#include <stdlib.h>

static void	init_tmp_map(t_game *g)
{
	int	i;

	i = -1;
	g->mlx->tmp = malloc(sizeof(int *) * WIN_Y);
	if (g->mlx->tmp == NULL)
		; //NULL 처리하기
	while (++i < WIN_Y)
	{
		g->mlx->tmp[i] = malloc(sizeof(int) * WIN_X);
		if (g->mlx->tmp[i] == NULL)
			; // NULL 처리
	}
}

void	init_mlx_strt(t_game *g)
{
	init_tmp_map(g);
	//textuer init();
	//image init();
}
