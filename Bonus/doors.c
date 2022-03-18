/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:29:14 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/18 14:19:44 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	wich_door(t_data *data, int y, int x)
{
	t_door	*d;
	int		i;

	i = 0;
	d = data->d;
	while (i < data->number_d)
	{
		if (d[i].y == y && d[i].x == x)
			break ;
		i++;
	}
	return (i);
}

void	open_door(t_data *data, int y, int x)
{
	int	i;

	i = wich_door(data, y, x);
	if (data->d[i].stat == CLOSED)
		sound(1);
	data->d[i].stat = OPENED;
}

void	close_door(t_data *data, int y, int x)
{
	int	i;

	i = wich_door(data, y, x);
	if (data->d[i].stat == OPENED)
		sound(2);
	data->d[i].stat = CLOSED;
}

int	if_closed(t_data *data, int y, int x)
{
	t_door	*d;
	int		i;

	i = 0;
	d = data->d;
	i = wich_door(data, y, x);
	if (d[i].stat == CLOSED)
	{
		data->tar = &data->d[i].do_t;
		return (1);
	}
	else
		return (0);
	return (0);
}

void	get_door_info(t_data *data, int y, int x)
{
	int			tmp;
	t_texture	*t;
	t_door		*d;
	static int	i;

	d = &data->d[i++];
	t = &d->do_t;
	t->texture = \
	mlx_png_file_to_image(data->ml, PTATH_DOOR, &t->width, &t->hight);
	if (!t->texture)
		ft_error("can't open door img :^)");
	t->info = mlx_get_data_addr(t->texture, &t->bits, &t->line_len, &tmp);
	d->x = x;
	d->y = y;
	d->stat = CLOSED;
}
