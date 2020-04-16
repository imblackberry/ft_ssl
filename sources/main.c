#include "ft_ssl.h"

int	main(int argc, char **argv)
{
	(void)argc;
	if (argc < 2)
		ERROR_RET(ERR_USAGE)
	return ft_ssl(argc, argv);
}
