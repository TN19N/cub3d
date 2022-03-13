/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:18:17 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/13 14:08:25 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

int	ft_clean(void *v_data)
{
	t_data	*data;

	data = (t_data *)v_data;
	ft_free_2d_array(data->map);
	free(data->floor_color);
	free(data->ceilling_color);
	exit(EXIT_SUCCESS);
}

void	mega_init(t_data *data)
{
	data->pl.dir_x = -1.0;
	data->pl.dir_y = 0.0;
	data->pl.plane_x = 0.0;
	data->pl.plane_y = 0.66;
}

int	move(int key, void *v_data)
{
	t_data	*data;

	data = (t_data *)v_data;
	if (key == MOVE_FORWARD)
		move_player(data, 1.0, 1.0);
	//else if (key == MOVE_LEFT)
	//	move_player(data, 0.0, -1.0); // need fix
	else if (key == MOVE_BOCKWARD)
		move_player(data, -1.0, -1.0);
	//else if (key == MOVE_WRIGHT) // need fix
	//	move_player(data, -1.0, 0.0);
	else if (key == ROT_LEFT)
		rotate_player(data, 1.0);
	else if (key == ROT_WRIGHT)
		rotate_player(data, -1.0);
	else if (key == ESC)
		ft_clean(v_data);
	strat_ray(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error("usage : ./cub3d (map).cub");
	mega_init(&data);
	data.ml = mlx_init();
	init_the_map(av[1], &data);
	data.wi = mlx_new_window(data.ml, WINDOW_WIDTH, WINDOW_HIEGHT, "cub3d");
	strat_ray(&data);
	mlx_hook(data.wi, 02, 0L, move, &data);
	mlx_hook(data.wi, 17, 0L, ft_clean, &data);
	mlx_loop(data.ml);
	return (EXIT_SUCCESS);
}
