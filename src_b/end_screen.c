/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:03:49 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/05 16:32:05 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	play_endscreen(int game_state)
{
	t_miniani	*data;

	data = malloc(sizeof(t_miniani));
	data->mlx = mlx_init(512, 512, "End", false);
	data->game_state = game_state;
	data->frames = 0;
	if (game_state == 1)
		play_win(data);
	if (game_state == 2)
		play_void(data);
	if (game_state == 3)
		play_killed(data);
	if (game_state == 4)
		play_explosion(data);
	free(data);
}

void	play_win(t_miniani *data)
{
	data->ani[0] = mlx_load_png("./textures/end_screen/win1.png");
	data->ani[1] = mlx_load_png("./textures/end_screen/win2.png");
	data->ani[2] = mlx_load_png("./textures/end_screen/win3.png");
	data->ani_i = mlx_texture_to_image(data->mlx, data->ani[0]);
	mlx_loop_hook(data->mlx, &count_frames1, data);
	mlx_key_hook(data->mlx, &keyhook1, data->mlx);
	mlx_loop(data->mlx);
	mlx_delete_texture(data->ani[0]);
	mlx_delete_texture(data->ani[1]);
	mlx_delete_texture(data->ani[2]);
}

void	play_killed(t_miniani *data)
{
	data->ani[0] = mlx_load_png("./textures/end_screen/stab1.png");
	data->ani[1] = mlx_load_png("./textures/end_screen/stab2.png");
	data->ani[2] = mlx_load_png("./textures/end_screen/stab3.png");
	data->ani_i = mlx_texture_to_image(data->mlx, data->ani[0]);
	mlx_loop_hook(data->mlx, &count_frames1, data);
	mlx_key_hook(data->mlx, &keyhook1, data->mlx);
	mlx_loop(data->mlx);
	mlx_delete_texture(data->ani[0]);
	mlx_delete_texture(data->ani[1]);
	mlx_delete_texture(data->ani[2]);
}

void	play_void(t_miniani *data)
{
	data->ani[0] = mlx_load_png("./textures/end_screen/fell1.png");
	data->ani[1] = mlx_load_png("./textures/end_screen/fell2.png");
	data->ani[2] = mlx_load_png("./textures/end_screen/fell3.png");
	data->ani_i = mlx_texture_to_image(data->mlx, data->ani[0]);
	mlx_loop_hook(data->mlx, &count_frames1, data);
	mlx_key_hook(data->mlx, &keyhook1, data->mlx);
	mlx_loop(data->mlx);
	mlx_delete_texture(data->ani[0]);
	mlx_delete_texture(data->ani[1]);
	mlx_delete_texture(data->ani[2]);
}

void	play_explosion(t_miniani *data)
{
	data->ani[0] = mlx_load_png("./textures/end_screen/blew1.png");
	data->ani[1] = mlx_load_png("./textures/end_screen/blew2.png");
	data->ani[2] = mlx_load_png("./textures/end_screen/blew3.png");
	data->ani_i = mlx_texture_to_image(data->mlx, data->ani[0]);
	mlx_loop_hook(data->mlx, &count_frames1, data);
	mlx_key_hook(data->mlx, &keyhook1, data->mlx);
	mlx_loop(data->mlx);
	mlx_delete_texture(data->ani[0]);
	mlx_delete_texture(data->ani[1]);
	mlx_delete_texture(data->ani[2]);
}
