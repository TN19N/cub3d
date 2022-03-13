/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 08:20:34 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/13 08:50:22 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	**init_buffer(void)
{
	int	**buffer;
	int	i;

	i = -1;
	buffer = ft_calloc(WINDOW_HIEGHT, sizeof(int *));
	if (!buffer)
		ft_error("mallc fail :(");
	while (++i < WINDOW_HIEGHT)
	{
		buffer[i] = ft_calloc(WINDOW_WIDTH, sizeof(int));
		if (!buffer[i])
			ft_error("malloc fail :(");
	}
	return (buffer);
}

void	get_delta_dist(t_math *m)
{
	if (m->raydir_x == 0)
		m->delta_dist_x = 1e30;
	else
		m->delta_dist_x = fabs(1 / m->raydir_x);
	if (m->raydir_y == 0)
		m->delta_dist_y = 1e30;
	else
		m->delta_dist_y = fabs(1 / m->raydir_y);
}

void	draw_buffer(int	**buffer, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WINDOW_HIEGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
		{
			mlx_pixel_put(data->no_t.texture, data->wi, j, i, buffer[i][j]);
		}
		free(buffer[i]);
	}
	free(buffer);
}
