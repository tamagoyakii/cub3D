#include "../gnl/get_next_line.h" 
#include "cub3d.h"

static void	check_map_closed(int y, char **map, t_cub *c)
{
	int	x;

	x = -1;
	while (++x < c->w)
	{
		if (map[y][x] == '0' && (
			y == 0 || y == c->h - 1 || x == 0 || x == c->w - 1\
			|| map[y - 1][x] == ' ' || map[y + 1][x] == ' '\
			|| map[y][x - 1] == ' ' || map[y][x + 1] == ' '))
			err_exit("The player might run away!");
	}
}

static void	make_map_rectangle(char **line, int w)
{
	int		size;
	char	*fill;
	
	size = w - (int)ft_strlen(*line) - 1;
	if (size > 0)
	{
		fill = ft_calloc(sizeof(char), size + 1);
		if (!fill)
			err_exit(0);
		ft_memset(fill, ' ', size);
		*line = gnl_strjoin(*line, fill);
		if (!*line)
			err_exit(0);
		free(fill);
	}
}

static void	set_map(char *full_line, t_cub *c)
{
	int		y;
	char	**map;

	y = -1;
	map = ft_split(full_line, '\n');
	if (!map)
		err_exit(0);
	while (++y < c->h)
		make_map_rectangle(&map[y], c->w);
	y = -1;
	while (++y < c->h)
		check_map_closed(y, map, c);
	c->map = map;
}

static int	check_element(char *line, int *flag, t_game *g)
{
	int	x;

	x = -1;
	while(line[++x])
	{
		if (!(*flag) && gnl_strchr("NSEW", line[x]))
		{
			init_vec(g->vec, line[x], x, g->cub->h);
			*flag = 1;
			line[x] = '0';
			continue ;
		}
		if (!gnl_strchr("10 \n", line[x]))
			return (FAIL);
	}
	if (x > g->cub->w)
		g->cub->w = x;
	return (SUCCESS);
}

#include <stdio.h>

void	parse_map(int fd, t_game *g)
{
	int		is_p;
	char	*line;
	char	*full_line;

	is_p = 0;
	line = NULL;
	full_line = NULL;
	skip_empty_line(fd, &line);
	while (line)
	{
		if (is_empty_line(line) || check_element(line, &is_p, g))
			err_exit("Invalid map!");
		full_line = gnl_strjoin(full_line, line);
		if (!full_line)
			err_exit(0);
		g->cub->h++;
		free(line);
		line = get_next_line(fd);
	}
	if (!is_p)
		err_exit("No player, no game!");
	set_map(full_line, g->cub);
}