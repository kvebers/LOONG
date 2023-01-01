/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:50:33 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/01 16:02:06 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	protection(char *argv)
{
	t_check	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	if (check_name(argv) == 0)
		return (free(data), 0);
	data->name = ft_strjoin("./maps/", argv);
	data->width = calculate_width(data->name);
	data->height = calculate_height(data->name);
	data->map = create_name(data->name);
	data->height = calculate_height(data->name);
	if (check_chars(data) == 0 || check_rec(data, 0) == 0)
		return (free(data->name), free(data->map), free(data), 0);
	data->x = init_x(data->width, data->map);
	data->y = init_y(data->width, data->map);
	if (check_must_have(data) == 0 || surrounded_by_walls(data, 0, 0) == 0)
		return (free(data->name), free(data->map), free(data), 0);
	if (check_path_setup(data) == 0)
		return (free(data->name), free(data->map), free(data), 0);
	return (free(data->name), free(data->map), free(data), 1);
}

int	check_name(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (*(argv + len - 1) == 'r'
		&& *(argv + len - 2) == 'e'
		&& *(argv + len - 3) == 'b'
		&& *(argv + len - 4) == '.')
		return (1);
	ft_printf("\nError: The map should have .ber format\n");
	return (0);
}

int	check_chars(t_check *data)
{
	int		cnt;
	char	*allowed;

	allowed = malloc(sizeof(char) * 7);
	ft_strlcpy(allowed, "\nP01EC", 7);
	cnt = 0;
	while (data->map[cnt] != '\0')
	{
		if (ft_strchr2(allowed, data->map[cnt]) == NULL)
		{
			ft_printf("\nError: Not allowed char: %c", data->map[cnt]);
			ft_printf(", At cordinates: X: %i ", cnt % data->width);
			ft_printf("Y: %i\n\n", cnt / data->width);
			return (free(allowed), 0);
		}
		cnt++;
	}
	return (free(allowed), 1);
}

int	check_must_have(t_check *data)
{
	if (ft_strchr2(data->map, 'C') == NULL
		|| ft_strchr2(data->map, 'E') == NULL
		|| ft_strchr2(data->map, 'P') == NULL)
	{
		printf("\nError: There is not a single C, E or P Char in the map\n");
		return (0);
	}
	return (1);
}

int	surrounded_by_walls(t_check *d, int cnt, int error)
{
	while (d->map[cnt] != '\0')
	{
		if (d->map[cnt] == '\n')
			cnt++;
		if (d->map[cnt] != '1' && cnt / d->width == 0)
			error = 1;
		if (d->map[cnt] != '1' && cnt % d->width == 0)
			error = 1;
		if (cnt % d->width == d->width - 2 && d->map[cnt] != '1')
			error = 1;
		if (cnt / d->width == d->height - 1 && d->map[cnt] != '1')
			error = 1;
		if (error == 1)
		{
			ft_printf("Error not surrounded, by walls");
			return (0);
		}
		cnt++;
	}
	return (1);
}
