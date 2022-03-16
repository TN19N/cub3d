/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:05:45 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/16 10:16:46 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	check_col(char **map, float *tmp_y, float *tmp_x)
{
	int		len_h;
	float	col_x;
	float	col_y;
	float	b_col_x;
	float	b_col_y;

	len_h = ft_count_2d_array(map);
	col_x = *tmp_x + COLLISION;
	col_y = *tmp_y + COLLISION;
	b_col_x = *tmp_x - COLLISION;
	b_col_y = *tmp_y - COLLISION;
	if ((int)col_y < len_h && map[(int)col_y][(int)*tmp_x] == '1')
		*tmp_y = (int)col_y - COLLISION;
	if (map[(int)*tmp_y][(int)col_x] == '1')
		*tmp_x = (int)col_x - COLLISION;
	if ((int)b_col_x >= 0 && map[(int)*tmp_y][(int)b_col_x] == '1')
		*tmp_x = (int)*tmp_x + COLLISION;
	if ((int)b_col_y >= 0 && map[(int)b_col_y][(int)*tmp_x] == '1')
		*tmp_y = (int)*tmp_y + COLLISION;
}

void	rotate_player(t_player *p, float i, float buf)
{
	float		old_dir_x;
	float		old_plane_x;

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

void	move_side_way(t_player *p, char **map, float i)
{
	float		old_dir_x;
	float		tmp_dir_x;
	float		tmp_dir_y;
	float		tmp_x;
	float		tmp_y;

	old_dir_x = p->dir_x;
	tmp_dir_x = p->dir_x * cos(1.6 * i) - p->dir_y * sin(1.6 * i);
	tmp_dir_y = old_dir_x * sin(1.6 * i) + p->dir_y * cos(1.6 * i);
	tmp_x = p->pos_x + tmp_dir_x * MOVE_SPEED;
	tmp_y = p->pos_y + tmp_dir_y * MOVE_SPEED;
	if (map[(int)tmp_y][(int)tmp_x] == '0')
	{
		check_col(map, &tmp_y, &tmp_x);
		p->pos_x = tmp_x;
		p->pos_y = tmp_y;
	}
}

void	move_player(t_player *p, char **map, float x, float y)
{
	float		tmp_x;
	float		tmp_y;

	tmp_x = p->pos_x + p->dir_x * x * MOVE_SPEED;
	tmp_y = p->pos_y + p->dir_y * y * MOVE_SPEED;
	if (map[(int)tmp_y][(int)tmp_x] == '0')
	{
		check_col(map, &tmp_y, &tmp_x);
		p->pos_x = tmp_x;
		p->pos_y = tmp_y;
	}
}
