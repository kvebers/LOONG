/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:17:17 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/01 19:12:01 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

mlx_texture_t	*wall_texture(int cnt)
{
	mlx_texture_t	*texture;
	char			*card;
	char			*card1;
	char			*card2;

	card = ft_itoa(cnt);
	card1 = ft_strjoin("./textures/walls/", card);
	free(card);
	card2 = ft_strjoin(card1, ".png");
	free(card1);
	texture = mlx_load_png(card2);
	return (free(card2), texture);
}

mlx_image_t	*wall_img(mlx_t *mlx, mlx_texture_t *texture)
{
	mlx_image_t	*image;

	image = mlx_texture_to_image(mlx, texture);
	return (image);
}

void	init_textures(t_data *data, int cnt)
{
	while (cnt++ < 26)
	{
		data -> wall[cnt - 1] = wall_texture(cnt);
		data -> wall_img[cnt - 1] = wall_img(data->mlx, data->wall[cnt - 1]);
	}
	cnt = 0;
	data->ground = mlx_load_png("./textures/walls/basic.png");
	data->ground_img = mlx_texture_to_image(data->mlx, data->ground);
	data->coins = mlx_load_png("./textures/coins/coin.png");
	data->coins_img = mlx_texture_to_image(data->mlx, data->coins);
	init_stats_textures(data);
	player_textures(data);
	
}

void	player_textures(t_data *data)
{
	data->player[0] = mlx_load_png("./textures/player/S_Walk1.png");
	data->player[1] = mlx_load_png("./textures/player/S_Walk2.png");
	data->player[2] = mlx_load_png("./textures/player/W_Walk1.png");
	data->player[3] = mlx_load_png("./textures/player/W_Walk2.png");
	data->player[4] = mlx_load_png("./textures/player/A_Walk1.png");
	data->player[5] = mlx_load_png("./textures/player/A_Walk2.png");
	data->player[6] = mlx_load_png("./textures/player/A_Walk3.png");
	data->player[7] = mlx_load_png("./textures/player/D_Walk1.png");
	data->player[8] = mlx_load_png("./textures/player/D_Walk2.png");
	data->player[9] = mlx_load_png("./textures/player/D_Walk3.png");
	data->player[10] = mlx_load_png("./textures/player/Idle1.png");
	data->player[11] = mlx_load_png("./textures/player/Idle2.png");
	data->player[12] = mlx_load_png("./textures/player/Idle3.png");
	data->player[13] = mlx_load_png("./textures/player/Idle4.png");
	data->player[14] = mlx_load_png("./textures/player/Idle5.png");
	data->exit[0] = mlx_load_png("./textures/walls/basic3.png");
	data->exit_img[0] = mlx_texture_to_image(data->mlx, data->exit[0]);
	data->exit[1] = mlx_load_png("./textures/walls/basic2.png");
	data->exit_img[1] = mlx_texture_to_image(data->mlx, data->exit[1]);
}
