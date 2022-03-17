/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:18:20 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/17 09:54:14 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"
#include <stdio.h>
void	strat_ray(t_data *data)
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
	img_t->texture = mlx_new_image(data->ml, WINDOW_WIDTH, WINDOW_HIEGHT);
	img_t->info = mlx_get_data_addr(img_t->texture, &img_t->bits, \
	&img_t->line_len, &tmp);
	draw_walls(data, math);
	reload_gun(&data->gun);
	data->change = 1;
	free(math);
}
