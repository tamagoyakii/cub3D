#include "../gnl/get_next_line.h" 
#include "cub3d.h"

static void	check_map_closed(int y, char **map, t_cub *c)
{
	int	x;

	x = -1;
	while (++x < c->w)
	{
		if (map[y][x] == '0' && (\
			y == 0 || y == c->h - 1 || x == 0 || x == c->w - 1 \
			|| map[y - 1][x] == ' ' || map[y + 1][x] == ' ' \
			|| map[y][x - 1] == ' ' || map[y][x + 1] == ' '))
			err_exit("The player might run away!");
	}
}

static void	make_map_rectangle(char **line, int w)
{
	int		size;
	char	*fill;

	size = w - (int)ft_strlen(*line);
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
	free(full_line);
	if (!map)
		err_exit(0);
	while (++y < c->h)
		make_map_rectangle(&map[y], c->w);
	y = -1;
	while (++y < c->h)
		check_map_closed(y, map, c);
	c->map = map;
}

static int	check_element(char *line, int *is_p, t_game *g)
{
	int	x;

	x = -1;
	while (line[++x])
	{
		if (!(*is_p) && gnl_strchr("NSEW", line[x]))
		{
			init_vec(g->vec, line[x], x, g->cub->h);
			*is_p = 1;
			line[x] = '0';
			continue ;
		}
		if (!gnl_strchr("10 \n", line[x]))
			return (FAIL);
	}
	if (--x > g->cub->w)
		g->cub->w = x;
	g->cub->h++;
	return (SUCCESS);
}

void	parse_map(int fd, t_game *g)
{
	t_parse	p;

	ft_bzero(&p, sizeof(t_parse));
	skip_empty_line(fd, &p.line);
	while (p.line)
	{
		if (!is_empty_line(p.line))
		{
			if (p.is_e || check_element(p.line, &p.is_p, g))
				err_exit("Invalid map!");
			p.full_line = gnl_strjoin(p.full_line, p.line);
			if (!p.full_line)
				err_exit(0);
		}
		else
			p.is_e = 1;
		free(p.line);
		p.line = get_next_line(fd);
	}
	if (!p.is_p)
		err_exit("No player, no game!");
	set_map(p.full_line, g->cub);
}
