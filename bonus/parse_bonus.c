#include "../gnl/get_next_line.h" 
#include "cub3d_bonus.h"
#include <fcntl.h>
#include <unistd.h>

static void	check_file(char *av, int *fd)
{
	int	len;

	len = ft_strlen(av);
	if (len < 4 || av[len - 4] != '.' || av[len - 3] != 'c'\
		|| av[len - 2] != 'u' || av[len - 1] != 'b')
		err_exit("Invalid map extension.");
	*fd = open(av, O_RDONLY);
	if (*fd < 0)
		err_exit("Open map failed.");
}

static void	check_minimap(t_game *g)
{
	if ((g->cub->h * 5 > WIN_Y) || (g->cub->w * 5 > WIN_X))
		err_exit("Map too big.");
}

void	parse(char *av, t_game *g)
{
	int		fd;

	check_file(av, &fd);
	parse_cub(fd, g->cub);
	parse_map(fd, g);
	close(fd);
	check_minimap(g);
}
