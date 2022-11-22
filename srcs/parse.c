#include "../gnl/get_next_line.h" 
#include "cub3d.h"
#include <fcntl.h>

static int	check_file(char *av)
{
	int	fd;
	int len;

	len = ft_strlen(av);
	if (len < 4 || av[len - 4] != '.' || av[len - 3] != 'c'\
		|| av[len - 2] != 'u' || av[len - 1] != 'b')
		p_err_exit("Invalid file name.", NULL);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		p_err_exit("File open failed.", NULL);
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
	c->h = 0;
	c->w = 0;
}

void	parse(char *av, t_cub *c)
{
	int	fd;

	fd = check_file(av);
	init_cub(c);
	parse_cub(fd, c);
	parse_map(fd, c);
}
