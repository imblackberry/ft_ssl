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
	launch(&cmd, find_hash_function(cmd.hash_type), ++parameters);
	return true;
}

void	launch(t_command *cmd, t_hash_f hash_function, char **parameters)
{
	size_t	i;
	bool	areFilesStarted;

	i = 0;
	areFilesStarted = false;
	while (true) //todo test!
	{
		if (!areFilesStarted && !set_flag(parameters[i], &cmd->flags))
			areFilesStarted = true;
		if (set_input(parameters, &i, cmd, areFilesStarted))
			call_and_free(hash_function, cmd);
		if (!parameters[i])
			break ;
		i++;
	}
}

bool	set_flag(char *parameter, uint8_t *flags)
{
	if (parameter && parameter[0] && parameter[0] == '-')
		parameter++;
	else
		return false;
	if (ft_strequ("p", parameter))
		*flags |= READ_STDIN_PRINT_STDOUT;
	else if (ft_strequ("q", parameter))
	{
		*flags |= PRINT_ONLY_CHECKSUM;
		// ft_bitset(flags, 0, PRINT_REVERSELY);//check
	}
	else if (ft_strequ("r", parameter)) //&& !PRINT_ONLY_CHECKSUM ? test
		*flags |= PRINT_REVERSELY;
	else if (ft_strequ("s", parameter))
		*flags |= READ_NEXT_ARG_PRINT_STDOUT;
	else //todo: error
		ERROR_RET("error flag")
	return true;
}

void	ft_ssl_stdin()
{
	char **parameters;
	bool is_launched;

	is_launched = false;
	while (!is_launched)
	{
		parameters = get_parameters_stdin();
		is_launched = ft_ssl(parameters); //todo set flag -q
		free(parameters[0]);
		free(parameters);
	}
}