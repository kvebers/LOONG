/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:42:20 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/22 19:19:51 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_game(t_data *data)
{
//	mlx_loop_hook();

	init_map(data);
//	mlx_key_hook
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