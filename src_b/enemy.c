/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:15:21 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/04 13:31:40 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void    render_holes(t_data *d)
{
	int	cnt;
	int	x;
	int	y;

	cnt = 0;
	mlx_delete_image(d->mlx, d->e_img[d->ani%2]);
	d->e_img[d->ani%2] = mlx_texture_to_image(d->mlx, d->enemy[d->ani%2]);
	while (d->map[cnt] != '\0')
	{
		x = cnt % d->width;
		y = cnt / d->width;
		if (d->map[cnt] == '2')
			mlx_image_to_window(d->mlx, d->e_img[d->ani % 2], x * 60, y * 84);
		cnt++;
	}
}

void	init_enemys_textures(t_data *data)
{
	data->enemy[0] = mlx_load_png("./textures/enemy/0.png");
	data->enemy[1] = mlx_load_png("./textures/enemy/0.png");
	data->enemy[2] = mlx_load_png("./textures/enemy/enemy_death_1.png");
	data->enemy[3] = mlx_load_png("./textures/enemy/enemy_death_2");
	data->enemy[4] = mlx_load_png("./textures/enemy/enemy_death_3");
	data->enemy[5] = mlx_load_png("./textures/enemy/enemy_tp1.png");
	data->enemy[6] = mlx_load_png("./textures/enemy/enemy_tp2.png");
	data->enemy[7] = mlx_load_png("./textures/enemy/enemy_tp3.png");
	data->enemy[8] = mlx_load_png("./textures/enemy/enemy_tp4.png");
	data->enemy[9] = mlx_load_png("./textures/enemy/enemy_tp5.png");
	data->enemy[10] = mlx_load_png("./textures/enemy/enemy_tp6.png");
	data->enemy[11] = mlx_load_png("./textures/enemy/enemy_idle1.png");
	data->enemy[12] = mlx_load_png("./textures/enemy/enemy_idle2.png");
	data->blood_t = mlx_load_png("./textures/blood/blood.png");
	data->e_img[0] = mlx_texture_to_image(data->mlx, data->enemy[0]);
	data->e_img[1] = mlx_texture_to_image(data->mlx, data->enemy[0]);
	data->e_img[2] = mlx_texture_to_image(data->mlx, data->enemy[11]);
	data->blood_img[0] = mlx_texture_to_image(data->mlx, data->blood_t);
	data->blood_img[1] = mlx_texture_to_image(data->mlx, data->blood_t);
	data->blood_img[2] = mlx_texture_to_image(data->mlx, data->blood_t);
	data->blood_img[4] = mlx_texture_to_image(data->mlx, data->blood_t);
}

void	check_lose(t_data *data, int x, int y)
{
		if (data->map[y * data->width + x] == '2')
			data->game_state = 2;
}