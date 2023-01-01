/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:16:59 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/01 18:35:47 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

mlx_image_t	*oof(t_data *data, int cnt)
{
	return (data->wall_img[(cnt * 11001 + 12345) % 26]);
}

void	init_player(t_data *d)
{
	d->temp_img = mlx_texture_to_image(d->mlx, d->player[0]);
	mlx_image_to_window(d->mlx, d->temp_img, d->x * 60 + 15, d->y * 84 + 30);
}

void	init_map(t_data *d, int cnt, int x, int y)
{
	while (y < d->height)
	{
		x = 0;
		while (x < d->width)
		{
			if (d->map[cnt] == '1')
				mlx_image_to_window(d->mlx, oof(d, cnt), x * 60, y * 84);
			else if (d->map[cnt] == '\n' || d->map[cnt] == 'E')
			{
			}
			else
				mlx_image_to_window(d->mlx, d->ground_img, x * 60, y * 84);
			x++;
			cnt++;
		}
		y++;
	}
}

char	*create_name(char *name)
{
	int		fd2;
	char	*line;
	char	*temp;

	temp = malloc(sizeof(char));
	fd2 = open(name, O_RDONLY);
	line = get_next_line(fd2);
	while (line != NULL)
	{
		temp = ft_strjoin3(temp, line);
		line = get_next_line(fd2);
	}
	close(fd2);
	free(line);
	return (temp);
}

int	init_game(char *argv)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (d == NULL)
		return (0);
	d->name = ft_strjoin("./maps/", argv);
	d->width = calculate_width(d->name);
	d->height = calculate_height(d->name);
	d->map = create_name(d->name);
	d->height = calculate_height(d->name);
	d->x = init_x(d->width, d->map);
	d->y = init_y(d->width, d->map);
	d->mlx = mlx_init((d->width + 4) * 60, d->height * 84, "NabJokes", false);
	d->frames = 0;
	d->turn_counter = 0;
	init_textures(d, 0);
	start_game(d);
	free_data_textures(d);
	return (0);
}
