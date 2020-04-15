#include "ft_ssl.h"

const char	*g_hash_name[N_HASH] = { "md5", "sha256"};

bool ft_ssl(char **argv)
{
	t_command	cmd;
	t_hash_f	hash_function;

	if (!argv)
		return false;
	if (set_hash_type(argv[1], &(cmd.hash_type)) == false)
	{
		error_usage_msg(argv[1]);
		return false;
	}
	hash_function = find_hash_function(cmd.hash_type);
	if (launch(&cmd, hash_function, argv) == false)
		return false;
	return 0;
}

bool	launch(t_command *cmd, t_hash_f hash_function, char **argv)
{
	size_t	i;
	char	*arg;

	i = 2;
	while ((arg = argv[i]))
	{
		if (arg++[0] == '-')
			set_flag(argv[i], &cmd->flags);
		// set_input() check here if file/stdin/str or nothing
		hash_function(cmd);
		i++;
	}
	return true;
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

bool	set_flag(char *str, uint8_t *flags)
{
	if (!ft_strcmp("p", str))
		*flags |= READ_STDIN_PRINT_STDOUT;
	else if (!ft_strcmp("q", str))
	{
		*flags |= PRINT_ONLY_CHECKSUM;
		ft_bitset(flags, 0, PRINT_REVERSELY);//check
	}
	else if (!ft_strcmp("r", str)) //&& !PRINT_ONLY_CHECKSUM ? test
		*flags |= PRINT_REVERSELY;
	else if (!ft_strcmp("s", str))
		*flags |= READ_NEXT_ARG_PRINT_STDOUT;
	else //todo: error
		ERROR_RET("error flag")
	return true;
}

t_hash_f	find_hash_function(t_hash_type type)
{
	t_hash_f	hash_functions[N_HASH];

	hash_functions[MD5] = &ft_ssl_md5;
	hash_functions[SHA256] = &ft_ssl_sha256;
	return hash_functions[type];
}
