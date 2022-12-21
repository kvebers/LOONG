/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:11:52 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/20 16:34:04 by kvebers          ###   ########.fr       */
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



typedef struct textures
{
	mlx_texture_t 	*ground;
	mlx_texture_t	*wall[52];
	mlx_texture_t	*enemy[10];
	mlx_texture_t	*player[10];
	mlx_texture_t	*exit;
	mlx_image_t		*ground_img;
	mlx_image_t		*wall_img[52];
	mlx_image_t		*enemy_img[10];
	mlx_image_t		*player_img[10];
	mlx_image_t		*exit_img;
}	t_textures;

typedef struct data
{
	mlx_t	*mlx;
	char	*name;
	int		width;
	int		height;
	char	*map;
    char    x;
    char    y;
}	t_data;
//Utills.c
t_textures		*init_textures(int cnt);
int				calculate_width(char *name);
int				calculate_height(char *name);
char			*ft_strjoin3(char *s1, char *s2);
int				init_y(int width, char *map);
int				init_x(int width, char *map);
mlx_texture_t	*wall_texture(int cnt);

#endif