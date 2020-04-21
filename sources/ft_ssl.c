#include "ft_ssl.h"

bool ft_ssl(char **parameters)
{
	t_command	cmd;

	if (!parameters || !parameters[0])
		return false;
	if (!set_hash_type(parameters[0], &(cmd.hash_type)))
	{
		error_usage_msg(parameters[0]);
		return false;
	}
	if (!launch(&cmd, find_hash_function(cmd.hash_type), parameters))
		return false;
	return 0;
}

bool	launch(t_command *cmd, t_hash_f hash_function, char **parameters)
{
	size_t	i;
	char	*parameter;
	bool	areFilesStarted;

	i = 1;
	areFilesStarted = false;
	while ((parameter = parameters[i]))
	{
		if (!areFilesStarted) //todo optimize
		{
			if (parameter[0] == '-')
				set_flag(parameter + 1, &cmd->flags);
			else
				areFilesStarted = true;
		}
		if (set_input(parameters, &i, cmd, areFilesStarted))
		{
			hash_function(cmd);
			ft_strdel(&cmd->input);
			ft_putstr("DEL\n");
		}
		
		i++;
	}
	return true;
}

bool	set_flag(char *str, uint8_t *flags)
{
	if (!ft_strcmp("p", str))
		*flags |= READ_STDIN_PRINT_STDOUT;
	else if (!ft_strcmp("q", str))
	{
		*flags |= PRINT_ONLY_CHECKSUM;
		// ft_bitset(flags, 0, PRINT_REVERSELY);//check
	}
	else if (!ft_strcmp("r", str)) //&& !PRINT_ONLY_CHECKSUM ? test
		*flags |= PRINT_REVERSELY;
	else if (!ft_strcmp("s", str))
		*flags |= READ_NEXT_ARG_PRINT_STDOUT;
	else //todo: error
		ERROR_RET("error flag")
	return true;
}

bool	ft_ssl_stdin()
{
	char **parameters;
	bool ret;

	parameters = get_parameters_stdin();
	ret = ft_ssl(parameters); //todo set flag -p
	free(parameters[0]);
	free(parameters);
	return ret;
}