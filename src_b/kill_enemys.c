/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_enemys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:02:02 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/05 06:27:19 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_blood(t_data *data)
{
	data->blood_img[0] = mlx_texture_to_image(data->mlx, data->blood_t[0]);
	data->blood_img[1] = mlx_texture_to_image(data->mlx, data->blood_t[0]);
	data->blood_img[2] = mlx_texture_to_image(data->mlx, data->blood_t[0]);
	data->blood_img[3] = mlx_texture_to_image(data->mlx, data->blood_t[0]);
	data->blood_img[4] = mlx_texture_to_image(data->mlx, data->blood_t[0]);
	data->blood_img[5] = mlx_texture_to_image(data->mlx, data->blood_t[0]);
	data->blood_img[6] = mlx_texture_to_image(data->mlx, data->blood_t[0]);
	data->blood_img[7] = mlx_texture_to_image(data->mlx, data->blood_t[0]);
	data->blood_img[8] = mlx_texture_to_image(data->mlx, data->blood_t[0]);
	data->blood_img[9] = mlx_texture_to_image(data->mlx, data->blood_t[0]);
	system("afplay ./Music/splat.mp3 &");
}

void	spawn_blood(t_data *d, int b)
{
	int	cnt;
	int	c;

	cnt = 0;
	c = 0;
	while (c < d->height)
	{
		while (cnt < d->width * 84 + 180)
		{
			mlx_image_to_window(d->mlx, d->blood_img[b], cnt + b * 5, 84 * c);
			cnt = cnt + 60;
		}
		cnt = 0;
		c++;
	}
}

void	clear_blood(t_data *d, int b)
{
	mlx_delete_image(d->mlx, d->blood_img[b]);
}

void	blood_screen(t_data *data)
{
	if (data->blood_state == 20)
		init_blood(data);
	if (data->blood_state > 10)
		spawn_blood(data, data->blood_state % 10);
	else if (data->blood_state > 0)
		clear_blood(data, data->blood_state % 10);
	data->blood_state--;
}