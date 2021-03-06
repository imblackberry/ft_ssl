#ifndef FT_SSL_H
#define FT_SSL_H

#include "ft_printf.h"
#include "ft_ssl_md5.h"
#include "ft_ssl_sha256.h"
#include "errors.h"
#include "ft_ssl_hash.h"
#include "ft_ssl_read.h"

bool		ft_ssl(char **parameters);
void		ft_ssl_stdin();
bool		set_flag(char *parameter, uint8_t *flags);
void		launch(t_command *cmd, t_hash_f hash_function, char **parameters);

#endif