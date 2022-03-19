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
	ptr[i] = mlx_png_file_to_image(data->ml, c, &tmp, &tmp);
	if (!ptr[i])
		ft_error("can't open png for frames");
}

void	start_filling(t_data *data)
{
	int		i;

	i = 0;
	while (i < 128)
	{
		if (i < 14)
			load_the_img(data, data->gun.fire_frames, i, 1);
		if (i < 5)
			load_the_img(data, data->gun.bullets_frames, i, 2);
		load_the_img(data, data->gun.reload_frames, i, 3);
		i++;
	}
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
	start_filling(data);
	data->gun.idle_frame = \
	mlx_png_file_to_image(data->ml, "textures/gun/fire/idle.png", &tmp, &tmp);
	if (!data->gun.idle_frame)
		ft_error("can't open png for frames");
	data->gun.cursor = \
	mlx_png_file_to_image(data->ml, "textures/gun/fire/cursor.png", &tmp, &tmp);
	if (!data->gun.cursor)
		ft_error("can't open png for frames");
}
