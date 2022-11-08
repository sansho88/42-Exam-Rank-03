#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char *get_next_line_3_ligne(int fd)
{
	char *s = malloc(10000), *c = s;
	while(read(fd, c, 1) > 0 && *c++ != '\n');
	return c > s ? (*c = 0, s) : (free(s), NULL);
}

char	*get_next_line(int fd)
{
	char *str = malloc(10000);
	char *c = str;
	while (read(fd, c, 1) > 0 && *c++ != '\n');
	if (c > str)
	{
		*c = 0;
		return (str);
	}
	else
	{
		free(str);
		return (NULL);
	}
}
