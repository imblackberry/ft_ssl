/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:34:16 by vblokha           #+#    #+#             */
/*   Updated: 2018/01/23 16:34:21 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>//415
#include <stdio.h>
//#include "libft.h"
#include <unistd.h>

unsigned long long int ft_unicode_last_byte(unsigned long long int start)
{
	unsigned long long int to_right;
	unsigned long long int to_left;

	to_left = start >> 6;
	to_right = to_left << 6;
	return (128 | (to_right ^ start));
}

void ft_unicode_4(unsigned long long int start)
{
	unsigned long long int a;
	unsigned long long int b;
	unsigned long long int c;
	unsigned long long int d;

	a = 240 | start >> 18;
	b = ft_unicode_last_byte((((start >> 18) << 18) ^ start) >> 12);
	c = ft_unicode_last_byte((((start >> 12) << 12) ^ start) >> 6);
	d = ft_unicode_last_byte(((start >> 6) << 6) ^ start);
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	write(1, &d, 1);
}

void ft_unicode_3(unsigned long long int start)
{
	unsigned long long int a;
	unsigned long long int b;
	unsigned long long int c;

	a = 224 | start >> 12;
	b = ft_unicode_last_byte((((start >> 12) << 12) ^ start) >> 6);
	c = ft_unicode_last_byte(((start >> 6) << 6) ^ start);
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void ft_unicode_2(unsigned long long int start)
{
	unsigned long long int a;
	unsigned long long int b;
	unsigned long long int to_left;

	to_left = start >> 6;
	a = (192 | to_left);
	b = ft_unicode_last_byte(start);
	write(1, &a, 1);
	write(1, &b, 1);
}

void	ft_unicode(unsigned long long int n)
{
	if(n <= 2047)
		ft_unicode_2(n);
	else if(n <= 65535)
	 	ft_unicode_3(n);
	else if(n <= 2097151)
		ft_unicode_4(n);
}

void	ft_unicode_s(unsigned long long int *n)
{
	int i;

	i = 0;
	while(n != NULL)
	{
		ft_unicode(n[i]);
		i++;
	}
}

int	ft_printf(const char *s, ... )
{
  va_list v;
  int i;

  i = 0;
 va_start(v, s);
//   n = va_arg(v, int);
//   ft_putnbr(n);
//   ft_putchar('\n');
//   n = va_arg(v, int);
//  ft_putnbr(n);
//   ft_putchar('\n');
//   n = va_arg(v, int);
//  ft_putnbr(n);
//   ft_putchar('\n');
//   n = va_arg(v, int);
//  ft_putnbr(n);
//   ft_putchar('\n');
// n = va_arg(v, int);
//  ft_putnbr(n);
//   S       U   C
//	sSpdDioOuUxXcC



while (s[i])
 {
	if (s[i] == '%')
	{

		i++;
		// if (s[i] == 'd' || s[i] == 'i')
		// {
		// 	ft_putnbr(va_arg(v, int));
		// 	i++;
		// }
		// else if (s[i] == 'c')
		// {
		// 	ft_putchar(va_arg(v, int));
		// 	i++;
		// }
		// else if (s[i] == 's')
		// {
		// 	ft_putstr((char *)va_arg(v, long long int));
		// 	i++;
		// }
		// else if (s[i] == 'u')
		// {
		// 	ft_putnbr(va_arg(v, unsigned int));
		// 	i++;
		// }
		// else if (s[i] == 'U')
		// {
		// 	ft_putnbr(va_arg(v, unsigned long int));
		// 	i++;
		// }
		// else if (s[i] == 'D')
		// {
		// 	ft_putnbr(va_arg(v, unsigned long int));
		// 	i++;
		// }
		// else if (s[i] == 'x')
		// {
		// 	ft_putstr(ft_itoa_base(va_arg(v, unsigned int), 16));
		// 	i++;
		// }
		// else if (s[i] == 'X')
		// {
		// 	ft_putstr(ft_strtoupper(ft_itoa_base(va_arg(v, unsigned int), 16)));
		// 	i++;
		// }
		// else if(s[i] == 'o')
		// {
		// 	ft_putstr(ft_itoa_base(va_arg(v, unsigned int), 8));
		// 	i++;
		// }
		// else if(s[i] == 'O')//loooooooooooook
		// {
		// 	ft_putstr(ft_itoa_base(va_arg(v, unsigned long int), 8));
		// 	i++;
		// }
		// else if(s[i] == 'p')
		// {
		// 	ft_putstr("0x");
		// 	ft_putstr(ft_itoa_base(va_arg(v, unsigned long long int), 16));
		// 	i++;
		// }
		if(s[i] == 'C')
		{
			ft_unicode(va_arg(v, unsigned long long int));
			i++;
		}
		else if (s[i] == 'S')
		{
			ft_unicode_s((unsigned long long int*)va_arg(v, unsigned long long int));
			i++;
		}
	}
	else
		write(1, s + i++, 1);
}



  va_end(v);
  return 7;
}
//PUTNUMBER!!!!!!!!!!!!!!!!!!!!!!!!!
int main()
{
	unsigned long long a[3];
	a[0] = 120000;
	a[1] = 120001;
	a[2] = 120002;
	ft_printf("  %S", a);
//1011 111111 011100

	return (0);
}