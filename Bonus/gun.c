/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:29:51 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/16 20:53:02 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d_bonus.h"

void	fire_gun(t_gun *gun)
{
	if (gun->fired == 0)
	{
		gun->fired = 1;
		gun->fire_index = 50;
	}
}

void	reload_gun(t_gun *gun)
{
	if (gun->gun_reload == 0)
	{
		gun->gun_reload = 1;
		gun->reload_index = 50;
	}
}

void	fire_animation(t_data *data, t_gun *gun)
{
	char c[40];
	void	*img;
	int height;
	int width;

	//ft_strcpy("./fire/a.xpm", c);
	if (gun->fired == 1)
	{
		file_name(c, "textures/png/gun/fire/", (gun->fire_index / 50));
		//cursor(data);
		//fire_smoke(data);
		img = mlx_png_file_to_image(data->ml, c, &height, &width);
		mlx_put_image_to_window(data ->ml, data->wi, img, 0, 0);
		mlx_destroy_image(data->ml, img);
		gun->fire_index++;
	}
	if (gun->fire_index == 651)
	{
		gun->fire_index = 50;
		gun->fired = 0;
	}
}

# include <stdio.h>

void	reload_animation(t_data *data, t_gun *gun)
{
	char c[40];
	void	*img;
	int height;
	int width;

	if (gun->gun_reload == 1)
	{
		//cursor(data);
		file_name(c, "textures/png/gun/reload/", (gun->reload_index / 50));
		img = mlx_png_file_to_image(data->ml, c, &height, &width);
		mlx_put_image_to_window(data->ml, data->wi, img, 0, 0);
		mlx_destroy_image(data->ml, img);
		gun->reload_index++;
	}
	if (gun->reload_index == 6351)
	{
		gun->reload_index = 50;
		gun->gun_reload = 0;
	}
}

void	gun_inamation(t_data *data, t_gun *gun)
{
	if (gun->fired && !gun->gun_reload && gun->fire_index % 50 == 0)
	{
		mlx_put_image_to_window(data->ml, data->wi, gun->blank_img, 0, 0);
		fire_animation(data, gun);
	}
	else if (gun->fired && !gun->gun_reload && gun->fire_index % 50 != 0)
	{
		gun->fire_index++;
	}
	if (gun->gun_reload && !gun->fired && gun->reload_index % 50 == 0)
	{
		mlx_put_image_to_window(data->ml, data->wi, gun->blank_img, 0, 0);
		reload_animation(data, gun);
	}
	else if (gun->gun_reload && !gun->fired && gun->reload_index % 50 != 0)
	{
		gun->reload_index++;
	}
}
