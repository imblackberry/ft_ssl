/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:33:14 by vblokha           #+#    #+#             */
/*   Updated: 2017/12/07 16:33:19 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // DELETE!!!!!!!!!!!!!!!!!!!!!!!!!!!
 typedef struct s_mylist
 {
 	int fd;
 	char *content;
 	t_list *next;
 }				t_mylist;

static int ft_line_size(char *str)
{
	int i;

	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	return (i);
}

int get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	static char *myline = "";
	int ret;
	int k;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	k = 0;
	while ((ret = read(fd, buf, BUFF_SIZE))) 
	{
		buf[ret] = '\0';
		myline = ft_strjoin(myline, buf);
//		printf("Dance\n");
//printf("ret = %d\n", ret);
		if (ft_strchr(myline, '\n'))
			break ;
	}
	*line = ft_strsub(myline, 0, ft_line_size(myline));
//	printf("line_____________________________________|%s|\n", *line);
	//printf("myline ---|%s|---\n", myline);
 
	if (myline[ft_line_size(myline)] == '\0' || (myline[ft_line_size(myline)] == '\n' && myline[ft_line_size(myline) + 1] == '\0'))
		k = 1;
//	printf("k = %d\n", k);	
	if (myline[0] != '\0' && ft_strchr(myline, '\n') != 0)
	{
		myline = ft_strdup(ft_strchr(myline, '\n') + 1);
		//printf("ret2 = %d\n", ret);
	}

	printf("kusok ---|%s|---\n", myline);
// 	printf("THE END\n");
	if ((ret == 0 && k == 1))
	{
		//*line = ft_strnew(1);
		myline = "";
		return (0);
	}
	return (1);
}
