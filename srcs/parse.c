#include "cub3d.h"
#include <fcntl.h>

static int	check_file(char *av)
{
	int	fd;
	int len;

	len = ft_strlen(av);
	if (len < 4 || av[len - 4] != '.' || av[len - 3] != 'c'\
		|| av[len - 2] != 'u' || av[len - 1] != 'b')
		err_exit("Invalid file name.", NULL);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		err_exit("File open failed.", NULL);
	return (fd);
}

static void	init_cub(t_cub *c)
{
	c->no = NULL;
	c->so = NULL;
	c->we = NULL;
	c->ea = NULL;
	c->fl = -1;
	c->ce = -1;
	c->h = -1;
	c->w = -1;
}

static void	parse_map(t_cub *c)
{
	(void ) c; //warning으로 잠시 추가 추후 삭제 바랍니다 🙌
	//  c->w, c->h도 저장해야 함
	// 이차원 배열로 저장하는 함수
}

void	parse(char *av, t_cub *c)
{
	int				fd;

	fd = check_file(av);
	init_cub(c);
	parse_cub(fd, c);
	parse_map(c);
}
