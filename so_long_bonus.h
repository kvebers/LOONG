/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:00:31 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/02 19:13:53 by kvebers          ###   ########.fr       */
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

typedef struct data
{
	mlx_t			*mlx;
	char			*name;
	int				width;
	int				height;
	char			*map;
	int				x;
	int				y;
	int				turn_counter;
	int				turns;
	int				value;
	int				frames;
	int				ani;
	int				y_off;
	int				x_off;
	mlx_texture_t	*ground;
	mlx_texture_t	*wall[26];
	mlx_texture_t	*enemy[10];
	mlx_texture_t	*player[15];
	mlx_texture_t	*exit[2];
	mlx_texture_t	*points[10];
	mlx_texture_t	*coins;
	mlx_texture_t	*stats[4];
	mlx_image_t		*coins_img;
	mlx_image_t		*ground_img;
	mlx_image_t		*wall_img[28];
	mlx_image_t		*exit_img[2];
	mlx_image_t		*temp_img;
	mlx_image_t		*stats_img[4];
	mlx_image_t		*p_i[5];
}	t_data;

typedef struct check
{
	char	*name;
	int		width;
	int		height;
	char	*map;
	int		x;
	int		y;
}	t_check;
//Utills.c
int				calculate_width(char *name);
int				calculate_height(char *name);
char			*ft_strjoin3(char *s1, char *s2);
int				init_y(int width, char *map);
int				init_x(int width, char *map);
//textures.c
void			init_textures(t_data *data, int cnt);
mlx_texture_t	*wall_texture(int cnt);
void			player_textures(t_data *data);
//init.c
void			init_map(t_data *data, int cnt, int x, int y);
int				init_game(char *argv);
mlx_image_t		*oof(t_data *data, int cnt);
char			*create_name(char *name);
void			init_player(t_data *data);
//Keyhooks
void			keyhook(mlx_key_data_t key_data, void *param);
void			update_player(void *param);
void			count_frames(void *param);

//key.c
void			pressed_w(t_data *data);
void			pressed_s(t_data *data);
void			pressed_d(t_data *data);
void			pressed_a(t_data *data);
void			render_coins(t_data *data);
// init_gatess.c
void			init_coins(t_data *data);
void			init_gates(t_data *data);
void			update_gates(t_data *d);
void			check_win(t_data *data, int x, int y);
//protection.c
int				protection(char *argv);
int				check_name(char *argv);
int				check_chars(t_check *data);
int				check_must_have(t_check *data);
int				surrounded_by_walls(t_check *data, int cnt, int error);
//protection2.c
int				check_rec(t_check *data, int cnt);
int				check_path_setup(t_check *data);
//free.c
void			free_data_textures(t_data *data);
void			free_data(t_data *data);
//start.c
void			start_game(t_data *data);
//point_counter.c
void			init_stats_textures(t_data *data);
void			init_stats(t_data *data);
void			long_line(t_data *data, int x, int y);
void			long_line_2 (t_data *d, int x, int y);
void			long_line_1 (t_data *d, int x);
// stats_algo.c
void    		stats_algo(t_data *d);
//ani_algo.c
void    		ani_algo(t_data *data);
#endif
