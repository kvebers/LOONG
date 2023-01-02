/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ani_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:29:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/02 19:23:53 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void    ani_algo(t_data *data)
{
    if (data->ani != 0)
        data->ani--;
    if (data->x_off < 0)
        data->x_off = data->x_off + 5;
    else if (data->x_off > 0)
        data->x_off = data->x_off - 5;
    else 
        data->x_off = 0;
    if (data->y_off < 0)
        data->y_off = data->y_off + 7;
    else if (data->y_off > 0)
        data->y_off = data->y_off - 7;
    else 
        data->y_off = 0;
}