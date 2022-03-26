/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:42:48 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/19 11:09:44 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	wich_one(t_data *data, int y, int x)
{
	int	i;

	i = 0;
	while (i < data->number_e)
	{
		if (data->enemys[i].x == x && data->enemys[i].y == y)
			return (i);
		i++;
	}
	return (0);
}

void	get_enemy_info(t_data *data, int y, int x)
{
	t_enemy		*e;
	static int	i;

	e = &data->enemys[i++];
	e->x = (float)x + 0.5;
	e->y = (float)y + 0.5;
}

void	save_enemy_info(t_data *data, t_math *m, int y, int x)
{
	int	i;

	if (data->is_enemy[0])
		return ;
	i = wich_one(data, y, x);
	if (m->side == 0)
		data->enemys[i].dest = m->side_dist_x - m->delta_dist_x;
	else
		data->enemys[i].dest = m->side_dist_y - m->delta_dist_y;
	data->is_enemy[1] = i;
	data->is_enemy[0] = 1;
}
