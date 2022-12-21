/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:18:07 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/21 16:37:08 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void free_data_textures(t_data *data, t_textures *textures)
{
    int cnt;

    cnt = 0;
    while(cnt < 52)
    {
        mlx_delete_texture(textures->wall[cnt]);
        mlx_delete_image(data->mlx, textures->wall_img[cnt]);
        cnt++;
    }
    mlx_delete_texture(textures->ground);
    mlx_delete_image(data->mlx, textures->wall_img[cnt]);
    
    free(textures);
    free(data->map);
    free(data->name);
    free(data);
}