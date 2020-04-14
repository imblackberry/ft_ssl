#ifndef FT_SSL_H
#define FT_SSL_H

#include "ft_printf.h"
#include "ft_ssl_md5.h"
#include "ft_ssl_256.h"

#define ERROR(error_str) { ft_putstr(error_str); }
#define ERROR_RET(error_str) { ERROR(error_str) return false; }

#define ERR_USAGE "usage: ft_ssl command [command opts] [command args]"


typedef enum	s_flags
{
	READ_STDIN_PRINT_STDOUT = (1 << 1), //p
	PRINT_ONLY_CHECKSUM = (1 << 2), //q overrides the -r option
	PRINT_REVERSELY = (1 << 3), //r does nothing when combined with the -p
	READ_NEXT_ARG_PRINT_STDOUT = (1 << 4) //s
}				t_flags;

typedef enum		s_hash_type
{
	MD5,
	SHA256,
	N_HASH
}					t_hash_type;

typedef bool	(*t_hash_f)(struct s_command*);

typedef struct	s_command
{
	t_hash_type	hash_type;
	char		*input;
	short		flags;
}				t_command;

bool		ft_ssl(char **argv);
bool		set_hash_type(char *name, t_hash_type *type);
t_hash_f	find_hash_function(t_hash_type type);
short		get_flags(char **argv);
bool		launch(t_command *cmd, t_hash_f hash_function, char **argv);

#endif