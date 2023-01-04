/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:33:05 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/04 18:19:39 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_stats_textures(t_data *data)
{
	data->stats[0] = mlx_load_png("./textures/stats/S.png");
	data->stats[1] = mlx_load_png("./textures/stats/T.png");
	data->stats[2] = mlx_load_png("./textures/stats/A.png");
	data->stats_img[0] = mlx_texture_to_image(data->mlx, data->stats[0]);
	data->stats_img[1] = mlx_texture_to_image(data->mlx, data->stats[1]);
	data->stats_img[2] = mlx_texture_to_image(data->mlx, data->stats[2]);
	data->points[0] = mlx_load_png("./textures/points/0.png");
	data->points[1] = mlx_load_png("./textures/points/1.png");
	data->points[2] = mlx_load_png("./textures/points/2.png");
	data->points[3] = mlx_load_png("./textures/points/3.png");
	data->points[4] = mlx_load_png("./textures/points/4.png");
	data->points[5] = mlx_load_png("./textures/points/5.png");
	data->points[6] = mlx_load_png("./textures/points/6.png");
	data->points[7] = mlx_load_png("./textures/points/7.png");
	data->points[8] = mlx_load_png("./textures/points/8.png");
	data->points[9] = mlx_load_png("./textures/points/9.png");
	data->p_i[0] = mlx_texture_to_image(data->mlx, data->points[0]);
	data->p_i[1] = mlx_texture_to_image(data->mlx, data->points[0]);
	data->p_i[2] = mlx_texture_to_image(data->mlx, data->points[0]);
	data->p_i[3] = mlx_texture_to_image(data->mlx, data->points[0]);
	data->p_i[4] = mlx_texture_to_image(data->mlx, data->points[0]);
}

void	init_stats(t_data *data)
{
	int	cnt1;
	int	cnt2;

	cnt1 = 0;
	cnt2 = 0;
	while (cnt1 < data->height)
	{
		while (cnt2 < 5)
		{
			if (cnt1 == 0)
				long_line_2(data, (data->width - 1 + cnt2) * 60, cnt1 * 84);
			else if (cnt1 == 1)
				long_line_1(data, cnt2 - 1);
			else
				long_line(data, (data->width - 1 + cnt2) * 60, cnt1 * 84);
			cnt2++;
		}
		cnt2 = 0;
		cnt1++;
	}
}

void	long_line(t_data *d, int x, int y)
{
	mlx_image_to_window(d->mlx, d->exit_img[1], x, y);
}

void	long_line_2(t_data *d, int x, int y)
{
	static int	called;

	if (called == 0)
		mlx_image_to_window(d->mlx, d->stats_img[0], x, y);
	if (called == 1)
		mlx_image_to_window(d->mlx, d->stats_img[1], x, y);
	if (called == 2)
		mlx_image_to_window(d->mlx, d->stats_img[2], x, y);
	if (called == 3)
		mlx_image_to_window(d->mlx, d->stats_img[1], x, y);
	if (called == 4)
		mlx_image_to_window(d->mlx, d->stats_img[0], x, y);
	called++;
}

void	long_line_1(t_data *d, int x)
{
	static int	called_1;

	if (called_1 == 0)
		mlx_image_to_window(d->mlx, d->p_i[0], (d->width + x) * 60, 84);
	if (called_1 == 1)
		mlx_image_to_window(d->mlx, d->p_i[1], (d->width + x) * 60, 84);
	if (called_1 == 2)
		mlx_image_to_window(d->mlx, d->p_i[2], (d->width + x) * 60, 84);
	if (called_1 == 3)
		mlx_image_to_window(d->mlx, d->p_i[3], (d->width + x) * 60, 84);
	if (called_1 == 4)
		mlx_image_to_window(d->mlx, d->p_i[4], (d->width + x) * 60, 84);
	called_1++;
	if (called_1 == 5)
		called_1 = 0;
}
