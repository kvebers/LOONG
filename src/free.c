/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:18:07 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/22 18:43:17 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void free_data_textures(t_data *data)
{
    int cnt;

    cnt = 0;
    while(cnt < 52)
    {
        mlx_delete_texture(data->wall[cnt]);
        mlx_delete_image(data->mlx, data->wall_img[cnt]);
        cnt++;
    }
    mlx_delete_texture(data->ground);
    mlx_delete_image(data->mlx, data->wall_img[cnt]);
    free(data->map);
    free(data->name);
    free(data);
}
