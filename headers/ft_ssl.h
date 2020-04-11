#ifndef FT_SSL_H
#define FT_SSL_H

#include "ft_printf.h"
#define ERROR(error_str) { ft_putstr(error_str); }
#define ERROR_RET(error_str) { ERROR(error_str) return -1; }

#define ERR_USAGE "usage: ft_ssl command [command opts] [command args]"

enum FLAG
{
	FLAG_P = (1 << 1),
	FLAG_Q = (1 << 2),
	FLAG_R = (1 << 3),
	FLAG_S = (1 << 4)
};


typedef struct s_command
{
	t_hash		hash;
	char		*input; 
	short		flags;
}				t_command;

typedef int (*t_hash_f)(t_command);

typedef struct s_hash
{
	const char	*name;
	t_hash_f	function;
}				t_hash;

int			ft_ssl(char **argv);
int			init_command(char **argv, t_command* cmd);
t_hash_f	find_hash_function(char* cmd_name);
short		get_flags(char **argv);
t_hash		hash_by_name(char* cmd_name);
// void		get_hash(t_command* cmd);
#endif