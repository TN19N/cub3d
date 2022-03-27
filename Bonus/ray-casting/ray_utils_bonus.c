/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 08:20:34 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/27 14:06:01 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	gun_frames(t_data *data, int count)
{
	count = 0;
	if ((data->gun.frame == 55 || data->gun.frame == 67 \
	|| data->gun.frame == 79 || \
	data->gun.frame == 92 || data->gun.frame == 101) \
	&& data->gun.bullets < 5)
		data->gun.bullets++;
	if ((data->gun.fired || data->gun.gun_reload) && data->gun.frame != 0)
		data->gun.frame++;
}

void	get_right_one(t_data *data, t_math *m)
{
	if (data->map[m->map_y][m->map_x] == 'D')
		return ;
	else if (m->side == 0 && m->raydir_x > 0)
		data->tar = &data->ea_t;
	else if (m->side == 0 && m->raydir_x < 0)
		data->tar = &data->we_t;
	else if (m->side == 1 && m->raydir_y > 0)
		data->tar = &data->so_t;
	else
		data->tar = &data->no_t;
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

void	put_in_image(t_data *data, int i, int j, int color)
{
	char		*tmp;
	t_texture	*img_t;

	img_t = &data->b_img;
	tmp = img_t->info + (img_t->line_len * i + j * (img_t->bits / 8));
	*(unsigned int *)tmp = color;
}

void	con_draw(t_data *data, t_math_2 *m, int i, t_enemy *e)
{
	t_texture		*t;
	int				j;
	int				d;
	unsigned int	*color;

	j = m->draw_start_y - 1;
	if (e->attacking)
		t = &data->zombie.attack_frames[e->frame_index];
	else if (!e->zombie_dead)
		t = &data->zombie.walk_frames[e->frame_index];
	else if (e->zombie_dead)
		t = &data->zombie.death_frames[e->frame_index];
	while (++j < m->draw_end_y)
	{
		d = (j * 256) - (WINDOW_HIEGHT * 128) + (m->sprite_height * 128);
		m->tex_y = ((d * t->hight) / m->sprite_height) / 256;
		color = (unsigned int *)(t->info + (t->line_len * \
			m->tex_y + (m->tex_x * t->bits / 8)));
		if (*color && *color != 0x010101)
			put_in_image(data, j, i, add_darck(*color, sqrt(e->dest)));
	}
}
