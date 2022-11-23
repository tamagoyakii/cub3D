#include "cub3d.h"

static int	is_only_wspace(char *str)
{
	while (*str)
	{
		if (!(*str == ' ' || (*str >= 9 && *str <= 13)))
			return(0);
		str++;
	}
	return (1);
}

int	is_empty_line(char *line)
{
	if (!ft_strncmp(line, "\n", 1) || is_only_wspace(line))
		return (1);
	else
		return (0);
}
