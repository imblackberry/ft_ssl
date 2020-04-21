#include "errors.h"

void	error_usage_msg(char *invalid_cmd)
{
	unsigned i;

	
	ERROR("ft_ssl: Error: \'");
	ERROR(invalid_cmd);
	ERROR("\' is an invalid command.\n");
	ERROR("\nStandard commands:\n");
	ERROR("\nMessage Digest commands:\n");
	i = 0;
	while (i < N_HASH)
	{
		ERROR(g_hash_name[i++]);
		ERROR("\n");
	}
	ERROR("\nCipher commands:\n");
}

void	error_cmd(t_hash_type hash_type, char *msg)
{
	ERROR(g_hash_name[hash_type]);
	ERROR(": ");
	ERROR(msg);
	ERROR("\n");
}