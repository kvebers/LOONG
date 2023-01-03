/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:42:34 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/03 18:34:51 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	pressed_w(t_data *data)
{
	if (data->map[(data->y - 1) * data->width + data->x] != '1')
	{
		if (data->map[(data->y - 1) * data->width + data->x] == 'C')
		{
			data->map[(data->y - 1) * data->width + data->x] = '0';
			render_coins(data);
		}
		if (data->map[(data->y * data->width + data->x)] != 'E')
			data->map[(data->y * data->width + data->x)] = '2';
		check_lose(data, data->x, data->y - 1);
		check_win(data, data->x, data->y - 1);
		data -> y = data -> y - 1;
		data->turn_counter++;
		data->ani = 13;
		data->y_off = 84;
		stats_algo(data);
	}
}

void	pressed_s(t_data *data)
{
	if (data->map[(data->y + 1) * data->width + data->x] != '1')
	{
		if (data->map[(data->y + 1) * data->width + data->x] == 'C')
		{
			data->map[(data->y + 1) * data->width + data->x] = '0';
			render_coins(data);
		}
		if (data->map[(data->y * data->width + data->x)] != 'E')
			data->map[(data->y * data->width + data->x)] = '2';
		check_lose(data, data->x, data->y + 1);
		check_win(data, data->x, data->y + 1);
		data -> y = data -> y + 1;
		data->turn_counter++;
		data->ani = 13;
		data->y_off = -84;
		stats_algo(data);
	}
}

void	pressed_d(t_data *data)
{
	if (data->map[(data->y) * data->width + data->x + 1] != '1')
	{
		if (data->map[(data->y) * data->width + data->x + 1] == 'C')
		{
			data->map[(data->y) * data->width + data->x + 1] = '0';
			render_coins(data);
		}
		if (data->map[(data->y * data->width + data->x)] != 'E')
			data->map[(data->y * data->width + data->x)] = '2';
		check_lose(data, data->x + 1, data->y);
		check_win(data, data->x + 1, data->y);
		data -> x = data -> x + 1;
		data->turn_counter++;
		data->ani = 13;
		data->x_off = -60;
		stats_algo(data);
	}
}

void	pressed_a(t_data *data)
{
	if (data->map[(data->y) * data->width + data->x - 1] != '1')
	{
		if (data->map[(data->y) * data->width + data->x - 1] == 'C')
		{
			data->map[(data->y) * data->width + data->x - 1] = '0';
			render_coins(data);
		}
		if (data->map[(data->y * data->width + data->x)] != 'E')
			data->map[(data->y * data->width + data->x)] = '2';
		check_lose(data, data->x - 1, data->y);
		check_win(data, data->x - 1, data->y);
		data -> x = data -> x - 1;
		data->turn_counter++;
		data->ani = 13;
		data->x_off = 60;
		stats_algo(data);
	}
}

void	render_coins(t_data *data)
{
	mlx_delete_image(data->mlx, data->coins_img);
	data->coins_img = mlx_texture_to_image(data->mlx, data->coins);
	init_coins(data);
}
