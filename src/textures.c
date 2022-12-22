/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:17:17 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/22 19:13:31 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_texture_t *wall_texture(int cnt)
{
	mlx_texture_t *texture;
	char *card;
	char *card1;
	char *card2;
	
	card = ft_itoa(cnt);
	card1 = ft_strjoin("./textures/", card);
	free(card);
	card2 = ft_strjoin(card1, ".png");
	free(card1);
	texture = mlx_load_png(card2);
	return (free(card2), texture);
}

mlx_image_t *wall_img(mlx_t *mlx, mlx_texture_t *texture)
{
	mlx_image_t *image;
	image = mlx_texture_to_image(mlx, texture);
	return (image);
}

void	init_textures(t_data *data, int cnt)
{
	while (cnt++ < 52)
	{
		data -> wall[cnt - 1] = wall_texture(cnt);
		data -> wall_img[cnt - 1] = wall_img(data->mlx, data->wall[cnt - 1]);
	}
	cnt = 0;
	data->ground = mlx_load_png("./textures/basic.png");
	data->ground_img = mlx_texture_to_image(data->mlx, data->ground);
}
