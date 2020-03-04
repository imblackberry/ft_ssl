#include "ft_ssl.h"

int	init_command(char **argv, t_command* cmd)
{
	if (!argv)
		return -1;
	cmd->name = ft_strdup(argv[1]);
	cmd->flags = get_flags(argv);
	return 0;
}

short	get_flags(char **argv)
{
	char *str;
	short flags;
	int i;

	flags = 0;
	i = 2;
	while ((str = argv[i]))
	{
		if (!str[0] || str[0] != '-')
		//todo: error
			return flags;
		str++;
		if (!ft_strcmp("p", str))
			flags |= FLAG_P;
		else if (!ft_strcmp("q", str))
			flags |= FLAG_Q;
		else if (!ft_strcmp("r", str))
			flags |= FLAG_R;
		else if (!ft_strcmp("s", str))
			flags |= FLAG_S;
		else
			//todo: error
			return flags;
		i++;
	}
	return flags;
}