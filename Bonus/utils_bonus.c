/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:03:57 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/16 17:56:26 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	releas_key(int key, t_data *data)
{
	data->key_bord[key] = 0;
	return (0);
}

int	press_key(int key, t_data *data)
{
	data->key_bord[key] = 1;
	return (0);
}

int	mouse(int x, int y, t_data *data)
{
	(void)y;
	if (x < WINDOW_WIDTH / 2)
		rotate_player(&data->pl, 1.0);
	else if (x > WINDOW_WIDTH / 2)
		rotate_player(&data->pl, -1.0);
	strat_ray(data);
	mlx_mouse_move(data->wi, WINDOW_WIDTH / 2, 0);
	return (1);
}
