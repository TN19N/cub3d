/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:34:22 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/17 13:32:40 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	init_gun_and_mouse(t_data *data)
{
	data->mouse_1 = 0;
	data->mouse_2 = 0;
	data->pitch = 0;
	data->gun.current_img = NULL;
	data->b_img.texture = NULL;
	data->change = 0;
	data->gun.fire_index = 50;
	data->gun.fired = 0;
	data->gun.reload_index = 50;
	data->gun.gun_reload = 0;
}

void	init_2(t_data *data)
{
	if (data->pl.spawning == 'N')
	{
		data->pl.plane_x = 0.0;
		data->pl.plane_y = -0.66;
		data->pl.dir_x = 1.0;
		data->pl.dir_y = 0.0;
	}
	else if (data->pl.spawning == 'S')
	{
		data->pl.plane_x = -0.66;
		data->pl.plane_y = 0.0;
		data->pl.dir_x = 0.0;
		data->pl.dir_y = -1.0;
	}
}

void	init_1(t_data *data)
{
	init_gun_and_mouse(data);
	if (data->pl.spawning == 'E')
	{
		data->pl.plane_x = 0.0;
		data->pl.plane_y = 0.66;
		data->pl.dir_x = -1.0;
		data->pl.dir_y = 0.0;
	}
	if (data->pl.spawning == 'W')
	{
		data->pl.plane_x = 0.66;
		data->pl.plane_y = 0.0;
		data->pl.dir_x = 0.0;
		data->pl.dir_y = 1.0;
	}
	init_2(data);
}