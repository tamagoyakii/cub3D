#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef enum e_return {
	SUCCESS	= 0,
	FAIL	= 1,
	UNDEF	= -1,
}	t_return;

typedef enum e_error {
	E_INIT	= 0x01,
	E_PARSE	= 0x02,
}	t_error;
typedef enum e_keycode {
	KEY_W	= 13,
	KEY_A	= 0,
	KEY_S	= 1,
	KEY_D	= 2,
	KEY_R	= 124,
	KEY_L	= 123,
	KEY_ESC = 53,
}	t_keycode;

typedef enum e_x_event {
	ON_KEYDOWN = 2,
	ON_DESTROY = 17,
}	t_x_event;

typedef enum e_size {
	PIX = 16,
	WIN_X = 680,
	WIN_Y = 480
}	t_size;

typedef enum e_speed {
	MOVE_SPEED = 5,
	ROT_SPEED = 3
}	t_speed;

typedef struct s_ray {
	double	cam_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side; //NEWS ?
	double	wall_dist;
}	t_ray;

typedef struct s_wall {
	int	side;
	int	tex_x;
	int line_h;
	int	draw_start;
	int	draw_end;
}	t_wall;

typedef struct s_img
{
	void	*img_ptr;
	int		bpp;
	int		size_l;
	int		endian;
	unsigned int		*data;
}			t_img;

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*mlx_win;
	int		**tmp;
	int		*texture[4];
	t_img	img;
}			t_mlx;

typedef struct s_cub {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		fl;
	int		ce;
	char	**map;
	int		h;
	int		w;
}	t_cub;

typedef struct s_vec {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	pln_x;
	double	pln_y;
}	t_vec;

typedef struct s_game {
	struct s_cub	*cub;
	struct s_mlx	*mlx;
	struct s_vec	*vec;
}	t_game;

/**********
* main.c  *
**********/
void	err_exit(const char *str, t_game *g, int err);
int		close_win(t_mlx *mlx);

/*********
* init.c *
*********/
void	init_cub(t_cub *c);
void	init_vec(t_vec *v, char p);
int		init_mlx(t_game *g);

/*********
* free.c *
*********/
void	free_double_char(char **ptr);
void	free_double_int(int **ptr);
void	free_cub(t_cub *cub);

/*********
* move.c *
*********/
int		key_press(int keycode, t_game *g);

/*********
* draw.c *
*********/
int		draw_game(t_game *g);

/**********
* parse.c *
**********/
int		parse(char *av, t_cub *c, t_vec *v);
int		parse_cub(int fd, t_cub *c);
int		parse_map(int fd, t_cub *c, char *p);
int		set_color(int *content, char *value);

int		is_empty_line(char *line);

/***************
* raycasting.c *
***************/
void	calc_ray(t_vec *v, t_ray *r, int x);
void	dda(t_ray *r, t_cub *cub);

/***************
* draw_util.c *
***************/
void	my_xpm_to_img(t_mlx *m, int dir, char *wall);
void	draw_floor_ceil(t_game *g);

#endif
