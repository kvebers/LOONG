/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:19:26 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/20 14:36:57 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int calculate_width(char *name)
{
	int fd;
	int len;
	char *data;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return 0;
	data = get_next_line(fd);
	len = ft_strlen(data);
	close(fd);
	return (free(data), len);
}

int calculate_height(char *name)
{
	int 	cnt;
	char 	*line;
	int 	fd1;

	cnt = 0;
	fd1 = open(name, O_RDONLY);
	line = get_next_line(fd1);
	while(line != NULL)
	{
		free(line);
		cnt++;
		line = get_next_line(fd1);
	}
	free(line);
	close(fd1);
	return (cnt);
}

char	*ft_strjoin3(char *s1, char *s2)
{
	size_t	counter1;
	size_t	counter2;
	size_t	counter3;
	char	*dest;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	counter1 = ft_strlen((char *)s1);
	counter2 = ft_strlen((char *)s2);
	counter3 = 0;
	dest = ft_calloc((counter1 + counter2 + 1), sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (counter3 < counter1)
	{
		*(dest + counter3) = *(s1 + counter3);
		counter3++;
	}
	counter3 = 0;
	while (counter3 < counter2)
	{
		*(dest + counter1 + counter3) = *(s2 + counter3);
		counter3++;
	}
	return (free(s1), free(s2), dest);
}

int init_x(int width, char *map)
{
    int cnt;

    cnt = 0;
    while(*(map + cnt) != 'P')
        cnt++;
    return(cnt % width);
    
}

int init_y(int width, char *map)
{
    int cnt;

    cnt = 0;
    while(*(map + cnt) != 'P')
        cnt++;
    return(cnt / width);
}