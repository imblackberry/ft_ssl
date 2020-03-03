#include "ft_printf.h"

//flags
// #define ALL_FLAGS	"pqrs"
#define FLAG_P	(1 << 1)
#define FLAG_Q	(1 << 2)
#define FLAG_R	(1 << 3)
#define FLAG_S	(1 << 4)
#define N_FLAGS	(1 << 5)

typedef struct s_command
{
	char	*name;
	char	*message;
	short	flags;
}			t_command;

int		init_command(char **argv, t_command* cmd);
short	get_flags(char **argv);