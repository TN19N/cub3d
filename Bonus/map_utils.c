/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:27:04 by hait-moh          #+#    #+#             */
/*   Updated: 2022/03/26 10:27:06 by hait-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub3d_bonus.h"

void	my_mlx_pixel_put(t_texture *data, int x, int y, int color)
{
	char	*dst;

	dst = data->info + (y * data->line_len + x * (data->bits / 8));
	*(unsigned int *)dst = color;
}

int	pixel_color(t_texture *data, int x, int y)
{
	char	*dst;

	dst = data->info + (y * data->line_len + x * (data->bits / 8));
	return (*(unsigned int *)dst);
}

int	in_range(t_data *data, int i)
{
	if (data->pl.pos_x + (data->pl.dir_x / 5) - 0.15 <= data->enemys[i].x && \
		data->pl.pos_x + (data->pl.dir_x / 5) + 0.15 >= data->enemys[i].x \
		&& data->pl.pos_y + (data->pl.dir_y / 5) - 0.15 <= data->enemys[i].y && \
		data->pl.pos_y + (data->pl.dir_y / 5) + 0.15 >= data->enemys[i].y)
		return (1);
	return (0);
}
