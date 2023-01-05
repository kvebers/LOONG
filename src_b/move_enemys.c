/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 06:28:47 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/05 17:16:40 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_enemy_state_2(t_data *d)
{
	if (d->fra % 700 == 680)
	{
		mlx_delete_image(d->mlx, d->e_img2[7]);
		mlx_texture_to_image(d->mlx, d->enemy[7]);
		render_enemys1(d, 8, '3');
	}	
	if (d->fra % 700 == 685)
	{
		mlx_delete_image(d->mlx, d->e_img2[8]);
		mlx_texture_to_image(d->mlx, d->enemy[8]);
		render_enemys1(d, 9, '3');
		count_enemys(d, '3', '2');
		render_holes(d);
	}
	if (d->fra % 700 == 690)
	{
		mlx_delete_image(d->mlx, d->e_img2[9]);
		mlx_texture_to_image(d->mlx, d->enemy[9]);
		render_enemys1(d, 10, '3');
	}
	check_enemy_state_3(d);
}

void	check_enemy_state1(t_data *d)
{
	if (d->fra % 700 == 660)
	{
		mlx_delete_image(d->mlx, d->e_img2[3]);
		mlx_texture_to_image(d->mlx, d->enemy[3]);
		render_enemys1(d, 4, 'N');
	}
	if (d->fra % 700 == 665)
	{
		mlx_delete_image(d->mlx, d->e_img2[4]);
		mlx_texture_to_image(d->mlx, d->enemy[4]);
		count_enemys(d, 'N', '3');
	}
	if (d->fra % 700 == 670)
	{
		render_enemys1(d, 6, '3');
	}
	if (d->fra % 700 == 675)
	{
		mlx_delete_image(d->mlx, d->e_img2[6]);
		mlx_texture_to_image(d->mlx, d->enemy[6]);
		render_enemys1(d, 7, '3');
	}
	check_enemy_state_2(d);
}

void	check_enemy_state(t_data *d)
{
	if (d->fra % 700 == 0 || d->fra % 700 == 2)
		render_enemys(d, 0);
	if (d->fra % 3 == 0 && d->fra % 700 < 650)
		render_enemys(d, 1);
	if (d->fra % 700 > 550 && d->fra % 7 == 0 && d->fra % 700 < 650)
		change_map(d, 0, 0, 0);
	if (d->fra % 700 == 651)
	{
		mlx_delete_image(d->mlx, d->e_img2[0]);
		mlx_delete_image(d->mlx, d->e_img2[1]);
		mlx_texture_to_image(d->mlx, d->enemy[11]);
		mlx_texture_to_image(d->mlx, d->enemy[12]);
		render_enemys1(d, 2, 'N');
	}
	if (d->fra % 700 == 654)
	{
		mlx_delete_image(d->mlx, d->e_img2[2]);
		mlx_texture_to_image(d->mlx, d->enemy[2]);
		render_enemys1(d, 3, 'N');
	}
	check_enemy_state1(d);
}

void	render_enemys1(t_data *d, int add, int c)
{
	int	cnt;
	int	x;
	int	y;
	int	n;

	n = d->fra % 2;
	cnt = 0;
	mlx_delete_image(d->mlx, d->e_img2[add]);
	d->e_img2[add] = mlx_texture_to_image(d->mlx, d->enemy[add]);
	while (d->map[cnt] != '\0')
	{
		if (add < 6)
		{
			x = cnt % d->width * 60 + 20;
			y = cnt / d->width * 84 + 30;
		}
		else
		{
			x = cnt % d->width * 60;
			y = cnt / d->width * 84;
		}
		if (d->map[cnt] == c)
			mlx_image_to_window(d->mlx, d->e_img2[add], x, y);
		cnt++;
	}
}

void	count_enemys(t_data *d, int former, int future)
{
	int	cnt;
	int	enemys;

	cnt = 0;
	enemys = 0;
	while (d->map[cnt] != '\0')
	{
		if (d->map[cnt] == former)
		{
			enemys++;
			d->map[cnt] = future;
		}
		cnt++;
	}
	d->enemy_count = enemys;
}
