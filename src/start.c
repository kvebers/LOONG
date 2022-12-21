/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:42:20 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/20 16:16:26 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


char	*create_map(char *name)
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

int	init_map(t_data *data)
{
	
ft_printf("%i",data->x);
data->x = 5;
ft_printf("%i", data->x);
return (0);
}

int init_game(char *argv)
{
	t_data		*data;
	t_textures	*textures;
	
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return 0;
	data->name = ft_strjoin("./maps/",argv);
	data->width = calculate_width(data->name);
	data->height = calculate_height(data->name);
	data->map = create_map(data->name);
	data->height = calculate_height(data->name);
	data->x = init_x(data->width, data->map);
	data->y = init_y(data->width, data->map);
	data->mlx = mlx_init((data->width - 1) * 60, data->height * 85, "Card Game", false);
	textures = init_textures(0);
	init_map(data);
	//free_data_textures(data, textures);
	return (free(data->map), free(data->name), free(data), 0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
    {
		return (0);
    }
	else
	{
		init_game(argv[1]);
	}
	system("leaks so_long");
//	system("leaks bonus");
	return (0);
}