/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:18:20 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/19 14:18:44 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	strat_ray(t_data *data, int count)
{
	int			tmp;
	t_math		*math;
	t_texture	*img_t;

	img_t = &data->b_img;
	if (img_t->texture)
		mlx_destroy_image(data->ml, img_t->texture);
	math = malloc(sizeof(t_math));
	if (!math)
		ft_error("malloc faild!");
	data->z_buffer = malloc(sizeof(float) * WINDOW_WIDTH);
	if (!data->z_buffer)
		ft_error("malloc faild!");
	img_t->texture = mlx_new_image(data->ml, WINDOW_WIDTH, WINDOW_HIEGHT);
	img_t->info = mlx_get_data_addr(img_t->texture, &img_t->bits, \
	&img_t->line_len, &tmp);
	draw_walls(data, math);
	zombie_manager(data, count);
	draw_enemy(data, -1);
	gun_frames(data, count);
	data->change = 1;
	free(math);
	free(data->z_buffer);
}
