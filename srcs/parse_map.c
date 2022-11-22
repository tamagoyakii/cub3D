#include "../gnl/get_next_line.h" 
#include "cub3d.h"

static int	check_line_content(char *line, int *flag, t_cub *c)
{
	int	w;

	w = -1;
	while(line[++w])
	{
		if (!(*flag) && gnl_strchr("NSEW", line[w]))
		{
			(*flag) = 1;
			// later: 보는 방향을 내가 저장해야하는데 어디가다 저장해야할 지 고민중
			continue ;
		}
		if (!gnl_strchr("10 \n", line[w]))
			return (0);
	}
	if (w > c->w)
		c->w = w;
	return (1);
}

static void	fill_map(char **map, t_cub *c)
{
	int		i;
	int		size;
	char	*fill;
	
	i = -1;
	size = 0;
	while (++i < c->h)
	{
		size = (c->w) - (int)ft_strlen(map[i]) - 1;
		if (size > 0)
		{
			fill = ft_calloc(sizeof(char), size + 1);
			if (!fill)
			{
				free_strs(map);
				p_err_exit("Malloc failed.", NULL);
			}
			ft_memset(fill, ' ', size);
			map[i] = ft_strjoin(map[i], fill);
			if (!map[i])
			{
				free_strs(map);
				p_err_exit("Malloc failed.", NULL);
			}
		}
		
	}
}

static void	check_map_closed(int y, int x, char **map, t_cub *c)
{
	if (y == 0 || y == c->h - 1 || x == 0 || x == c->w - 1\
		|| map[y - 1][x] == ' ' || map[y + 1][x] == ' '\
		|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
	{
		free_strs(map);
		p_err_exit("Map must be surrounded by walls", NULL);
	}
}

static void	set_map(char *full_line, t_cub *c)
{
	int		y;
	int		x;
	char	**map;

	y = -1;
	x = -1;
	map = ft_split(full_line, '\n');
	if (!map)
		p_err_exit("Malloc failed.", &full_line);
	fill_map(map, c);
	while (++y < c->h)
	{
		x = -1;
		while (++x < c->w)
		{
			if (map[y][x] == '0')
				check_map_closed(y, x, map, c);
		}
	}
	c->map = map;
}

int	parse_map(int fd, t_cub *c)
{
	char	*line;
	char	*full_line;
	int		pos_flag;

	pos_flag = 0;
	full_line = NULL;
	line = get_next_line(fd);
	while (line && is_empty_line(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		if (is_empty_line(line) || !check_line_content(line, &pos_flag, c))
			p_err_exit("Invalid Map content.", &line);
		full_line = gnl_strjoin(full_line, line);
		if (!full_line)
			p_err_exit("Malloc failed.", &line);
		free(line);
		c->h++;
		line = get_next_line(fd);
	}
	if (!pos_flag)
		p_err_exit("No player.", &full_line);
	set_map(full_line, c);
	return (SUCCESS);
}