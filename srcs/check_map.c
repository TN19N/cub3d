/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 06:59:54 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/12 07:26:06 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

int		check_if_valid(char c)
{
	if (c != '1' && c != ' ' && c != '0' \
	&& c != 'N' && c != 'W' && c != 'E' \
	&& c != 'S')
		return (1);
	return (0);
}

void	check_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (check_if_valid(data->map[i][j]))
				ft_error("invalid element in the map");
		}	
	}
}