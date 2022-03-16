/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_up_down_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:35:57 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/16 07:00:06 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	get_floor_x_y(t_data *data, t_math *math, float pos_z, int p)
{
	math->row_distance = pos_z / p;
	math->floor_step_x = math->row_distance * \
	(math->raydir_x2 - math->raydir_x1) / WINDOW_WIDTH;
	math->floor_step_y = math->row_distance * \
	(math->raydir_y2 - math->raydir_y1) / WINDOW_WIDTH;
	math->floor_x = data->pl.pos_x + math->row_distance * math->raydir_x1;
	math->floor_y = data->pl.pos_y + math->row_distance * math->raydir_y1;
}

void	put_cell(t_data *data, t_math *math, int y, int x)
{
	int	*color;
	int	tx;
	int	ty;

	tx = (int)(data->ce_t.width * (math->floor_x - math->cell_x)) * \
	(data->ce_t.bits / 8);
	ty = (int)(data->ce_t.hight * (math->floor_y - math->cell_y)) * \
	(data->ce_t.bits / 8);
	color = (int *)(data->ce_t.info + ((data->ce_t.width * ty) + tx));
	put_in_image(data, WINDOW_HIEGHT - y - 1, x, (*color >> 1) & 8355711);
}

void	put_floor(t_data *data, t_math *math, int y, int x)
{
	int	*color;
	int	tx;
	int	ty;

	tx = (int)(data->fl_t.width * (math->floor_x - math->cell_x)) * \
	(data->fl_t.bits / 8);
	ty = (int)(data->fl_t.hight * (math->floor_y - math->cell_y)) * \
	(data->fl_t.bits / 8);
	color = (int *)(data->fl_t.info + ((data->fl_t.width * ty) + tx));
	put_in_image(data, y, x, (*color >> 1) & 8355711);
}

void	start_drawing_up_down(t_data *data, t_math *math, int y)
{
	int	x;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		math->cell_x = (int)math->floor_x;
		math->cell_y = (int)math->floor_y;
		put_floor(data, math, y, x);
		put_cell(data, math, y, x);
		math->floor_x += math->floor_step_x;
		math->floor_y += math->floor_step_y;
	}
}

void	draw_up_down(t_data *data, t_math *math)
{
	float	pos_z;
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
