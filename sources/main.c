#include "ft_ssl.h"

int	main(int argc, char **argv)
{
	t_command command;

	if (argc < 2)
		return 0; //todo: error
	if (init_command(argv, &command))
		return -1; //todo: error
	ft_printf("{%d}", command.flags);


	(void)argc;
	return 0;
}