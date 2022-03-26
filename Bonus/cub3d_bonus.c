/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:18:17 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/20 16:38:56 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	ft_clean(t_data	*data)
{
	ft_free_2d_array(data->map);
	free(data->key_bord);
	ft_putendl_fd("thanks for trying our game :)", 1);
	exit(EXIT_SUCCESS);
}

void	put_evry_thene(t_data *data)
{
	int	l;

	l = data->gun.frame;
	mlx_put_image_to_window(data->ml, data->wi, data->b_img.texture, 0, 0);
	mlx_put_image_to_window(data->ml, data->wi, data->gun.cursor, 500, 320);
	draw_part_of_map(data);
	if (data->gun.gun_reload)
		mlx_put_image_to_window(data->ml, \
		data->wi, data->gun.reload_frames[l], 0, 0);
	if (data->gun.fired)
		mlx_put_image_to_window(data->ml, data->wi, \
		data->gun.fire_frames[l], 0, 0);
	else if (!data->gun.gun_reload && !data->gun.fired)
		mlx_put_image_to_window(data->ml, data->wi, data->gun.idle_frame, 0, 0);
	if (data->gun.bullets)
		mlx_put_image_to_window(data->ml, data->wi, \
		data->gun.bullets_frames[data->gun.bullets - 1], -80, 500);
	my_mlx_pixel_put(&data->b_img, data->mini_map.player.x \
		+ (data->pl.dir_x * 10), \
		data->mini_map.player.y + (data->pl.dir_y * 10), 0xFFFFFF);
	mlx_put_image_to_window(data->ml, data->wi, data->mini_map.icon, \
		data->mini_map.player.x - 5, data->mini_map.player.y - 5);
	data->change = 0;
}

void	keys(t_data *data, int count, int *i)
{
	if (data->key_bord[MOVE_FORWARD] && ++(*i))
		move_player(&data->pl, data->map, 1.0, 1.0);
	if (data->key_bord[MOVE_BOCKWARD] && ++(*i))
		move_player(&data->pl, data->map, -1.0, -1.0);
	if (data->key_bord[MOVE_LEFT] && ++(*i))
		move_side_way(&data->pl, data->map, 1.0);
	if (data->key_bord[MOVE_WRIGHT] && ++(*i))
		move_side_way(&data->pl, data->map, -1.0);
	if ((data->key_bord[ROT_LEFT] || data->mouse_1) && ++(*i))
	{
		rotate_player(&data->pl, 1.0);
		data->mouse_1 = 0;
	}
	if ((data->key_bord[ROT_WRIGHT] || data->mouse_2) && ++(*i))
	{
		rotate_player(&data->pl, -1.0);
		data->mouse_2 = 0;
	}
	if (count % 100 == 0)
		strat_ray(data, count);
}

int	animation(t_data *data)
{
	int			i;
	static int	count;

	i = 0;
	more_keys(data);
	if (count % 100 == 0)
	{
		if (data->key_bord[RELOAD_GUN])
			reload_gun(&data->gun);
		keys(data, count, &i);
		gun_inamation(&data->gun, data, count, i);
		if (data->change || data->gun.gun_reload || data->gun.fired)
			put_evry_thene(data);
		if (data->gun.frame == 0 && (data->gun.gun_reload || data->gun.fired))
			data->gun.frame++;
	}
	count++;
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
	ft_putendl_fd("loading pleas wait ....", 1);
	data.ml = mlx_init();
	init_the_map(av[1], &data);
	init_1(&data);
	data.wi = mlx_new_window(data.ml, WINDOW_WIDTH, WINDOW_HIEGHT, "cub3d");
	strat_ray(&data, 0);
	mlx_mouse_hide();
	mlx_mouse_move(data.wi, WINDOW_WIDTH / 2, 0);
	mlx_hook(data.wi, BUTTONPRESS, NOEVENTMASK, handle_mouse_button, &data);
	mlx_hook(data.wi, MOTIONNOTIFY, POINTERMOTIONMASK, mouse, &data);
	mlx_hook(data.wi, KEYPRESS, KEYPRESSMASK, press_key, &data);
	mlx_hook(data.wi, KEYRELEASE, KEYRELEASEMASK, releas_key, &data);
	mlx_hook(data.wi, DESTROYNOTIFY, NOEVENTMASK, ft_clean, &data);
	mlx_loop_hook(data.ml, animation, &data);
	ft_putendl_fd("you can play now ;)", 1);
	mlx_loop(data.ml);
	return (EXIT_SUCCESS);
}
