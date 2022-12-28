/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:08:52 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/28 14:59:36 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_player(void *param)
{
	t_data	*d;
	d = param;
	mlx_delete_image(d->mlx, d->temp_img);
	d->temp_img = mlx_texture_to_image(d->mlx, d->player[0]);
	mlx_image_to_window(d->mlx, d->temp_img, d->x * 60 + 15, d->y * 84 + 30);
}

void	count_frames(void *param)
{
	t_data	*d;
	d = param;
	d->frames++;
	if(d->frames > 20000)
		d->frames = 0;
}

void	keyhook(mlx_key_data_t key_data, void *param)
{
	t_data *data;
	
	data = (t_data*)param;
	if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
		pressed_w(data);
	else if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS)
		pressed_s(data);
	else if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS)
		pressed_d(data);
	else if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS)
		pressed_a(data);
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}
