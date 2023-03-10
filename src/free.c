/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:18:07 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/01 12:31:55 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_data_textures(t_data *data)
{
	int	cnt;

	cnt = 0;
	while (cnt < 26)
	{
		mlx_delete_texture(data->wall[cnt]);
		mlx_delete_image(data->mlx, data->wall_img[cnt]);
		if (cnt < 15)
			mlx_delete_texture(data->player[cnt]);
		cnt++;
	}
	mlx_delete_texture(data->ground);
	mlx_delete_image(data->mlx, data->wall_img[cnt]);
	mlx_delete_image(data->mlx, data->temp_img);
	mlx_delete_texture(data->coins);
	if (data->coins_img != NULL)
		mlx_delete_image(data->mlx, data->coins_img);
	free_data(data);
	free(data->map);
	free(data->name);
	mlx_terminate(data->mlx);
	free(data);
}

void	free_data(t_data *data)
{
	mlx_delete_texture(data->exit[0]);
	mlx_delete_texture(data->exit[1]);
	mlx_delete_image(data->mlx, data->exit_img[0]);
	mlx_delete_image(data->mlx, data->exit_img[1]);
}
