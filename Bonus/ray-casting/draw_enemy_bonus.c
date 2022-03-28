/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:54:56 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/28 07:32:58 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	sort_dist(int *order, float *dest_all, int len)
{
	int		j;
	int		i;
	float	tmp;
	int		t;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (dest_all[i] < dest_all[j])
			{
				tmp = dest_all[i];
				dest_all[i] = dest_all[j];
				dest_all[j] = tmp;
				t = order[i];
				order[i] = order[j];
				order[j] = t;
			}
			j++;
		}
		i++;
	}
}

void	get_start_and_end(t_math_2 *m)
{
	m->sprite_height = abs((int)(WINDOW_HIEGHT / m->transform_y));
	m->draw_start_y = -m->sprite_height / 2 + WINDOW_HIEGHT / 2;
	if (m->draw_start_y < 0)
		m->draw_start_y = 0;
	m->draw_end_y = m->sprite_height / 2 + WINDOW_HIEGHT / 2;
	if (m->draw_end_y >= WINDOW_HIEGHT)
		m->draw_end_y = WINDOW_HIEGHT - 1;
	m->sprite_width = abs((int)(WINDOW_HIEGHT / m->transform_y));
	m->draw_start_x = -m->sprite_width / 2 + m->sprite_screen_x;
	if (m->draw_start_x < 0)
		m->draw_start_x = 0;
	m->draw_end_x = m->sprite_width / 2 + m->sprite_screen_x;
	if (m->draw_end_x >= WINDOW_WIDTH)
		m->draw_end_x = WINDOW_WIDTH - 1;
}

void	s_drawing(t_data *data, t_math_2 *m, t_enemy *e)
{
	t_texture	*t;
	int			i;

	i = m->draw_start_x - 1;
	if (e->zombie_dead)
		t = &data->zombie.death_frames[e->frame_index];
	else if (e->attacking)
		t = &data->zombie.attack_frames[e->frame_index];
	else if (!e->zombie_dead)
		t = &data->zombie.walk_frames[e->frame_index];
	while (++i < m->draw_end_x)
	{
		m->tex_x = (int)(256 * (i - \
		(-m->sprite_width / 2 + m->sprite_screen_x)) * \
		t->width / m->sprite_width) / 256;
		if (m->transform_y > 0 && i > 0 && i < WINDOW_WIDTH && \
		m->transform_y < data->z_buffer[i])
			con_draw(data, m, i, e);
	}
}

void	start_now(t_data *data, int *order)
{
	t_player	*p;
	t_enemy		*e;
	t_math_2	m;
	int			i;

	i = -1;
	p = &data->pl;
	while (++i < data->number_e)
	{
		e = &data->enemys[order[i]];
		m.sprite_x = e->x - p->pos_x;
		m.sprite_y = e->y - p->pos_y;
		m.inv_det = 1.0 / (p->plane_x * p->dir_y - p->dir_x * p->plane_y);
		m.transform_x = m.inv_det * \
		(p->dir_y * m.sprite_x - p->dir_x * m.sprite_y);
		m.transform_y = m.inv_det * \
		(-p->plane_y * m.sprite_x + p->plane_x * m.sprite_y);
		m.sprite_screen_x = (int)((WINDOW_WIDTH / 2) * \
		(1 + m.transform_x / m.transform_y));
		get_start_and_end(&m);
		s_drawing(data, &m, e);
	}
}

void	draw_enemy(t_data *data, int i)
{
	t_enemy		*e;
	int			*order;
	float		*dest_all;

	if (data->number_e == 0)
		return ;
	order = malloc(sizeof(int) * data->number_e);
	if (!order)
		ft_error("malloc faild ;(");
	dest_all = malloc(sizeof(float) * data->number_e);
	if (!dest_all)
		ft_error("malloc faild ;(");
	while (++i < data->number_e)
	{
		e = &data->enemys[i];
		order[i] = i;
		dest_all[i] = (data->pl.pos_x - e->x) * (data->pl.pos_x - e->x) + \
		(data->pl.pos_y - e->y) * (data->pl.pos_y - e->y);
		e->dest = dest_all[i];
	}
	sort_dist(order, dest_all, data->number_e);
	start_now(data, order);
	free(order);
	free(dest_all);
}
