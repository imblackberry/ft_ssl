#ifndef FT_SSL_HASH_H
#define FT_SSL_HASH_H

#include "ft_printf.h"

typedef enum		s_hash_type
{
	MD5,
	SHA256,
	N_HASH
}					t_hash_type;

extern const char *g_hash_name[N_HASH];

typedef struct	s_command
{
	t_hash_type	hash_type;
	char		*input;
	uint8_t		flags;
}				t_command;

typedef char*	(*t_hash_f)(struct s_command*);


bool		set_hash_type(char *name, t_hash_type *type);
t_hash_f	find_hash_function(t_hash_type type);
void		call_and_free(t_hash_f hash_function, t_command *cmd);
#endif