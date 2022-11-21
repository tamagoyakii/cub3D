#include "cub3d.h"
#include <math.h>

void	rotate(t_vec *v, int opt)
{
	double	dir_x;
	double	pln_x;
	double	rot;

	dir_x = v->dir_x;
	pln_x = v->pln_x;
	rot = ROT_SPEED / 100 * opt;
	v->dir_x = dir_x * cos(rot) - v->dir_y * sin(rot);
	v->dir_y = dir_x * sin(rot) + v->dir_y * cos(rot);
	v->pln_x = pln_x * cos(rot) - v->pln_y * sin(rot);
	v->pln_y = pln_x * sin(rot) + v->pln_y * cos(rot);
}

void	move_ws(t_vec *v, t_cub *c, int opt)
{
	int	des_x;
	int	des_y;

	des_x = (int)(v->pos_x + v->dir_x * MOVE_SPEED / 100 * opt);
	des_y = (int)(v->pos_y + v->dir_y * MOVE_SPEED / 100 * opt);
	if (c->map[(int)v->pos_y][des_x] == 0)
		v->pos_x = des_x;
	if (c->map[des_y][(int)v->pos_x] == 0)
		v->pos_y = des_y;
}

void	move_ad(t_vec *v, t_cub *c, int opt)
{
	int	des_x;
	int	des_y;

	des_x = (int)(v->pos_x + v->pln_x * MOVE_SPEED / 100 * opt);
	des_y = (int)(v->pos_y + v->pln_y * MOVE_SPEED / 100 * opt);
	if (c->map[(int)v->pos_y][des_x] == 0)
		v->pos_x = des_x;
	if (c->map[des_y][(int)v->pos_x] == 0)
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
		rotate(g->vec, -1);
	if (keycode == KEY_L)
		rotate(g->vec, 1);
	if (keycode == KEY_ESC)
		close_win(g->mlx);
	// 맵 프린트
	// 탈출구에 도달했을 경우 게임 종료하는 코드 추가
	return (0);
}