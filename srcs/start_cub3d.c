#include "cub3d.h"

void	start_cub3d(t_game *g)
{
	g->mlx->mlx_ptr = mlx_init();
	//mlx_init() 실패시 처리 필요;
	g->mlx->mlx_win = mlx_new_window(g->mlx->mlx_ptr, 600, 600, "cub3D");
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

	mlx_loop(g->mlx->mlx_ptr);
}
