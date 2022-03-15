/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:05:45 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/15 07:32:05 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_player(t_player *p, double i, double buf)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(ROT_SPEED * i * buf) - \
	p->dir_y * sin(ROT_SPEED * i * buf);
	p->dir_y = old_dir_x * sin(ROT_SPEED * i * buf) + \
	p->dir_y * cos(ROT_SPEED * i * buf);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(ROT_SPEED * i * buf) - \
	p->plane_y * sin(ROT_SPEED * i * buf);
	p->plane_y = old_plane_x * sin(ROT_SPEED * i * buf) + \
	p->plane_y * cos(ROT_SPEED * i * buf);
}

void	move_side_way(t_player *p, char **map, double i)
{
	double		old_dir_x;
	double		tmp_dir_x;
	double		tmp_dir_y;
	double		tmp_x;
	double		tmp_y;

	old_dir_x = p->dir_x;
	tmp_dir_x = p->dir_x * cos(1.7 * i) - p->dir_y * sin(1.7 * i);
	tmp_dir_y = old_dir_x * sin(1.7 * i) + p->dir_y * cos(1.7 * i);
	tmp_x = p->pos_x + tmp_dir_x * MOVE_SPEED;
	tmp_y = p->pos_y + tmp_dir_y * MOVE_SPEED;
	if (map[(int)tmp_y][(int)tmp_x] == '0')
	{
		p->pos_x = tmp_x;
		p->pos_y = tmp_y;
	}
}

void	move_player(t_player *p, char **map, double x, double y)
{
	double		tmp_x;
	double		tmp_y;

	tmp_x = p->pos_x + p->dir_x * x * MOVE_SPEED;
	tmp_y = p->pos_y + p->dir_y * y * MOVE_SPEED;
	if (map[(int)tmp_y][(int)tmp_x] == '0')
	{
		p->pos_x = tmp_x;
		p->pos_y = tmp_y;
	}
}
