/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:50:33 by kvebers           #+#    #+#             */
/*   Updated: 2022/12/30 18:46:31 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int protection(char *argv)
{
    t_check *data;

    data = malloc(sizeof(t_data));
	if (data == NULL)
		return 0;
    if (check_name(argv) == 0)
        return (free(data), 0);
    data->name = ft_strjoin("./maps/",argv);
	data->width = calculate_width(data->name);
	data->height = calculate_height(data->name);
	data->map = create_name(data->name);
	data->height = calculate_height(data->name);
    if (check_chars(data) == 0)
        return(free(data->name), free(data->map), free(data), 0);
	data->x = init_x(data->width, data->map);
	data->y = init_y(data->width, data->map);
    if (check_must_have(data) == 0)
        return(free(data->name), free(data->map), free(data), 0);
    return(free(data->name), free(data->map), free(data), 1);
}

int check_name(char *argv)
{
    int len;
    
    len = ft_strlen(argv);
    if (*(argv + len - 1) == 'r' &&
        *(argv + len - 2) == 'e' &&
        *(argv + len - 3) == 'b' &&
        *(argv + len - 4) == '.')
        return (1);
    ft_printf("\nError: The map should have .ber format\n");
    return (0);
}

int check_chars(t_check *data)
{
    int cnt;

    cnt = 0;

    char *allowed = "\nP01EC";
    while (data->map[cnt] != '\0')
    {
        if (ft_strchr2(allowed, data->map[cnt]) == NULL)
        {
            ft_printf("\nError: Not allowed char: %c", data->map[cnt]);
            ft_printf(", At cordinates: X: %i ", cnt % data->width);
            ft_printf("Y: %i\n\n", cnt / data->width);
            return (0);
        }
        cnt++;
    }
    return (1);
}

int check_must_have(t_check *data)
{
    if (ft_strchr2(data->map, 'C') == NULL ||
        ft_strchr2(data->map, 'E') == NULL ||
        ft_strchr2(data->map, 'P') == NULL)
    {
        printf("\nError: There is not a single C, E or P Char in the map\n");
        return (0);
    }
    return (1);
}