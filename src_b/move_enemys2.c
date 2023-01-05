/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemys2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:51:31 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/05 13:25:57 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_enemy_state_3(t_data *d)
{
	if (d->fra % 700 == 690)
	{
		mlx_delete_image(d->mlx, d->e_img2[10]);
		mlx_texture_to_image(d->mlx, d->enemy[10]);
		while (d->enemy_count > 0)
			generate_enemys(d);
		check_lose(d, d->x, d->y);
	}
}

int	count_tiles(t_data *d)
{
	int	tiles;
	int	cnt;

	tiles = 0;
	cnt = 0;
	while (d->map[cnt] != '\0')
	{
		if (d->map[cnt] == '0')
			tiles++;
		cnt++;
	}
	return (tiles);
}

void	generate_enemys(t_data *d)
{
	int	cnt;
	int	tiles;
	int	other_tiles;

	tiles = count_tiles(d);
	if (d->enemy_count > tiles)
		d->enemy_count = tiles;
	other_tiles = rand() % tiles + 1;
	tiles = 0;
	cnt = 0;
	while (tiles != other_tiles && d->map[cnt] != '\0')
	{
		if (d->map[cnt] == '0')
			tiles++;
		cnt++;
	}
	if (d->map[cnt - 1] == '0')
		d->map[cnt - 1] = 'N';
	d->enemy_count--;
}
