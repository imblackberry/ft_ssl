#ifndef ERRORS_H
#define ERRORS_H


#include "ft_ssl_hash.h"
#include "libft.h"

#define ERROR(error_str) { ft_putstr_fd(error_str, 2); }
#define ERROR_RET(error_str) { ERROR(error_str) return false; }

#define ERR_USAGE "usage: ft_ssl command [command opts] [command args]\n"

void	error_usage_msg(char *invalid_cmd);
void	error_cmd(t_hash_type hash_type, char *msg);

#endif