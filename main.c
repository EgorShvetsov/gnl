#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int fd;
	int b;
	char *line;

	fd = open("file_to_read", O_RDONLY);
	b = get_next_line(fd, &line);

	printf("%s\n", line);
	return (0);
}