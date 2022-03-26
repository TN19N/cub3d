/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.21.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:13:10 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/20 18:03:21 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub3d_bonus.h"

void	put_big_pixel(t_texture *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = y * 21;
	j = x * 21;
	while (i < (y * 21) + (21))
	{
		j = x * 21;
		while (j < (x * 21) + (21))
		{
			my_mlx_pixel_put(img, j, i, color);
			j++;
		}
		i++;
	}
}

void	initialize(t_axis *from, t_axis *to, t_axis *current, t_data *data)
{
	if (!current)
	{
		if ((int)(data->pl.pos_x * 21) - 100 < 0)
			from->x = 0;
		else if ((int)(data->pl.pos_x * 21) + 100 > data->mini_map.map_width)
			from->x = to->x - 200;
		return ;
	}
	from->y = (int)(data->pl.pos_y * 21) - 100;
	to->x = (int)(data->pl.pos_x * 21) + 100;
	to->y = (int)(data->pl.pos_y * 21) + 100;
	if ((int)(data->pl.pos_y * 21) - 100 < 0)
	{
		from->y = 0;
		to->y = 200;
	}
	if ((int)(data->pl.pos_x * 21) - 100 < 0)
		to->x = 200;
	if ((int)(data->pl.pos_x * 21) + 100 > data->mini_map.map_width)
		to->x = data->mini_map.map_width;
	if ((int)(data->pl.pos_y * 21) + 100 > data->mini_map.map_height)
	{
		to->y = data->mini_map.map_height;
		from->y = to->y - 200;
	}
}

void	assign_player(t_axis *current, t_data *data)
{
	data->mini_map.player.x = current->x++;
	data->mini_map.player.y = current->y;
}

void	draw_part_of_map(t_data *data)
{
	t_axis	from;
	t_axis	to;
	t_axis	current;

	initialize(&from, &to, &current, data);
	current.y = 0;
	while (from.y < to.y)
	{
		from.x = (int)(data->pl.pos_x * 21) - 100;
		initialize(&from, &to, NULL, data);
		current.x = 0;
		while (from.x < to.x)
		{
			if (from.x == (int)(data->pl.pos_x * 21) && \
				from.y == (int)(data->pl.pos_y * 21))
				assign_player(&current, data);
			else if (from.x >= 0 && from.y >= 0 && from.x <= \
				data->mini_map.map_width && from.y <= data->mini_map.map_height)
				my_mlx_pixel_put(&data->b_img, current.x++, current.y, \
					pixel_color(&data->mini_map.full_map, from.x, from.y));
			from.x++;
		}
		current.y++;
		from.y++;
	}
}

void	draw_map(t_map *map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->full_map.texture = mlx_new_image(data->ml, \
		map->map_width + 20, map->map_height + 20);
	map->full_map.info = mlx_get_data_addr(map->full_map.texture, \
		&map->full_map.bits, &map->full_map.line_len, &map->full_map.endian);
	while (map->map_content[i])
	{
		j = 0;
		while (map->map_content[i][j])
		{
			if (map->map_content[i][j] == '1')
				put_big_pixel(&map->full_map, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
