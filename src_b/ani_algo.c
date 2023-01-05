/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ani_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:29:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/05 17:17:41 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ani_algo(t_data *data)
{
	if (data->ani != 0)
		data->ani--;
	if (data->x_off < 0)
		data->x_off = data->x_off + 5;
	else if (data->x_off > 0)
		data->x_off = data->x_off - 5;
	else
		data->x_off = 0;
	if (data->y_off < 0)
		data->y_off = data->y_off + 7;
	else if (data->y_off > 0)
		data->y_off = data->y_off - 7;
	else
		data->y_off = 0;
	if (data -> ani == 1)
		data->frames = 0;
	ani_predictor(data);
}

void	ani_predictor(t_data *data)
{
	if (data->ani != 0 && data->x_off < 0)
		data->ani_spr = data->ani % 2 + 7;
	else if (data->ani != 0 && data->x_off > 0)
		data->ani_spr = data->ani % 2 + 4;
	else if (data->ani != 0 && data->y_off < 0)
		data->ani_spr = data->ani % 2;
	else if (data->ani != 0 && data->y_off > 0)
		data->ani_spr = data->ani % 2 + 2;
	else if (data->frames > 50 && data->ani == 0)
		data->ani_spr = data->frames % 5 + 10;
	if (data->ani == 9)
		render_holes(data);
	if (data->ani == 10)
		render_holes(data);
	if (data->game_state != 0 && data->ani == 3)
		mlx_close_window(data->mlx);
}
