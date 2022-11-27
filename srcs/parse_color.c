#include "cub3d.h"

static int	calc_color(int color, int rgb)
{
	if (rgb < 0 || rgb > 255)
		return (-1);
	color <<= 8;
	return (color |= rgb);
}

static int	check_isdigit(char *str)
{
	int	i;
	
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (FAIL);
	}
	return (SUCCESS);
}

void	set_color(int *texture, char *value)
{
	char	**split;
	int		color;
	int		i;

	i = -1;
	color = 0;
	if (value[ft_strlen(value) - 1] == '\n')
		value[ft_strlen(value) - 1] = '\0';
	split = ft_split(value, ',');
	if (!split)
		err_exit(0);
	while (split[++i])
	{
		if (i < 3 && check_isdigit(split[i]))
			break ;
		color = calc_color(color, ft_atoi(split[i]));
		if (color < 0)
			break ;
	}
	free_double_char(split);
	if (color < 0 || i != 3)
		err_exit("Invalid color.");
	*texture = color;
}
