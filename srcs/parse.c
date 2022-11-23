#include "../gnl/get_next_line.h" 
#include "cub3d.h"
#include <fcntl.h>

static int	check_file(char *av, int *fd)
{
	int	len;

	len = ft_strlen(av);
	if (len < 4 || av[len - 4] != '.' || av[len - 3] != 'c'\
		|| av[len - 2] != 'u' || av[len - 1] != 'b')
		return (FAIL);
	*fd = open(av, O_RDONLY);
	if (*fd < 0)
		return (FAIL);
	return (SUCCESS);
}

int	parse(char *av, t_cub *c)
{
	int		fd;
	char	player;

	player = 0;
	if (check_file(av, &fd))
		return (FAIL);
	if (parse_cub(fd, c))
		return (FAIL);
	if (parse_map(fd, c, &player))
		return (FAIL);
	return (SUCCESS);
}
