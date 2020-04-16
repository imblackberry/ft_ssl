#include "ft_ssl_read.h"

bool	set_input(char **argv, size_t *i, t_command *cmd, bool areFilesStarted)
{
	if (areFilesStarted)
		read_from_file(argv[*i], &cmd->input);
	else if (cmd->flags & READ_NEXT_ARG_PRINT_STDOUT)
	{
		(*i)++;
		cmd->input = ft_strdup(argv[*i]);
		ft_printf("from_arg\n");
	}
	else if (cmd->flags & READ_STDIN_PRINT_STDOUT)
		read_from_stdin(&cmd->input);
	else
		return false;
	return true;
}

bool	read_from_stdin(char **input)
{
	(void)input;
	ft_printf("from_stdin\n");
	return true;
}

bool	read_from_file(char *file_name, char **input)
{
	(void)input;
	(void)file_name;
	ft_printf("from_file\n");
	return true;
}

