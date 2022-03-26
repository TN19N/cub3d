/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:28:23 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/18 13:11:18 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	check_door(t_data *data, int y, int x)
{
	char	**m;
	int		i;
	int		len_y;

	i = 0;
	m = data->map;
	len_y = ft_count_2d_array(data->map);
	if (m[y][x + 1] == '1')
		if (x >= 1 && m[y][x - 1] == '1')
			i = 1;
	if (y < len_y - 1 && x < ft_strlen(m[y + 1]) && m[y + 1][x] == '1')
		if (y >= 1 && x < ft_strlen(m[y - 1]) && m[y - 1][x] == '1')
			i = 1;
	if (i == 0)
		ft_error("invalid door position :(");
	return (1);
}
