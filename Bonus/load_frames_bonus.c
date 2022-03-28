/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_frames.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:38:49 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/19 15:06:35 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	load_zombie_frames(t_data *data, void **ptr, int i, int type)
{
	char	c[40];

	if (type == 4)
	{
		file_name(c, "textures/zombie/walk/", i + 1);
		*ptr = mlx_png_file_to_image(data->ml, c, \
			&data->zombie.walk_frames[i].width, \
			&data->zombie.walk_frames[i].hight);
	}
	else if (type == 5)
	{
		file_name(c, "textures/zombie/death/", i + 1);
		*ptr = mlx_png_file_to_image(data->ml, c, \
			&data->zombie.death_frames[i].width, \
			&data->zombie.death_frames[i].hight);
	}
	else if (type == 6)
	{
		file_name(c, "textures/zombie/attack/", i + 1);
		*ptr = mlx_png_file_to_image(data->ml, c, \
			&data->zombie.attack_frames[i].width, \
			&data->zombie.attack_frames[i].hight);
	}
}

void	load_the_img(t_data *data, void **ptr, int i, int type)
{
	int		tmp;
	char	c[40];

	if (type == 1)
		file_name(c, "textures/gun/fire/", i + 1);
	else if (type == 2)
		file_name(c, "textures/gun/bullet/", i + 1);
	else if (type == 3)
		file_name(c, "textures/gun/reload/", i + 1);
	load_zombie_frames(data, ptr, i, type);
	if (type < 4)
		ptr[i] = mlx_png_file_to_image(data->ml, c, &tmp, &tmp);
	if ((type < 4 && !ptr[i]) || (!*ptr && (type > 3)))
		ft_error("can't open png for frames");
}

void	fill_zombie_frames(t_data *data, int i, int tmp)
{
	if (i < 121)
	{
		load_the_img(data, &data->zombie.walk_frames[i].texture, i, 4);
		data->zombie.walk_frames[i].info = \
			mlx_get_data_addr(data->zombie.walk_frames[i].texture, \
			&data->zombie.walk_frames[i].bits, \
			&data->zombie.walk_frames[i].line_len, &tmp);
	}
	if (i < 90)
	{
		load_the_img(data, &data->zombie.death_frames[i].texture, i, 5);
		data->zombie.death_frames[i].info = \
			mlx_get_data_addr(data->zombie.death_frames[i].texture, \
			&data->zombie.death_frames[i].bits, \
			&data->zombie.death_frames[i].line_len, &tmp);
	}
	if (i < 65)
	{
		load_the_img(data, &data->zombie.attack_frames[i].texture, i, 6);
		data->zombie.attack_frames[i].info = \
			mlx_get_data_addr(data->zombie.attack_frames[i].texture, \
			&data->zombie.attack_frames[i].bits, \
			&data->zombie.attack_frames[i].line_len, &tmp);
	}
}

void	start_filling(t_data *data)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < 128)
	{
		if (i < 14)
			load_the_img(data, data->gun.fire_frames, i, 1);
		if (i < 5)
			load_the_img(data, data->gun.bullets_frames, i, 2);
		load_the_img(data, data->gun.reload_frames, i, 3);
		fill_zombie_frames(data, i, 0);
		i++;
	}
	data->gun.cursor = \
		mlx_png_file_to_image(data->ml, \
			"textures/gun/fire/cursor.png", &tmp, &tmp);
	if (!data->gun.cursor)
		ft_error("can't open png for frames");
	data->mini_map.icon = mlx_png_file_to_image(data->ml, \
		"./textures/loading/circle.png", &tmp, &tmp);
	if (!data->mini_map.icon)
		ft_error("can't open png for frames");
}

void	load_frames(t_data *data)
{
	int	tmp;

	data->gun.fire_frames = malloc(14 * sizeof(void *));
	if (!data->gun.fire_frames)
		ft_error("malloc faild :(");
	data->gun.reload_frames = malloc(129 * sizeof(void *));
	if (!data->gun.reload_frames)
		ft_error("malloc faild :(");
	data->gun.bullets_frames = malloc(5 * sizeof(void *));
	if (!data->gun.bullets_frames)
		ft_error("malloc faild :(");
	data->zombie.walk_frames = malloc(121 * sizeof(t_texture));
	if (!data->zombie.walk_frames)
		ft_error("malloc faild :(");
	data->zombie.death_frames = malloc(90 * sizeof(t_texture));
	if (!data->zombie.death_frames)
		ft_error("malloc faild :(");
	data->zombie.attack_frames = malloc(65 * sizeof(t_texture));
	if (!data->zombie.attack_frames)
		ft_error("malloc faild :(");
	start_filling(data);
	data->gun.idle_frame = \
	mlx_png_file_to_image(data->ml, "textures/gun/fire/idle.png", &tmp, &tmp);
	if (!data->gun.idle_frame)
		ft_error("can't open png for frames");
}
