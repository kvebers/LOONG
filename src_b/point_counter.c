/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:33:05 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/01 19:44:21 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

// void	render_points(t_data *data)
// {
	
 //	}

void	init_stats_textures(t_data *data)
{
	data->stats[0] = mlx_load_png("./textures/stats/0.png");
	data->stats[1] = mlx_load_png("./textures/stats/S.png");
	data->stats[2] = mlx_load_png("./textures/stats/T.png");
	data->stats[3] = mlx_load_png("./textures/stats/A.png");
	data->stats_img[0] = mlx_texture_to_image(data->mlx, data->stats[0]);
	data->stats_img[1] = mlx_texture_to_image(data->mlx, data->stats[1]);
	data->stats_img[2] = mlx_texture_to_image(data->mlx, data->stats[2]);
	data->stats_img[3] = mlx_texture_to_image(data->mlx, data->stats[3]);
}

void	init_stats(t_data *data)
{
	int	cnt1;
	int cnt2;

	cnt1 = 0;
	cnt2 = 0;
	while (cnt1 < data->height)
	{
		while (cnt2 < 5)
		{
			if (cnt1 == 0)
			{
				mlx_image_to_window()
			}
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
	mlx_image_to_window(d->mlx, oof(d, x + y / 23), x, y);
}

void	long_line_2