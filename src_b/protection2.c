/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:17:20 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/01 16:02:10 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_rec(t_check *data, int cnt)
{
	int	len_cnt;

	while (data->map[cnt] != '\0')
	{
		if (data->map[cnt] != '\n')
			len_cnt++;
		else
		{
			if (len_cnt != data->width - 1)
			{
				ft_printf("\nError: The Map is not rectangular\n");
				return (0);
			}
			len_cnt = 0;
		}
		cnt++;
	}
	if (len_cnt != data->width - 1)
	{
		ft_printf("\nError: The Map is not rectangular\n");
		return (0);
	}
	return (1);
}

void	check_path(int start_pos, char *map, int width)
{
	if (start_pos < width || start_pos > (ft_strlen(map) - width))
		return ;
	if (map[start_pos] == '1' || map[start_pos] == 'X'
		|| map[start_pos] == '\n')
		return ;
	map[start_pos] = 'X';
	check_path(start_pos + 1, map, width);
	check_path(start_pos - 1, map, width);
	check_path(start_pos + width, map, width);
	check_path(start_pos - width, map, width);
}

int	check_path_setup(t_check *data)
{
	char	*map;
	int		cnt;

	map = malloc(sizeof(char) * (data->width * data->height) + 1);
	if (map == NULL)
		return (0);
	ft_strlcpy(map, data->map, ft_strlen(data->map) + 1);
	check_path(data->y * data->width + data -> x, map, data->width);
	cnt = 0;
	while (map[cnt] != '\0')
	{
		if (map[cnt] != '1' && map[cnt] != 'X' && map[cnt] != '\n')
		{
			ft_printf("\nThere ain't valid path\n");
			return (free(map), 0);
		}
		cnt++;
	}
	return (free(map), 1);
}
