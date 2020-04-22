#ifndef FT_SSL_READ_H
#define FT_SSL_READ_H

#include "ft_ssl_hash.h"
#include "errors.h"


typedef enum	s_flags
{
	READ_STDIN_PRINT_STDOUT = (1 << 0), //p
	PRINT_ONLY_CHECKSUM = (1 << 1), //q overrides the -r option
	PRINT_REVERSELY = (1 << 2), //r does nothing when combined with the -p
	READ_NEXT_ARG_PRINT_STDOUT = (1 << 3) //s
}				t_flags;

bool	set_input(char **argv, size_t *i, t_command *cmd, bool isFilesStarted);
bool	read_fd(const int fd, char **input);
bool	read_file(const char *file_name, t_command *cmd);
bool	read_next_arg(char *parameter, t_command *cmd);
char	**get_parameters_stdin();
#endif