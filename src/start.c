/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:42:20 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/30 10:22:12 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_game(t_data *data)
{
	init_map(data);
	init_coins(data);
	update_gates(data);
	init_player(data);
	mlx_key_hook(data->mlx, &keyhook, data);
//	mlx_loop_hook(data->mlx, &count_frames, data);
	mlx_loop_hook(data->mlx, &update_player, data);
	mlx_loop(data->mlx);
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