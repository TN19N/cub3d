/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:03:57 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/20 08:33:42 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	releas_key(int key, t_data *data)
{
	data->key_bord[key] = 0;
	return (0);
}

int	press_key(int key, t_data *data)
{
	data->key_bord[key] = 1;
	return (0);
}

int	mouse(int x, int y, t_data *data)
{
	(void)y;
	if (!data->mouse_on)
		return (0);
	if (x < WINDOW_WIDTH / 2)
		data->mouse_1 = 1;
	else if (x > WINDOW_WIDTH / 2)
		data->mouse_2 = 1;
	mlx_mouse_move(data->wi, WINDOW_WIDTH / 2, 0);
	return (1);
}

int	handle_mouse_button(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (!data->mouse_on)
	{
		data->mouse_on = 1;
		mlx_mouse_hide();
		mlx_mouse_move(data->wi, WINDOW_WIDTH / 2, 0);
	}
	if (button == 1 && !data->gun.gun_reload)
		fire_gun(&data->gun);
	return (0);
}

void	file_name(char *c, char *path, int filenum)
{
	char	*it;
	char	*extention;
	int		i;

	i = 0;
	extention = ".png";
	it = ft_itoa(filenum);
	while (*path)
		*(c++) = *(path++);
	while (it[i])
		*(c++) = it[i++];
	while (*extention)
		*(c++) = *(extention++);
	free(it);
	*c = 0;
}
