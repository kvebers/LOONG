/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:24:46 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/05 17:15:31 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	count_frames1(void *param)
{
	t_miniani	*data;

	data = (t_miniani *)param;
	if (data->frames % 30 == 0)
	{
		mlx_delete_image(data->mlx, data->ani_i);
		data->ani_i = mlx_texture_to_image(data->mlx, data->ani[0]);
	}
	else if (data->frames % 30 == 10)
	{
		mlx_delete_image(data->mlx, data->ani_i);
		data->ani_i = mlx_texture_to_image(data->mlx, data->ani[1]);
	}
	else if (data->frames % 30 == 20)
	{
		mlx_delete_image(data->mlx, data->ani_i);
		data->ani_i = mlx_texture_to_image(data->mlx, data->ani[2]);
	}
	mlx_image_to_window(data->mlx, data->ani_i, 0, 0);
	data->frames++;
}
