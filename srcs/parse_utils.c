#include "cub3d.h"

void	free_strs(char **strs)
{
	int	i;

	i = -1;
	if (!strs)
		return ;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

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
	// "     NO      ./imgs/" 이런 것도 처리해야 하는 건가... 고민이되네요.
	if (!ft_strncmp(line, "\n", 1) || is_only_wspace(line))
		return (1);
	else
		return (0);
}