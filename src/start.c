/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:42:20 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/23 12:50:40 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	keyhook(void *func)
// {
// 	t_data *data;
// 	data = func;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(data->mlx);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
// 		ft_printf("%i\n", data->x);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
// 		ft_printf("%i\n", data->x);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
// 		ft_printf("%i\n", data->x);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
// 		ft_printf("%i\n", data->x);
// }

void	my_keyhook(mlx_key_data_t key_data, void *param)
{
	t_data *data;
	
	data = (t_data*)param;
	if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
		data -> y = data -> y + 1;
	if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS)
		data -> y = data -> y - 1;
	if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS)
		data -> x = data -> x + 1;
	if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS)
		data -> x = data -> x - 1;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}

void	test1(void *param)
{
	t_data	*data;

	data = param;
	ft_printf("%i\n", data->x);
}

void	start_game(t_data *data)
{
//	mlx_loop_hook();

	init_map(data);
	mlx_key_hook(data->mlx, &my_keyhook, data);
	mlx_loop_hook(data->mlx, &test1, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}

int	main(int argc, char **argv)
{
	//system("afplay ./Music/mafia.mp3 &");
	// system("killall say");
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
//	system("killall afplay");
	return (0);
}