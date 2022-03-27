/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:27:04 by hait-moh          #+#    #+#             */
/*   Updated: 2022/03/27 08:23:47 by mannouao         ###   ########.fr       */
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
	t_player	*p;
	t_enemy		*e;

	p = &data->pl;
	e = &data->enemys[i];
	if (fabs(e->x - p->pos_x) < 0.40 && fabs(e->y - p->pos_y) < 0.40)
		return (1);
	return (0);
}
