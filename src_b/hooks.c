/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:08:52 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/05 08:42:30 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_player(void *param)
{
	t_data	*d;
	int		x;
	int		y;

	d = (t_data *)param;
	if (d->blood_state < 1)
	{
		mlx_delete_image(d->mlx, d->temp_img);
		d->temp_img = mlx_texture_to_image(d->mlx, d->player[d->ani_spr]);
		ani_algo(d);
		x = d->x * 60 + d->x_off + 15;
			y = d->y * 84 + d->y_off + 30;
		mlx_image_to_window(d->mlx, d->temp_img, x, y);
	}
}

void	count_frames(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	d->frames++;
	if (d->blood_state < 1)
		d->fra++;
	if (d->fra > 5000)
	{
		d->frames = 0;
		d->fra = 0;
	}
	if (d->blood_state < 1)
		check_enemy_state(d);
	if (d->blood_state > 0)
		blood_screen(d);
}

void	keyhook(mlx_key_data_t key_data, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->ani == 0 && data->blood_state == 0)
	{
		if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
			pressed_w(data);
		else if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS)
			pressed_s(data);
		else if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS)
			pressed_d(data);
		else if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS)
			pressed_a(data);
	}
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}
