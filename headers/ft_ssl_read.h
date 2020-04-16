#ifndef READ_H
#define READ_H

#include "hash_structs.h"

typedef enum	s_flags
{
	READ_STDIN_PRINT_STDOUT = (1 << 0), //p
	PRINT_ONLY_CHECKSUM = (1 << 1), //q overrides the -r option
	PRINT_REVERSELY = (1 << 2), //r does nothing when combined with the -p
	READ_NEXT_ARG_PRINT_STDOUT = (1 << 3) //s
}				t_flags;

bool	set_input(char **argv, size_t *i, t_command *cmd, bool isFilesStarted);
bool	read_from_stdin(char **input);
bool	read_from_file(char *file_name, char **input);

#endif