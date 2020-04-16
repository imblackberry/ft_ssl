#include "errors.h"
#include "hash_structs.h"

void	error_usage_msg(char *invalid_cmd)
{
	unsigned i;

	ft_printf("ft_ssl: Error: \'%s\' is an invalid command.\n", invalid_cmd);
	ft_printf("\nStandard commands:\n");
	ft_printf("\nMessage Digest commands:\n");
	i = 0;
	while (i < N_HASH)
		ft_printf("%s\n", g_hash_name[i++]);
	ft_printf("\nCipher commands:\n");
}