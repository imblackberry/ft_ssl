#include "ft_ssl.h"

int	main(int argc, char **argv)
{
	char **parameters;
	char *line = NULL;

	if (argc < 2) {
		ERROR(ERR_USAGE)
		get_next_line(0, &line);
		parameters = ft_strsplit(line, ' '); //split string
	}
	else
		parameters = argv;
	return ft_ssl(parameters);
}
