#include "cub3d.h"

static int	calc_color(int color, int rgb)
{
	if (rgb < 0 || rgb > 255)
		return (-1);
	color <<= 8;
	return (color |= rgb);
}

int parse_color(char *value)
{
	char	**split;
	int		color;
	int		i;

	i = -1;
	color = 0;
	split = ft_split(value, ',');
	if (!split)
	{
		// free(line); // 프리할 걸 다 받아올 수 없어서
		err_exit("Malloc failed.", NULL);
		// return (-1); // 이렇게 아래와 같이 할까 생각중
	}
	while (split[++i])
	{
		color = calc_color(color, ft_atoi(split[i]));
		if (color < 0)
			break ;
	}
	if (color < 0 || i > 3)
	{
		free_strs(split);
		err_exit("Invalid rgb color.", NULL);
		// return (-1); 
		// 이거 던져서 set_cub_content에서 받아서 0 리턴해서 set_cub에서 한꺼번에 처리할 방법 생각중
	}
	return (color);
}