/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray-casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:18:20 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/12 20:34:10 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
# include <stdio.h>

void	draw_buffer(int **buffer, t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < WINDOW_HIEGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			mlx_pixel_put(data->ml, data->wi, j, i, buffer[i][j]);
			j++;
		}
		i++;
	}
}
void	strat_ray(t_data *data)
{
	int pitch;
	int	**buffer;;
	double tex_pos;
	double step;
	int tex_x;
	int hit;
	int side;
	int step_x;
	int step_y;
	int line_height;
	double perp_wall_dist;
	double side_dist_x;
	double side_dist_y;
	double delta_dist_x;
	double delta_dist_y;
	int map_x;
	int map_y;
	int		x;
	char	c;
	double	wall_x;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		draw_start;
	int		draw_end;
	int 	tex_y;
	int		color;
	t_player *pl;
	char	*info;
	int y;
	int tmp;

	pl = &data->pl;
	x = -1;
	buffer = ft_calloc(WINDOW_HIEGHT, sizeof(int *));
	if (!buffer)
		ft_error("mallc fail :(");
	while (++x < WINDOW_HIEGHT)
	{
		buffer[x] = ft_calloc(WINDOW_WIDTH, sizeof(int));
		if (!buffer[x])
			ft_error("malloc fail :(");
	}
	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		hit = 0;
		camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
		raydir_x = pl->dir_x + pl->plane_x * camera_x;
		raydir_y = pl->dir_y + pl->plane_y * camera_x;
		map_x = (int)pl->pos_x;
		map_y = (int)pl->pos_y;
		delta_dist_x = (raydir_x == 0) ? 1e30 : fabs((1 / raydir_x));
		delta_dist_y = (raydir_y == 0) ? 1e30 : fabs((1 / raydir_y));
		if (raydir_x < 0)
		{
			step_x = -1;
			side_dist_x = (pl->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - pl->pos_x) * delta_dist_x;
		}
		if (raydir_y < 0)
		{
			step_y = -1;
			side_dist_y = (pl->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - pl->pos_y) * delta_dist_y;
		}
		while (hit == 0)
      	{
        	if(side_dist_x < side_dist_y)
        	{
        		side_dist_x += delta_dist_x;
        		map_x += step_x;
    			side = 0;
        	}
        	else
        	{
        		side_dist_y += delta_dist_y;
        		map_y += step_y;
    			side = 1;
       		}
			if (data->map[map_y][map_x] == '1')
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = side_dist_x - delta_dist_x;
    	else
			perp_wall_dist = side_dist_y - delta_dist_y;
		line_height = (int)(WINDOW_HIEGHT / perp_wall_dist);
		pitch = 0;
		draw_start = -line_height / 2 + WINDOW_HIEGHT / 2 + pitch;
      	if (draw_start < 0)
			draw_start = 0;
      	draw_end = line_height / 2 + WINDOW_HIEGHT / 2 + pitch;
      	if (draw_end >= WINDOW_HIEGHT)
			draw_end = WINDOW_HIEGHT - 1;
      	if (side == 0)
			wall_x = pl->pos_y + perp_wall_dist * raydir_y;
      	else
			wall_x = pl->pos_x + perp_wall_dist * raydir_x;
      	wall_x -= floor((wall_x));
		tex_x = (int)(wall_x * (double)TEXTER_WIDTH);
    	if (side == 0 && raydir_x > 0)
			tex_x = TEXTER_WIDTH - tex_x - 1;
    	if (side == 1 && raydir_y < 0)
			tex_x = TEXTER_WIDTH - tex_x - 1;
		step = 1.0 * TEXTER_HIEGHT / line_height;
		tex_pos = (draw_start - pitch - WINDOW_HIEGHT / 2 + line_height / 2) * step;
		y = draw_start;
		c = data->map[map_y][map_x];
      	while (y < draw_end)
      	{
    		tex_y = (int)tex_pos & (TEXTER_HIEGHT - 1);
       		tex_pos += step;
			info = mlx_get_data_addr(data->no_texture, &tmp, &tmp, &tmp);
    		color = (int)info[TEXTER_HIEGHT * tex_y + tex_x];
        	if (side == 1)
				color = (color >> 1) & 8355711;
        	buffer[y][x] = color;
			y++;
      	}
	}
	draw_buffer(buffer, data);
}
