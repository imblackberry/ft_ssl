#ifndef ERRORS_H
#define ERRORS_H

#define ERROR(error_str) { ft_putstr(error_str); }
#define ERROR_RET(error_str) { ERROR(error_str) return false; }

#define ERR_USAGE "usage: ft_ssl command [command opts] [command args]"

void	error_usage_msg(char *invalid_cmd);

#endif