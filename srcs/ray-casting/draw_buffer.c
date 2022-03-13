/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 08:20:34 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/13 14:06:36 by mannouao         ###   ########.fr       */
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
	t_texture	img_t;
	char		*tmp;
	int			tmp1;
	int			i;
	int			j;

	i = -1;
	img_t.texture = mlx_new_image(data->ml, WINDOW_WIDTH, WINDOW_HIEGHT);
	img_t.info = mlx_get_data_addr(img_t.texture, &img_t.bits, \
	&img_t.line_len, &tmp1);
	while (++i < WINDOW_HIEGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
		{
			tmp = img_t.info + (img_t.line_len * i + j * (img_t.bits / 8));
			*(unsigned int *)tmp = buffer[i][j];
		}
		free(buffer[i]);
	}
	free(buffer);
	mlx_put_image_to_window(data->ml, data->wi, img_t.texture, 0, 0);
	mlx_destroy_image(data->ml, img_t.texture);
}
