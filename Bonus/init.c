/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:34:22 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/20 16:38:09 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	init_gun_and_mouse(t_data *data)
{
	data->mouse_on = 1;
	data->mouse_1 = 0;
	data->mouse_2 = 0;
	data->b_img.texture = NULL;
	data->change = 0;
	data->gun.frame = 0;
	data->gun.bullets = 5;
	data->gun.fired = 0;
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
	int tmp;

	init_gun_and_mouse(data);
	load_frames(data);
	data->mini_map.map_content = data->map;
	printf("%d %d\n", data->mini_map.map_width, data->mini_map.map_height);
	data->mini_map.full_map.texture = mlx_new_image(data->ml, data->mini_map.map_width, data->mini_map.map_height);
	data->mini_map.full_map.info = mlx_get_data_addr(data->mini_map.full_map.texture,&data->mini_map.full_map.bits,&data->mini_map.full_map.line_len,&data->mini_map.full_map.endian);
	data->mini_map.part_map.texture = NULL;
	data->mini_map.icon = mlx_png_file_to_image(data->ml,"./textures/loading/circle.png",&tmp, &tmp);
	draw_map(&data->mini_map);
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

void	init_doors_and_enemys(t_data *data)
{
	if (data->number_d)
	{
		data->d = malloc(sizeof(t_door) * data->number_d);
		if (!data->d)
			ft_error("malloc faild :{");
	}
	if (data->number_e)
	{
		data->enemys = malloc(sizeof(t_enemy) * data->number_e);
		if (!data->enemys)
			ft_error("malloc faild :{");
	}
}

void	more_keys(t_data *data)
{
	if (data->key_bord[ESC])
		ft_clean(data);
	if (data->key_bord[MOUSE_ON_OFF])
	{
		mlx_mouse_show();
		data->mouse_on = 0;
	}
}
