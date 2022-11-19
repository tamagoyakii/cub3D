# include "cub3d.h"

void	turn()
{

}

void	move(t_game *g)
{
	(void)g;
}

int	key_press(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		move(g);
	if (keycode == KEY_A)
		move(g);
	if (keycode == KEY_S)
		move(g);
	if (keycode == KEY_D)
		move(g);
	if (keycode == KEY_ESC)
		close_win(g->mlx);
	return (0);
}