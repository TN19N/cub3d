/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_up_down_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:35:57 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/15 11:09:05 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	get_floor_x_y(t_data *data, t_math *math, double pos_z, int p)
{
	math->row_distance = pos_z / (double)p;
	math->floor_step_x = math->row_distance * (math->raydir_x2 - math->raydir_x1) / WINDOW_WIDTH;
	math->floor_step_y = math->row_distance * (math->raydir_y2 - math->raydir_y1) / WINDOW_WIDTH;
	math->floor_x = data->pl.pos_x + math->row_distance * math->raydir_x1;
	math->floor_y = data->pl.pos_y + math->row_distance * math->raydir_y1;
}

void	start_drawing_up_down(t_data *data, t_math *math, int y)
{
	int	*color;
	int	tx;
	int ty;
	int	x;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		math->cell_x = (int)math->floor_x;
		math->cell_y = (int)math->floor_y;
		tx = (int)(data->fl_t.width * (math->floor_x - math->cell_x));
		ty = (int)(data->fl_t.hight * (math->floor_y - math->cell_y));
		math->floor_x += math->floor_step_x;
		math->floor_y += math->floor_step_y;
		color = (int *)(data->fl_t.info + (data->fl_t.width * ty + tx * (data->fl_t.bits / 8)));
		put_in_image(data, y, x, *color);
		color = (int *)(data->ce_t.info + (data->ce_t.width * ty + tx * (data->ce_t.bits / 8)));
		put_in_image(data, WINDOW_HIEGHT - y - 1, x, *color);
	}
}

void	draw_up_down(t_data *data, t_math *math)
{
	double	pos_z;
	int		p;
	int		i;

	i = -1;
	while (++i < WINDOW_HIEGHT)
	{
		math->raydir_x1 = data->pl.dir_x - data->pl.plane_x;
		math->raydir_y1 = data->pl.dir_y - data->pl.plane_y;
		math->raydir_x2 = data->pl.dir_x + data->pl.plane_x;
		math->raydir_y2 = data->pl.dir_y + data->pl.plane_y;
		p = i - WINDOW_HIEGHT / 2;
		pos_z = 0.5 * WINDOW_HIEGHT;
		get_floor_x_y(data, math, pos_z, p);
		start_drawing_up_down(data, math, i);
	}
}