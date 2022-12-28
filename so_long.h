/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:11:52 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/28 12:43:45 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <memory.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>
# include "./MLX42/include/MLX42/MLX42.h"

// typedef struct textures
// {
// 	mlx_texture_t 	*ground;
// 	mlx_texture_t	*wall[52];
// 	mlx_texture_t	*enemy[10];
// 	mlx_texture_t	*player[10];
// 	mlx_texture_t	*exit;
// 	mlx_image_t		*ground_img;
// 	mlx_image_t		*wall_img[52];
// 	mlx_image_t		*enemy_img[10];
// 	mlx_image_t		*player_img[10];
// 	mlx_image_t		*exit_img;
// }	t_textures;

typedef struct data
{
	mlx_t	*mlx;
	char	*name;
	int		width;
	int		height;
	char	*map;
    int		x;
    int		y;
	int		turn_counter;
	int		turns;
	mlx_texture_t 	*ground;
	mlx_texture_t	*wall[52];
	mlx_texture_t	*enemy[10];
	mlx_texture_t	*player[15];
	mlx_texture_t	*exit;
	mlx_image_t		*ground_img;
	mlx_image_t		*wall_img[52];
	mlx_image_t		*exit_img;
	mlx_image_t		*temp_img;
	char			last_key;
	int				frames;
	
	
}	t_data;

//Utills.c
int				calculate_width(char *name);
int				calculate_height(char *name);
char			*ft_strjoin3(char *s1, char *s2);
int				init_y(int width, char *map);
int				init_x(int width, char *map);

void			init_textures(t_data *data, int cnt);
mlx_texture_t	*wall_texture(int cnt);
void			free_data_textures(t_data *data);

void			init_map(t_data *data);
int				init_game(char *argv);
mlx_image_t		*oof(t_data *data, int cnt);
char			*create_name(char *name);
void			start_game(t_data *data);
void			init_player(t_data *data);
void			player_textures(t_data *data);


//Keyhooks
void	keyhook(mlx_key_data_t key_data, void *param);
void	count_frames(void *param);
void	update_player(void *param);

void	pressed_w(t_data *data);
void	pressed_s(t_data *data);
void	pressed_d(t_data *data);
void	pressed_a(t_data *data);


#endif
