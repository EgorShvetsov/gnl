#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int fd;
	char *line;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
		printf("%s", line);

	//if (result == -1)
	//printf("Оно поломалось!!!\n");else

	return (0);
}