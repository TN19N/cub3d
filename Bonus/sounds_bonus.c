/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:04:33 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/26 17:38:16 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	check_if_door(t_data *data, int i, float d_x, float d_y)
{
	t_enemy	*e;
	int		tmp_y;
	int		tmp_x;

	e = &data->enemys[i];
	tmp_y = e->y + d_y / 6;
	tmp_x = e->x + d_x / 6;
	if (data->map[tmp_y][tmp_x] == 'D')
		return (1);
	else
		return (0);
}

void	sound(int i)
{
	if (i == 1)
		system("afplay sounds/door_open.mp3 &> /dev/null &");
	else if (i == 2)
		system("afplay sounds/door_close.mp3 &> /dev/null &");
	else if (i == 3)
		system("afplay sounds/gun_shoot.mp3 &> /dev/null &");
	else if (i == 4)
		system("afplay sounds/relaod_sound.mp3 &> /dev/null &");
}
