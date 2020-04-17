#ifndef FT_SSL_H
#define FT_SSL_H

#include "ft_printf.h"
#include "ft_ssl_md5.h"
#include "ft_ssl_sha256.h"
#include "errors.h"
#include "hash_structs.h"
#include "ft_ssl_read.h"

bool		ft_ssl(char **parameters);
bool		set_hash_type(char *name, t_hash_type *type);
t_hash_f	find_hash_function(t_hash_type type);
bool		set_flag(char *str, uint8_t *flags);
bool		launch(t_command *cmd, t_hash_f hash_function, char **parameters);

#endif