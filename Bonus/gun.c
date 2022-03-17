/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:29:51 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/17 09:41:52 by mannouao         ###   ########.fr       */
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

void	fire_animation(t_data *data, t_gun *gun, int x)
{
	static int f = 1;
	char c[40];
	int tmp;

	if (gun->fired == 1)
	{
		if (gun->current_img)
			mlx_destroy_image(data->ml, gun->current_img);
		file_name(c, "textures/gun/fire/", f);
		gun->current_img = mlx_png_file_to_image(data->ml, c, &tmp, &tmp);
		data->change = 1;
		f++;
		gun->fire_index += x;
	}
	if (f > 14)
	{
		f = 1;
		gun->fire_index = 50;
		gun->fired = 0;
	}
}

void	reload_animation(t_data *data, t_gun *gun, int x)
{
	static int f = 1;
	char c[40];
	int tmp;

	if (gun->gun_reload == 1)
	{
		if (gun->current_img)
			mlx_destroy_image(data->ml, gun->current_img);
		file_name(c, "textures/gun/reload/", f);
		gun->current_img = mlx_png_file_to_image(data->ml, c, &tmp, &tmp);
		data->change = 1;
		f++;
		gun->reload_index += x;
	}
	if (f > 128)
	{
		f = 1;
		gun->reload_index = 50;
		gun->gun_reload = 0;
	}
}

void	gun_inamation(t_data *data, t_gun *gun, int x)
{
	int	tmp;

	if (!gun->current_img)
	{
		gun->current_img = mlx_png_file_to_image(data->ml, "textures/gun/fire/14.png", &tmp, &tmp);
		data->change = 1;
	}
	if (gun->fired && !gun->gun_reload && gun->fire_index % 50 == 0)
		fire_animation(data, gun, x);
	else if (gun->fired && !gun->gun_reload && gun->fire_index % 50 != 0)
		gun->fire_index += x;
	if (gun->gun_reload && !gun->fired && gun->reload_index % 50 == 0)
		reload_animation(data, gun, x);
	else if (gun->gun_reload && !gun->fired && gun->reload_index % 50 != 0)
		gun->reload_index += x;
}
