#include "ft_ssl.h"

const char	*g_hash_name[N_HASH] = { "md5", "sha256"};

t_hash_f	find_hash_function(t_hash_type type)
{
	t_hash_f	hash_functions[N_HASH];

	hash_functions[MD5] = &ft_ssl_md5;
	hash_functions[SHA256] = &ft_ssl_sha256;
	return hash_functions[type];
}

bool	set_hash_type(char *name, t_hash_type *type)
{
	size_t i;

	i = 0;
	while (i < N_HASH && ft_strcmp(g_hash_name[i], name))
		i++;
	*type = i;
	return (i < N_HASH);
}

void	call_and_free(t_hash_f hash_function, t_command *cmd)
{
	hash_function(cmd);
	ft_strdel(&cmd->input);
}