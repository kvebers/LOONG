/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:16:59 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/30 12:02:51 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*oof(t_data *data, int cnt)
{
	return (data->wall_img[(cnt * 11001 + 12345) % 26]);
}

void init_player(t_data *d)
{
	d->temp_img = mlx_texture_to_image(d->mlx, d->player[0]);
	mlx_image_to_window(d->mlx, d->temp_img, d->x * 60 + 15, d->y * 84 + 30);
}

void init_map(t_data *d)
{
	int x;
	int y;
	int cnt;

	cnt = 0;
	y = 0;
	x = 0;
	while(y < d->height)
	{
		x = 0;
		while(x < d->width)
		{
			if (d->map[cnt] == '1')
			{
				mlx_image_to_window(d->mlx, oof(d, cnt), x * 60, y * 84);
			}
			else if(d->map[cnt] == '\n' || d->map[cnt] == 'E')
			{
			}
			else
				mlx_image_to_window(d->mlx, d->ground_img, x * 60, y  * 84);
			x++;
			cnt++;
		}
		y++;
	}
}

char	*create_name(char *name)
{
	int fd2;
	char *line;
	char *temp;
	
	temp = malloc(sizeof(char));
	fd2 = open(name, O_RDONLY);
	line = get_next_line(fd2);
	while(line != NULL)
	{
		temp = ft_strjoin3(temp, line);
		line = get_next_line(fd2);
	}
	close(fd2);
	free(line);
	return (temp);
}

int init_game(char *argv)
{
	t_data		*data;
	
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return 0;
	data->name = ft_strjoin("./maps/",argv);
	data->width = calculate_width(data->name);
	data->height = calculate_height(data->name);
	data->map = create_name(data->name);
	data->height = calculate_height(data->name);
	data->x = init_x(data->width, data->map);
	data->y = init_y(data->width, data->map);
	data->mlx = mlx_init((data->width - 1) * 60, data->height * 84, "Those are my jokes lad", false);
	data->frames = 0;
	data->turn_counter = 0;
	init_textures(data, 0);
	start_game(data);
	free_data_textures(data);
	return (0);
}