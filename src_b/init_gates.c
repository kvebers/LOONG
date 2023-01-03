/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:10:03 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/03 18:38:07 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_coins(t_data *d)
{
	int	cnt;
	int	x;
	int	y;
	int	coins;

	coins = 0;
	cnt = 0;
	while (d->map[cnt] != '\0')
	{
		x = cnt % d->width;
		y = cnt / d->width;
		if (d->map[cnt] == 'C')
		{
			mlx_image_to_window(d->mlx, d->coins_img, x * 60, y * 84);
			coins++;
		}
		cnt++;
	}
	d->value = coins;
	if (coins == 0)
		update_gates(d);
}

void	update_gates(t_data *d)
{
	int	cnt;
	int	x;
	int	y;

	cnt = 0;
	while (d->map[cnt] != 'E')
		cnt++;
	x = cnt % d->width;
	y = cnt / d->width;
	if (d->value > 0)
		mlx_image_to_window(d->mlx, d->exit_img[0], x * 60, y * 84);
	else
		mlx_image_to_window(d->mlx, d->exit_img[1], x * 60, y * 84);
}

void	check_win(t_data *data, int x, int y)
{
	if (data->value == 0)
	{
		if (data->map[y * data->width + x] == 'E')
			data->game_state = 1;
	}
}
