/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 07:18:34 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/15 07:31:41 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	start_drawing(t_data *data, t_math *math, int x)
{
	int	i;
	int	*color;

	i = -1;
	while (++i < math->draw_start)
		put_in_image(data, i, x, *(data->ceilling_color));
	i = math->draw_start;
	while (i < math->draw_end)
	{
		math->tex_y = (int)math->tex_pos & (data->tar->hight - 1);
		math->tex_pos += math->step;
		color = (int *)data->tar->info + (data->tar->hight * math->tex_y \
		+ math->tex_x);
		put_in_image(data, i, x, *color);
		i++;
	}
	i = math->draw_end;
	if (i < 0)
		return ;
	while (++i < WINDOW_HIEGHT)
		put_in_image(data, i, x, *(data->floor_color));
}

void	get_line_to_draw(t_data *data, t_math *m)
{
	m->line_height = (int)(WINDOW_HIEGHT / m->perp_wall_dist);
	m->draw_start = ((-1 * m->line_height) / 2) + (WINDOW_HIEGHT / 2);
	if (m->draw_start < 0)
		m->draw_start = 0;
	m->draw_end = (m->line_height / 2) + (WINDOW_HIEGHT / 2);
	if (m->draw_end >= WINDOW_HIEGHT)
		m->draw_end = WINDOW_HIEGHT - 1;
	if (m->side == 0)
		m->wall_x = data->pl.pos_y + m->perp_wall_dist * m->raydir_y;
	else
		m->wall_x = data->pl.pos_x + m->perp_wall_dist * m->raydir_x;
	m->wall_x -= floor((m->wall_x));
	get_right_one(data, m);
	m->tex_x = (int)(m->wall_x * (double)data->tar->width);
	if (m->side == 0 && m->raydir_x > 0)
		m->tex_x = data->tar->width - m->tex_x - 1;
	if (m->side == 1 && m->raydir_y < 0)
		m->tex_x = data->tar->width - m->tex_x - 1;
	m->step = 1.0 * data->tar->hight / m->line_height;
	m->tex_pos = ((m->draw_start - (WINDOW_HIEGHT / \
	2)) + (m->line_height / 2)) * m->step;
}

void	get_hit_pos(t_data *data, t_math *math)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (math->side_dist_x < math->side_dist_y)
		{
			math->side_dist_x += math->delta_dist_x;
			math->map_x += math->step_x;
			math->side = 0;
		}
		else
		{
			math->side_dist_y += math->delta_dist_y;
			math->map_y += math->step_y;
			math->side = 1;
		}
		if (data->map[math->map_y][math->map_x] == '1')
			hit = 1;
	}
	if (math->side == 0)
		math->perp_wall_dist = math->side_dist_x - math->delta_dist_x;
	else
		math->perp_wall_dist = math->side_dist_y - math->delta_dist_y;
	get_line_to_draw(data, math);
}

void	get_side_dist(t_data *data, t_math *m)
{
	get_delta_dist(m);
	if (m->raydir_x < 0)
	{
		m->step_x = -1;
		m->side_dist_x = (data->pl.pos_x - m->map_x) * m->delta_dist_x;
	}
	else
	{
		m->step_x = 1;
		m->side_dist_x = (m->map_x + 1.0 - data->pl.pos_x) * m->delta_dist_x;
	}
	if (m->raydir_y < 0)
	{
		m->step_y = -1;
		m->side_dist_y = (data->pl.pos_y - m->map_y) * m->delta_dist_y;
	}
	else
	{
		m->step_y = 1;
		m->side_dist_y = (m->map_y + 1.0 - data->pl.pos_y) * m->delta_dist_y;
	}
	m->old_side_x = m->side_dist_x;
	m->old_side_y = m->side_dist_y;
}

void	draw_walls(t_data *data)
{
	t_math	*math;
	int		i;

	i = -1;
	math = &data->math;
	while (++i < WINDOW_WIDTH)
	{
		math->camera_x = 2 * i / (double)WINDOW_WIDTH - 1.0;
		math->raydir_x = data->pl.dir_x + data->pl.plane_x * math->camera_x;
		math->raydir_y = data->pl.dir_y + data->pl.plane_y * math->camera_x;
		math->map_x = (int)data->pl.pos_x;
		math->map_y = (int)data->pl.pos_y;
		get_side_dist(data, math);
		get_hit_pos(data, math);
		start_drawing(data, math, i);
	}
}
