/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:29:51 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/19 15:51:26 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	fire_gun(t_gun *gun)
{
	if (gun->fired == 0 && !gun->gun_reload)
	{
		gun->frame = 0;
		gun->fired = 1;
		if (gun->bullets)
		{
			sound(3);
			gun->bullets--;
		}
	}
}

void	reload_gun(t_gun *gun)
{
	if (gun->gun_reload == 0 && !gun->fired)
	{
		sound(4);
		gun->frame = 0;
		gun->gun_reload = 1;
		gun->bullets = 0;
	}
}

void	gun_inamation(t_gun *gun, t_data *data, int count, int i)
{
	if ((data->gun.frame == 55 || data->gun.frame == 67 || \
	data->gun.frame == 79 || data->gun.frame == 92 || data->gun.frame == 101) \
	&& data->gun.bullets < 5 && !i && count % 400 == 0)
		data->gun.bullets++;
	if (gun->fired && !gun->gun_reload && gun->frame >= 14)
	{
		gun->fired = 0;
		gun->frame = 0;
		data->change = 1;
	}
	if (gun->gun_reload && !gun->fired && gun->frame >= 128)
	{
		gun->gun_reload = 0;
		gun->frame = 0;
		data->change = 1;
	}
	if (!gun->bullets && !gun->fired)
	{
		if (!gun->gun_reload)
			sound(4);
		gun->gun_reload = 1;
	}
}
