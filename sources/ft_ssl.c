#include "ft_ssl.h"

static const char	*g_hash_name[N_HASH] = { "md5", "sha256"};

bool ft_ssl(char **argv)
{
	t_command	cmd;
	t_hash_f	hash_function;

	if (!argv)
		return false;
	if (set_hash_type(argv[1], &(cmd.hash_type)) == false)
		ERROR_RET("error") //todo
	hash_function = find_hash_function(cmd.hash_type);
	if (launch(&cmd, hash_function, argv) == false)
		return false;
	// while ()
	// {

	// 	hash_function(&cmd);
	// }
	//get_flags
	//input

	//only files (using flags)

	return 0;
}

bool	launch(t_command *cmd, t_hash_f hash_function, char **argv)
{


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

short	get_flags(char **argv)
{
	char	*str;
	short	flags;
	int		i;

	flags = 0;
	i = 2;
	while ((str = argv[i++]))
	{
		if (str++[0] == '-')
		{
			if (!ft_strcmp("p", str))
				flags |= READ_STDIN_PRINT_STDOUT;
			else if (!ft_strcmp("q", str))
				flags |= PRINT_ONLY_CHECKSUM;
			else if (!ft_strcmp("r", str))
				flags |= PRINT_REVERSELY;
			else if (!ft_strcmp("s", str))
				flags |= READ_NEXT_ARG_PRINT_STDOUT;
			else //todo: error
				return flags;
		}
		else
			//todo: error
			return flags;
	}
	return flags;
}

t_hash_f	find_hash_function(t_hash_type type)
{
	t_hash_f	hash_functions[N_HASH];

	hash_functions[MD5] = &ft_ssl_md5;
	hash_functions[SHA256] = &ft_ssl_sha256;
	return hash_functions[type];
}
