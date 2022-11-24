#include "../gnl/get_next_line.h" 
#include "cub3d.h"

static int	set_texture(char **texture, char *value)
{
	*texture = ft_substr(value, 0, ft_strlen(value) - 1);
	if (!(*texture))
		return (FAIL);
	return (SUCCESS);
}

static int	set_cub(char *key, char *value, unsigned int len, t_cub *c)
{
	if (ft_strncmp(key, "NO", len) == 0 && c->no == NULL)
		return (set_texture(&c->no, value));
	if (ft_strncmp(key, "SO", len) == 0 && c->so == NULL)
		return (set_texture(&c->so, value));
	if (ft_strncmp(key, "WE", len) == 0 && c->we == NULL)
		return (set_texture(&c->we, value));
	if (ft_strncmp(key, "EA", len) == 0 && c->ea == NULL)
		return (set_texture(&c->ea, value));
	if (ft_strncmp(key, "F", len) == 0 && c->fl == UNDEF)
		return (set_color(&c->fl, value));
	if (ft_strncmp(key, "C", len) == 0 && c->ce == UNDEF)
		return (set_color(&c->ce, value));
	return (FAIL);
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
		return (FAIL);
	if (!is_empty_line(line))
	{
		split = ft_split(line, ' ');
		if (!split)
			err = FAIL;
		if (!err)
			err = set_cub(split[0], split[1], ft_strlen(split[0]), c);
	}
	free(line);
	free_double_char(split);
	// 성공, 실패 여부에 상관 없이 모든 line, split은 여기서 free
	// set_texture의 substr에서 할당한 메모리는 이후 err_exit에서 free
	return (err);
}

int	parse_cub(int fd, t_cub *c)
{
	init_cub(c);
	while (c->no == NULL || c->so == NULL || c->we == NULL \
		|| c->ea == NULL || c->fl == UNDEF || c->ce == UNDEF)
	{
		if (check_cub(fd, c))
			return (FAIL);
	}
	return (SUCCESS);
}
