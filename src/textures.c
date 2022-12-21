/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:17:17 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/20 16:29:04 by kvebers          ###   ########.fr       */
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

mlx_image_t *wall_img(mlx_texture_t *texture)
{
	mlx_image_t image;
	image = mlx_texture_to_image(texture);
	return (image);
}

t_textures	*init_textures(t_data *data, int cnt)
{
	t_textures	*textures;

	ft_printf("%i", cnt);
	textures = malloc(sizeof(t_textures));
	while (cnt++ < 53)
	{
		textures -> wall[cnt - 1] = wall_texture(cnt);
		textures -> wall_img[cnt - 1] = wall_img(data -> mlx, textures->wall[cnt - 1]);
	}
	
	return(textures);
}
