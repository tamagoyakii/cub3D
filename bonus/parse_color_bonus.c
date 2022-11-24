#include "cub3d_bonus.h"

static int	calc_color(int color, int rgb)
{
	if (rgb < 0 || rgb > 255)
		return (-1);
	color <<= 8;
	return (color |= rgb);
}

void	set_color(int *texture, char *value)
{
	char	**split;
	int		color;
	int		i;

	i = -1;
	color = 0;
	split = ft_split(value, ',');
	if (!split)
		err_exit(0);
	while (split[++i])
	{
		color = calc_color(color, ft_atoi(split[i]));
		if (color < 0)
			break ;
	}
	free_double_char(split);
	if (color < 0 || i > 3)
		err_exit("Invalid color.");
	*texture = color;
}
