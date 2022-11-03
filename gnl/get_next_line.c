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
	char *c = str;									// c pointe sur str pour ecrire directement dans str
	while (read(fd, c, 1) > 0 && *c++ != '\n');		// read de 1 caractere dans c soit 1er element de str si read != 0 pb sa stop && si *c == \n on stop et *c++ pour que le prochain buffer du read soit sur la prochaine address de str
	if (c > str)									// si c > str cela veut dire que l'on a ecrit donc des choses a renvoyer
	{
		*c = 0;										// cleanup avant return
		return (str);
	}
	else
	{
		free(str);									// cleanup avant return
		return (NULL);
	}
}
