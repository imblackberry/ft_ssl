#include "ft_ssl_read.h"

bool	set_input(char **parameters, size_t *i, t_command *cmd, bool areFilesStarted)
{
	if (areFilesStarted)
	{
		if (parameters[*i])
			return read_file(parameters[*i], cmd);
		else
			cmd->flags |= READ_STDIN_PRINT_STDOUT | PRINT_ONLY_CHECKSUM;
	}
	if (cmd->flags & READ_STDIN_PRINT_STDOUT)
		return read_fd(0, &(cmd->input));
	else if (cmd->flags & READ_NEXT_ARG_PRINT_STDOUT)
		return read_next_arg(parameters, i, cmd);
	else
		return false;
	return true;
}

bool	read_fd(const int fd, char **input)
{
	const size_t	buff_size = 64;
	char			buff[buff_size + 1];
	size_t			bytes_read;
	char			*tmp;

	*input = ft_strnew(0);
	while((bytes_read = read(fd, buff, buff_size)))
	{
		buff[bytes_read] = '\0';
		tmp = *input;
		*input = ft_strjoin(*input, buff);
		ft_strdel(&tmp);
	}
	ft_printf("read_fd\n");
	ft_printf("INPUT: |%s|\n", *input);
	return true;
}

bool	read_file(const char *file_name, t_command *cmd)
{
	int		fd;
	bool	ret;

	fd = open(file_name, O_RDONLY);
	ret = read_fd(fd, &(cmd->input));
	close(fd);
	ft_printf("read_file\n");
	return ret;
}

bool	read_next_arg(char **parameters, size_t *i, t_command *cmd)
{
	ft_printf("read_arg\n");
	if (parameters[(*i)++] && parameters[*i])
		cmd->input = ft_strdup(parameters[*i]);
	else
	{
		error_cmd(cmd->hash_type, "option requires an argument -- s\n");
		return false;
	}
	ft_printf("INPUT: |%s|\n", cmd->input);
	return true;
}

char	**get_parameters_stdin()
{
	char *line;
	char **parameters;

	line = NULL;
	get_next_line(0, &line);
	parameters = ft_strsplit_by_str(line, "\t \r"); //todo split string
	ft_strdel(&line);
	return parameters;
}

