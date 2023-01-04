/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:11:33 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/04 19:26:48 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void    stats_algo(t_data *d)
{
    int t;
    int w;
    
    if (d->turn_counter > 99999)
        mlx_close_window(d->mlx);
    w = d->width - 1;
    t = d->turn_counter;
    mlx_delete_image(d->mlx, d->p_i[0]);
    mlx_delete_image(d->mlx, d->p_i[1]);
    mlx_delete_image(d->mlx, d->p_i[2]);
    mlx_delete_image(d->mlx, d->p_i[3]);
    mlx_delete_image(d->mlx, d->p_i[4]);
    d->p_i[0] = mlx_texture_to_image(d->mlx, d->points[t % 10]);
    d->p_i[1] = mlx_texture_to_image(d->mlx, d->points[t / 10 % 10]);
    d->p_i[2] = mlx_texture_to_image(d->mlx, d->points[t / 100 % 10]);
    d->p_i[3] = mlx_texture_to_image(d->mlx, d->points[t / 1000 % 10]);
    d->p_i[4] = mlx_texture_to_image(d->mlx, d->points[t / 10000 % 10]);
    mlx_image_to_window(d->mlx, d->p_i[4], w * 60, 84);
    mlx_image_to_window(d->mlx, d->p_i[3], (w + 1) * 60, 84);
    mlx_image_to_window(d->mlx, d->p_i[2], (w + 2)* 60, 84);
    mlx_image_to_window(d->mlx, d->p_i[1], (w + 3) * 60, 84);
    mlx_image_to_window(d->mlx, d->p_i[0], (w + 4) * 60, 84);
}

void    health_algo(t_data *d)
{
    int w;
    int cnt;
    
    mlx_delete_image(d->mlx, d->health_i);
    d->health_i = mlx_texture_to_image(d->mlx, d->health);
    w = d->width - 1;
    cnt = 0;
    while (cnt < d->life)
    {
        mlx_image_to_window(d->mlx, d->health_i, (w + cnt) * 60, 2 * 84);
        cnt++;
    }
    if (d->life != 3)
        spawn_blood_screen(d);
}

void    spawn_blood_screen(t_data *d)
{
    int cnt;
    int c;

    cnt = 0;
    c = 0;
    mlx_delete_image(d->mlx, d->blood_img[10]);
    d->blood_img[10] = mlx_texture_to_image(d->mlx, d->blood_t[1]);
    while (c < d->height)
    {
        while ((cnt < d->width + 3))
	    {
            if (c == 0 || c == d->height - 1)
		        mlx_image_to_window(d->mlx, d->blood_img[10], cnt * 60, 84 * c);
		    cnt++;
	    }
        cnt = 0;
        c++;
    }
}