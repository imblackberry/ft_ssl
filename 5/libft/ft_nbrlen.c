/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:54:46 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/20 17:01:42 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlen(int n)
{
	unsigned int		i;

	i = 0;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}
