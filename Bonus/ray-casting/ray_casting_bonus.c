/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:18:20 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/16 21:13:30 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	strat_ray(t_data *data)
{
	t_math		*math;
	t_texture	*img_t;
	int			tmp;

	img_t = &data->b_img;
	math = malloc(sizeof(t_math) * 1);
	if (!math)
		ft_error("malloc faild!");
	img_t->texture = mlx_new_image(data->ml, WINDOW_WIDTH, WINDOW_HIEGHT);
	img_t->info = mlx_get_data_addr(img_t->texture, &img_t->bits, \
	&img_t->line_len, &tmp);
	draw_up_down(data, math);
	draw_walls(data, math);
	data->gun.blank_img = data->b_img.texture;
	mlx_put_image_to_window(data->ml, data->wi, img_t->texture, 0, 0);
	mlx_destroy_image(data->ml, img_t->texture);
	free(math);
}
