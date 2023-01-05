/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:22:59 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/05 13:32:53 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	change_map(t_data *d, int c, int x, int y)
{
	while (c < 26)
	{
		mlx_delete_image(d->mlx, d->wall_img[c]);
		d -> wall_img[c] = wall_img(d->mlx, d->wall[c]);
		c++;
	}
	c = 0;
	while (y < d->height)
	{
		x = 0;
		while (x < d->width)
		{
			if (d->map[c] == '1')
			{
				mlx_image_to_window(d->mlx, of(d, d->fra + c), x * 60, y * 84);
			}
			x++;
			c++;
		}
		y++;
	}
	if (d->life != 5)
		spawn_blood_screen(d);
}

void	init2(t_data *d)
{
	d->frames = 0;
	d->ani_spr = 0;
	d->ani = 0;
	d->x_off = 0;
	d->y_off = 0;
	d->fra = 0;
	d->turn_counter = 0;
	d->game_state = 0;
	d->blood_state = 0;
	d->life = 5;
	d->enemy_count = 0;
}
