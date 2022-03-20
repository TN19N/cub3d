/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:13:10 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/20 18:03:46 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d_bonus.h"

void	my_mlx_pixel_put(t_texture *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1000 && y >= 0 && y < 640)
	{
		dst = data->info + (y * data->line_len + x * (data->bits / 8));
		*(unsigned int *)dst = color;
	}
}

int	pixel_color(t_texture *data, int x, int y)
{
	char	*dst;

	if (x >= 0 && x < 1000 && y >= 0 && y < 640)
	{
		dst = data->info + (y * data->line_len + x * (data->bits / 8));
		return (*(unsigned int *)dst);
	}
	return (0);
}

void	put_big_pixel(t_texture *img, int size, int x, int y, int color)
{
	int i;
	int j;

	i = y * size;
	j = x * size;
	while (i < (y * size) + (size))
	{
		j = x * size;
		while (j < (x * size) + (size))
		{
			my_mlx_pixel_put(img, j , i, color);
			j++;
		}
		i++;
	}
}

void	initialize(t_axis *from, t_axis *to, t_axis *current, t_data *data)
{
	from->y = (int)data->pl.pos_y - 100;
	to->x = (int)data->pl.pos_x + 100;
	to->y = (int)data->pl.pos_y + 100;
	current->y = 0;
	if  ((int)data->pl.pos_y - 100 < 0)
	{
		from->y = 0;
		to->y = 200;
	}
	if ((int)data->pl.pos_x - 100 < 0)
		to->x = 200;
	if ((int)data->pl.pos_x + 100 > data->mini_map.map_width)
		to->x = data->mini_map.map_width;
	if  ((int)data->pl.pos_y + 100 > data->mini_map.map_height)
	{
		to->y = data->mini_map.map_height;
		from->y = to->y - 200;
	}
	data->mini_map.part_map.texture = mlx_new_image(data->ml, 202, 202);
	data->mini_map.part_map.info = mlx_get_data_addr(data->mini_map.part_map.texture, &data->mini_map.part_map.bits, &data->mini_map.part_map.line_len, &data->mini_map.part_map.endian);
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

	initialize(&from, &to, &current,data);
	while (from.y < to.y)
	{
		if ((int)data->pl.pos_x - 100 < 0)
			from.x = 0;
		else if ((int)data->pl.pos_x + 100 > data->mini_map.map_width)
			from.x = to.x - 200;
		else
			from.x = (int)data->pl.pos_x - 100;
		current.x = 0;
		while (from.x < to.x)
		{
			if (from.x == (int)data->pl.pos_x && from.y == (int)data->pl.pos_y)
				assign_player(&current,data);
			else if (from.x >= 0 && from.y >= 0 && from.x <= data->mini_map.map_width && from.y <= data->mini_map.map_height)
			{
				my_mlx_pixel_put(&data->mini_map.part_map, current.x++, current.y, pixel_color(&data->mini_map.full_map, from.x, from.y));
			}
			from.x++;
		}
		current.y++;
		from.y++;
	}
}
 
void	draw_map(t_map *map)
{
	int	i;
	int	j;

	i =	0;
	j =	0;
	while (map->map_content[i])
	{
		j =	0;
		while(map->map_content[i][j])
		{
			if (map->map_content[i][j] == '1')
			{
				put_big_pixel(&map->full_map ,40, j, i, 0xFFFFFF);
			}
			j++;
		}
		i++;
	}
}