#include "../gnl/get_next_line.h" 
#include "cub3d_bonus.h"

static void	set_texture(char **texture, char *value)
{
	*texture = ft_substr(value, 0, ft_strlen(value) - 1);
	if (!(*texture))
		err_exit(0);
}

static void	set_cub(char *key, char *value, t_cub *c)
{
	if (ft_strcmp(key, "NO") == 0 && c->no == NULL)
		set_texture(&c->no, value);
	else if (ft_strcmp(key, "SO") == 0 && c->so == NULL)
		set_texture(&c->so, value);
	else if (ft_strcmp(key, "WE") == 0 && c->we == NULL)
		set_texture(&c->we, value);
	else if (ft_strcmp(key, "EA") == 0 && c->ea == NULL)
		set_texture(&c->ea, value);
	else if (ft_strcmp(key, "F") == 0 && c->fl == UNDEF)
		set_color(&c->fl, value);
	else if (ft_strcmp(key, "C") == 0 && c->ce == UNDEF)
		set_color(&c->ce, value);
	else
		err_exit("Invalid texture.");
}

static int	check_cub(int fd, t_cub *c)
{
	char	*line;
	char	**split;
	int		err;

	err = SUCCESS;
	split = NULL;
	line = get_next_line(fd);
	if (!line)
		err_exit(0);
	if (!is_empty_line(line))
	{
		split = ft_split(line, ' ');
		if (!split)
			err_exit(0);
		set_cub(split[0], split[1], c);
	}
	free(line);
	free_double_char(split);
	return (err);
}

void	parse_cub(int fd, t_cub *c)
{
	init_cub(c);
	while (c->no == NULL || c->so == NULL || c->we == NULL \
		|| c->ea == NULL || c->fl == UNDEF || c->ce == UNDEF)
		check_cub(fd, c);
}
