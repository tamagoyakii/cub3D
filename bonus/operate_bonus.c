#include "cub3d_bonus.h"
#include <math.h>

static void	rotate(t_vec *v, int opt, double speed)
{
	double	dir_x;
	double	pln_x;
	double	rot;

	dir_x = v->dir_x;
	pln_x = v->pln_x;
	rot = speed / 20 * opt;
	v->dir_x = dir_x * cos(rot) - v->dir_y * sin(rot);
	v->dir_y = dir_x * sin(rot) + v->dir_y * cos(rot);
	v->pln_x = pln_x * cos(rot) - v->pln_y * sin(rot);
	v->pln_y = pln_x * sin(rot) + v->pln_y * cos(rot);
}

static void	move_ws(t_vec *v, t_cub *c, double opt)
{
	double	des_x;
	double	des_y;

	des_x = v->pos_x + v->dir_x * (double)MOVE_SPEED / 10 * opt;
	des_y = v->pos_y + v->dir_y * (double)MOVE_SPEED / 10 * opt;
	if (c->map[(int)v->pos_y][(int)des_x] == '0')
		v->pos_x = des_x;
	if (c->map[(int)des_y][(int)v->pos_x] == '0')
		v->pos_y = des_y;
}

static void	move_ad(t_vec *v, t_cub *c, double opt)
{
	double	des_x;
	double	des_y;

	des_x = v->pos_x + v->pln_x * (double)MOVE_SPEED / 10 * opt;
	des_y = v->pos_y + v->pln_y * (double)MOVE_SPEED / 10 * opt;
	if (c->map[(int)v->pos_y][(int)des_x] == '0')
		v->pos_x = des_x;
	if (c->map[(int)des_y][(int)v->pos_x] == '0')
		v->pos_y = des_y;
}

int	key_press(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		move_ws(g->vec, g->cub, 1);
	if (keycode == KEY_S)
		move_ws(g->vec, g->cub, -1);
	if (keycode == KEY_A)
		move_ad(g->vec, g->cub, -1);
	if (keycode == KEY_D)
		move_ad(g->vec, g->cub, 1);
	if (keycode == KEY_R)
		rotate(g->vec, 1, K_ROT_SPEED);
	if (keycode == KEY_L)
		rotate(g->vec, -1, K_ROT_SPEED);
	if (keycode == KEY_ESC)
		close_win(g->mlx);
	return (0);
}

int	mouse_rotate(int x, int y, t_game *g)
{
	if (WIN_X / 2 < x)
		rotate(g->vec, 1, M_ROT_SPEED);
	if (WIN_X / 2 > x)
		rotate(g->vec, -1, M_ROT_SPEED);
	(void)y;
	mlx_mouse_hide();
	mlx_mouse_move(g->mlx->mlx_win, WIN_X / 2, WIN_Y / 2);
	return (0);
}
