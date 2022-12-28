/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:42:34 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/28 15:13:44 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	pressed_w(t_data *data)
{
	if (data->map[(data->y - 1) * data->width + data->x] != '1')
	{
		data -> y = data -> y - 1;
		data->turn_counter++;
		ft_printf("\nTurns done: %i", data->turn_counter);
	}
}

void	pressed_s(t_data *data)
{
	if (data->map[(data->y + 1) * data->width + data->x] != '1')
	{
		data -> y = data -> y + 1;
		data->turn_counter++;
		ft_printf("\nTurns done: %i", data->turn_counter);
	}
}

void	pressed_d(t_data *data)
{
	if (data->map[(data->y) * data->width + data->x + 1] != '1')
	{
		data -> x = data -> x + 1;
		data->turn_counter++;
		ft_printf("\nTurns done: %i", data->turn_counter);
	}
}

void	pressed_a(t_data *data)
{
	if (data->map[(data->y) * data->width + data->x - 1] != '1')
	{
		data -> x = data -> x - 1;
		data->turn_counter++;
		ft_printf("\nTurns done: %i", data->turn_counter);
	}
}
