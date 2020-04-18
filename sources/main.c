#include "ft_ssl.h"

int	main(int argc, char **argv)
{		
	if (argc <= 1)
		ft_ssl_stdin();
	else
		ft_ssl(argv + 1);
	system("leaks ft_ssl");
	return (0);
}
