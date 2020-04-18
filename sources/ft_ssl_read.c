#include "ft_ssl_read.h"

bool	set_input(char **parameters, size_t *i, t_command *cmd, bool areFilesStarted)
{
	if (areFilesStarted)
		read_file(parameters[*i], cmd);
	else if (cmd->flags & READ_NEXT_ARG_PRINT_STDOUT)
		read_next_arg(parameters[++(*i)], cmd);
	else if (cmd->flags & READ_STDIN_PRINT_STDOUT)
		read_fd(0, cmd);
	else
		return false;
	return true;
}

bool	read_fd(int fd, t_command *cmd)
{
	(void)fd;
	(void)cmd;
	ft_printf("from_stdin\n");
	return true;
}

bool	read_file(char *file_name, t_command *cmd)
{
	int fd = 0;

	(void)file_name;
	read_fd(fd, cmd);
	ft_printf("from_file\n");
	return true;
}

bool	read_next_arg(char *parameter, t_command *cmd)
{
	ft_printf("from_arg\n");
	if (parameter)
		cmd->input = ft_strdup(parameter);
	else
	{
		error_cmd(cmd->hash_type, "option requires an argument -- s\n");
		return false;
	}
	return true;
}

char	**get_parameters_stdin()
{
	char *line;
	char **parameters;

	line = NULL;
	ERROR(ERR_USAGE)
	get_next_line(0, &line);
	parameters = ft_strsplit_by_str(line, "\t \r"); //todo split string
	ft_strdel(&line);
	return parameters;
}

