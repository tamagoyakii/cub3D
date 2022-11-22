#include "cub3d.h"
#include <stdio.h>

void	p_err_exit(const char *str, char **f_str)
{
	 // 프리해야해서 파싱용 에러 
	printf("Error\n%s\n", str);
	if (*f_str)
		free(*f_str);
	exit(1);
}

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
	if (!ft_strncmp(line, "\n", 1) || is_only_wspace(line))
		return (1);
	else
		return (0);
}
