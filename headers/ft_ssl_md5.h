#ifndef FT_SSL_MD5_H
#define FT_SSL_MD5_H

#include "ft_printf.h"
#include "hash.h"

typedef struct s_md5_storage
{
	size_t		bit_len;
	uint8_t*	result;
} t_md5_storage;


void	padding_bits();
char	*ft_ssl_md5(t_command* cmd);
#endif