#include "ft_ssl.h"

int ft_ssl(char **argv)
{
	t_command command;

	if (!argv)
		return -1;
	if (init_command(argv, &command))
		return -1;
	//while
	//get_flags
	//input
	command.hash.function(&command);

	//only files (using flags)

	return 0;
}

int	init_command(char **argv, t_command* cmd)
{
	t_hash	hash;

	hash = hash_by_name(argv[1]);
	if (hash.name)
		cmd->hash = hash;
	else
	{
		ERROR_RET("error") //todo
	}
	return 0;
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

t_hash	hash_by_name(char* cmd_name)
{
	size_t	i;
	t_hash hash_arr[2] = { //todo: N = size
 		{ "md5", &ft_ssl_md5 }, //todo: includes, copy
	// { "ssh256", &ft_ssl_ssh256 };
		{ NULL, NULL }
	};
	i = 0;
	while(hash_arr[i].name)
	{
		if (!ft_strcmp(cmd_name, hash_arr[i].name))
			return hash_arr[i];
		i++;
	}
	return hash_arr[i];
}
