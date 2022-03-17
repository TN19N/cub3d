/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:18:17 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/17 10:35:01 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	ft_clean(t_data	*data)
{
	ft_free_2d_array(data->map);
	free(data->key_bord);
	exit(EXIT_SUCCESS);
}

void	put_evry_thene(t_data *data)
{
	mlx_put_image_to_window(data->ml, data->wi, data->b_img.texture, 0, 0);
	mlx_put_image_to_window(data->ml, data->wi, data->gun.current_img, 0, 0);
	data->change = 0;
}

void	keys(t_data *data)
{
	int	v;
	int	i;

	i = 0;
	v = data->gun.fired + data->gun.gun_reload;
	if (data->key_bord[MOVE_FORWARD] && !v && ++i)
		move_player(&data->pl, data->map, 1.0, 1.0);
	if (data->key_bord[MOVE_BOCKWARD] && !v && ++i)
		move_player(&data->pl, data->map, -1.0, -1.0);
	if (data->key_bord[MOVE_LEFT] && !v && ++i)
		move_side_way(&data->pl, data->map, 1.0);
	if (data->key_bord[MOVE_WRIGHT] && !v && ++i)
		move_side_way(&data->pl, data->map, -1.0);
	if ((data->key_bord[ROT_LEFT] || data->mouse_1) && !v && ++i)
	{
		rotate_player(&data->pl, 1.0);
		data->mouse_1 = 0;
	}
	if ((data->key_bord[ROT_WRIGHT] || data->mouse_2) && !v && ++i)
	{
		rotate_player(&data->pl, -1.0);
		data->mouse_2 = 0;
	}
	if (i > 0)
		strat_ray(data);
}

int	animation(t_data *data)
{
	if (data->key_bord[ESC])
		ft_clean(data);
	if (data->key_bord[RELOAD_GUN])
		reload_gun(&data->gun);
	keys(data);
	gun_inamation(data, &data->gun);
	if (data->change)
		put_evry_thene(data);
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
	mlx_hook(data.wi, BUTTONPRESS, NOEVENTMASK, handle_mouse_button, &data.gun);
	mlx_hook(data.wi, MOTIONNOTIFY, POINTERMOTIONMASK, mouse, &data);
	mlx_hook(data.wi, KEYPRESS, KEYPRESSMASK, press_key, &data);
	mlx_hook(data.wi, KEYRELEASE, KEYRELEASEMASK, releas_key, &data);
	mlx_hook(data.wi, DESTROYNOTIFY, NOEVENTMASK, ft_clean, &data);
	mlx_loop_hook(data.ml, animation, &data);
	mlx_loop(data.ml);
	return (EXIT_SUCCESS);
}
