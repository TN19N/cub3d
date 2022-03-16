/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:18:17 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/16 21:11:37 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	ft_clean(t_data	*data)
{
	ft_free_2d_array(data->map);
	free(data->key_bord);
	exit(EXIT_SUCCESS);
}

void	init_2(t_data *data)
{
	data->gun.fire_index = 50;
	data->gun.fired = 0;
	data->gun.reload_index = 50;
	data->gun.gun_reload = 0;
	if (data->pl.spawning == 'N')
	{
		data->pl.plane_x = 0.0;
		data->pl.plane_y = -0.66;
		data->pl.dir_x = 1.0;
		data->pl.dir_y = 0.0;
	}
	else if (data->pl.spawning == 'S')
	{
		data->pl.plane_x = -0.66;
		data->pl.plane_y = 0.0;
		data->pl.dir_x = 0.0;
		data->pl.dir_y = -1.0;
	}
}

void	init_1(t_data *data)
{
	data->pitch = 0;
	if (data->pl.spawning == 'E')
	{
		data->pl.plane_x = 0.0;
		data->pl.plane_y = 0.66;
		data->pl.dir_x = -1.0;
		data->pl.dir_y = 0.0;
	}
	if (data->pl.spawning == 'W')
	{
		data->pl.plane_x = 0.66;
		data->pl.plane_y = 0.0;
		data->pl.dir_x = 0.0;
		data->pl.dir_y = 1.0;
	}
	init_2(data);
}

int	move(t_data *data)
{
	int	i;

	i = 0;
	if (data->key_bord[MOVE_FORWARD] && ++i)
		move_player(&data->pl, data->map, 1.0, 1.0);
	if (data->key_bord[MOVE_BOCKWARD] && ++i)
		move_player(&data->pl, data->map, -1.0, -1.0);
	if (data->key_bord[MOVE_LEFT] && ++i)
		move_side_way(&data->pl, data->map, 1.0);
	if (data->key_bord[MOVE_WRIGHT] && ++i)
		move_side_way(&data->pl, data->map, -1.0);
	if (data->key_bord[ROT_LEFT] && ++i)
		rotate_player(&data->pl, 1.0);
	if (data->key_bord[ROT_WRIGHT] && ++i)
		rotate_player(&data->pl, -1.0);
	//if (data->key_bord[RELOAD_GUN])
	//	reload_gun(&data->gun);
	if (data->key_bord[ESC])
		ft_clean(data);
	//gun_inamation(data, &data->gun);
	if (i > 0)
		strat_ray(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error("usage : ./cub3d (map).cub");
	data.key_bord = ft_calloc(500, sizeof(int));
	if (!data.key_bord)
		ft_error("malloc fail ;(");
	data.ml = mlx_init();
	init_the_map(av[1], &data);
	init_1(&data);
	data.wi = mlx_new_window(data.ml, WINDOW_WIDTH, WINDOW_HIEGHT, "cub3d");
	strat_ray(&data);
	mlx_mouse_hide();
	mlx_mouse_move(data.wi, WINDOW_WIDTH / 2, 0);
	//mlx_key_hook(data.wi, handle_mouse_button, &data.gun);
	//mlx_hook(data.wi, MOTIONNOTIFY, POINTERMOTIONMASK, mouse, &data);
	mlx_hook(data.wi, KEYPRESS, KEYPRESSMASK, press_key, &data);
	mlx_hook(data.wi, KEYRELEASE, KEYRELEASEMASK, releas_key, &data);
	mlx_hook(data.wi, DESTROYNOTIFY, NOEVENTMASK, ft_clean, &data);
	mlx_loop_hook(data.ml, move, &data);
	mlx_loop(data.ml);
	return (EXIT_SUCCESS);
}
