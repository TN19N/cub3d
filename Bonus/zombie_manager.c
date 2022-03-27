/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:46:38 by hait-moh          #+#    #+#             */
/*   Updated: 2022/03/27 08:28:22 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	hit_enemy(t_data *data, float x, float y, int i)
{
	float	enemy_x;
	float	enemy_y;

	enemy_x = data->enemys[i].x;
	enemy_y = data->enemys[i].y;
	while (1)
	{
		if (data->map[(int)y][(int)x] == 'D')
			if (if_closed(data, (int)y, (int)x))
				return (0);
		if (pixel_color(&data->mini_map.full_map, (int)(x * 21), \
			(int)(y * 21)) == 0xFFFFFF)
			return (0);
		if (x - 0.07 <= enemy_x && x + 0.2 >= enemy_x && \
			y - 0.1 <= enemy_y && y + 0.2 >= enemy_y)
			return (1);
		x += data->pl.dir_x / 5;
		y += data->pl.dir_y / 5;
	}
	return (0);
}

void	check_for_path(t_data *data, int i)
{
	float		dx;
	float		dy;
	float		length;
	float		deltax;
	float		deltay;

	dx = data->pl.pos_x - data->enemys[i].x;
	dy = data->pl.pos_y - data->enemys[i].y;
	if (fabsf(dx) > fabsf(dy))
		length = fabsf(dx);
	else
		length = fabsf(dy);
	deltax = dx / length;
	deltay = dy / length;
	if (check_if_door(data, i, deltax, deltay))
		return ;
	data->enemys[i].x += deltax / 6;
	data->enemys[i].y += deltay / 6;
	check_col(data->map, &data->enemys[i].y, &data->enemys[i].x, 0.28);
	check_if_enemy(&data->pl, &data->enemys[i].y, &data->enemys[i].x, i);
}

void	movement_manager(t_data *data, int i)
{
	if (data->enemys[i].frame_index == 64 || data->enemys[i].frame_index == 2)
		check_for_path(data, i);
}

void	animation_manager(t_data *data, int count, int i)
{
	if (count % 100 == 0 && (!data->enemys[i].zombie_dead || \
		data->enemys[i].frame_index != 89))
		data->enemys[i].frame_index++;
	if (data->enemys[i].frame_index == 120)
		data->enemys[i].frame_index = 0;
	if (data->enemys[i].attacking && data->enemys[i].frame_index == 65)
	{
		data->enemys[i].attacking = 0;
		data->enemys[i].frame_index = 0;
	}
	if (data->enemys[i].frame_index == 121 && !data->enemys[i].zombie_dead)
		data->enemys[i].frame_index = 0;
	if (data->enemys[i].frame_index == 90 && data->enemys[i].zombie_dead)
		data->enemys[i].frame_index = 0;
}

void	zombie_manager(t_data *data, int count)
{
	int	i;

	i = 0;
	while (i < data->number_e)
	{
		if (in_range(data, i) && !data->enemys[i].zombie_dead \
			&& !data->enemys[i].attacking)
		{
			data->enemys[i].attacking = 1;
			data->enemys[i].frame_index = 0;
		}
		if (in_range(data, i) && !data->enemys[i].zombie_dead \
			&& data->enemys[i].attacking && (data->enemys[i].frame_index == 33 \
			|| data->enemys[i].frame_index == 32))
		{
			printf("you died!\n");
			exit(0);
		}
		animation_manager(data, count, i);
		if (!data->enemys[i].zombie_dead && !data->enemys[i].attacking)
			movement_manager(data, i);
		i++;
	}
}
