#include "ft_printf.h"

typedef struct s_command
{
	char	*name;
	char	*message;
	short	flags;
}			t_command;