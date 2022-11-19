#include "cub3d.h"
#include <fcntl.h>

int	check_file(char *av)
{
	int	fd;
	int len;

	len = ft_strlen(av);
	if (len < 4 || av[len - 4] != '.' || av[len - 3] != 'c'\
		|| av[len - 2] != 'u' || av[len - 1] != 'b')
		err_exit("Invalid file name!", NULL);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		err_exit("File open failed.", NULL);
	return (fd);
}

void	init_map(t_cub *c)
{
	// map 구조체 초기화하는 함수
}

void	check_map(int fd)
{
	// 파일 내용이 유효한지 확인하는 함수
}

void	parse_map(t_cub *c)
{
	// 이차원 배열로 저장하는 함수
}

void	parse(char *av, t_cub *c)
{
	int		fd;

	fd = check_file(av);
	init_map(c);
	check_map(fd);
	parse_map(c);
}