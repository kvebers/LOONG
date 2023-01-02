/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:11:33 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/02 16:49:57 by kvebers          ###   ########.fr       */
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