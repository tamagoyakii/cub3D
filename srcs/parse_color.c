#include "cub3d.h"

static int	calc_color(int color, int rgb)
{
	if (rgb < 0 || rgb > 255)
		return (-1);
	color <<= 8;
	return (color |= rgb);
}

static int get_color(char *value)
{
	char	**split;
	int		color;
	int		i;

	i = -1;
	color = 0;
	split = ft_split(value, ',');
	if (!split)
		return (-1);
	while (split[++i])
	{
		color = calc_color(color, ft_atoi(split[i]));
		if (color < 0)
			break ;
	}
	free_strs(split);
	if (color < 0 || i > 3)
		return (-1); 
	return (color);
}

int	set_color(int *content, char *value)
{
	(*content) = get_color(value);
	if ((*content) < 0)
		return (FAIL);
	return (SUCCESS);
}