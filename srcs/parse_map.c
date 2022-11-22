#include "../gnl/get_next_line.h" 
#include "cub3d.h"

static int	check_line_content(char *line, int *flag)
{
	int	i; // later: c->w구할 때 넣어주면 될 듯!

	i = -1;
	while(line[++i])
	{
		if (!(*flag) && gnl_strchr("NSEW", line[i]))
		{
			(*flag) = 1;
			// later: 보는 방향을 내가 저장해야하는데 어디가다 저장해야할 지 고민중
			continue ;
		}
		if (!gnl_strchr("10 \n", line[i]))
			return (0);
	}
	return (1);
}

static void	check_map_closed(char el, t_cub *c)
{
	(void )el;
	(void )c;
	// 벽으로 막혀 있는지, 확인하는 함수
}

static void	set_map(char *full_line, t_cub *c)
{
	int		y;
	int		x;
	char	**map;

	y = -1;
	x = -1;
	map = NULL;
	map = ft_split(full_line, '\n');
	if (!map)
		p_err_exit("Malloc failed.", &full_line);
	while (++y < c->h)
	{
		while (++x < (int)ft_strlen(map[y]))
		{
			check_map_closed(map[y][x], c);
		}
	}
	c->map = map;
}

void	parse_map(int fd, t_cub *c)
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
		if (is_empty_line(line) || !check_line_content(line, &pos_flag))
			p_err_exit("Invalid Map content.", &line);
		full_line = gnl_strjoin(full_line, line);
		if (!full_line)
			p_err_exit("Malloc failed.", &line);
		free(line);
		c->h++;
		line = get_next_line(fd);
	}
	set_map(full_line, c);
}