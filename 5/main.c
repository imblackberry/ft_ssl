#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"


#include <stdio.h> // DELETE!!!!!!!!!!!!!!!!!!!!!!!!!!!
// typedef struct s_list
// {
// 	int fd;
// 	char *content;
// 	t_list *next;
// }				t_list;
int ft_line_size(char *str);
int get_next_line(const int fd, char **line);
int main()
{
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open("pelmen", O_RDONLY);
	while(i < 10)
	{
		printf("%d\n", get_next_line(fd, &line));
		printf("|%s|\n", line);
		i++;
	}
	close(fd);
	return (0);
}