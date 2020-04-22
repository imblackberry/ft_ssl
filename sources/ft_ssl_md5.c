#include "ft_ssl_md5.h"
#include "ft_ssl_hash.h"

void	padding_bits(char* input, t_md5_storage* md5)
{
	md5->bit_len = ft_strlen(input) * 8 + 1;
	while(md5->bit_len % 512 != 448)
		md5->bit_len++;
	if ((md5->result = ft_memalloc(md5->bit_len + 64)))
		return ;
	
	ft_printf("len = %zu\n", md5->bit_len);
}

char	*ft_ssl_md5(t_command* cmd)
{
	// t_md5_storage md5;
	
	// cmd->input = "1111111111222222222233333333334444444444555555555566666";
	ft_putstr(cmd->input);
	// padding_bits(cmd->input, &md5);	//padding bits
	//append length
	//init buffer
	//algirithm/calc?
	return NULL;
}