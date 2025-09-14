#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line); // print the line as is (including newline)
		free(line);
	}
	close(fd);
	return (0);
}