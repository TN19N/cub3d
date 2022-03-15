/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 06:59:54 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/15 07:31:50 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_if_valid(t_data *data, char c, int i, int j)
{
	if (c != '1' && c != ' ' && c != '0' \
	&& c != 'N' && c != 'W' && c != 'E' \
	&& c != 'S')
		return (1);
	if (c == 'S' || c == 'W' || c == 'E' || c == 'N')
	{
		if (data->pl.spawning != '@')
			ft_error("you entered more than one player :)");
		else
		{
			data->pl.pos_x = (double)j;
			data->pl.pos_y = (double)i;
			data->pl.spawning = data->map[i][j];
			data->map[i][j] = '0';
		}
	}
	return (0);
}

int	check_x(t_data *data, int i, int j)
{
	int	tmp_j;

	tmp_j = j;
	while (data->map[i][j])
	{
		if (data->map[i][j] == ' ')
			ft_error("the map not surrounded by walls");
		if (data->map[i][j] == '1')
			break ;
		j++;
	}
	if (!data->map[i][j])
		return (1);
	while (tmp_j >= 0)
	{
		if (data->map[i][tmp_j] == ' ')
			ft_error("the map not surrounded by walls");
		if (data->map[i][tmp_j] == '1')
			break ;
		tmp_j--;
	}
	if (tmp_j < 0)
		return (1);
	return (0);
}

int	check_y(t_data *data, int i, int j)
{
	int	tmp_i;

	tmp_i = i;
	while (data->map[i])
	{
		if (data->map[i][j] == ' ' || j >= ft_strlen(data->map[i]))
			return (1);
		if (data->map[i][j] == '1')
			break ;
		i++;
	}
	if (!data->map[i])
		return (1);
	while (tmp_i >= 0)
	{
		if (data->map[tmp_i][j] == ' ' || j >= ft_strlen(data->map[tmp_i]))
			return (1);
		if (data->map[tmp_i][j] == '1')
			break ;
		tmp_i--;
	}
	if (tmp_i < 0)
		return (1);
	return (0);
}

void	check_if_surrounded(t_data *data)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			c = data->map[i][j];
			if (c == '0' || c == 'W' || c == 'N' || c == 'E' || c == 'S')
				if (check_y(data, i, j) || check_x(data, i, j))
					ft_error("the map not surrounded by walls");
		}
	}
}

void	check_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->pl.spawning = '@';
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (check_if_valid(data, data->map[i][j], i, j))
				ft_error("invalid element in the map");
		}	
	}
	if (data->pl.spawning == '@')
		ft_error("you didnt entre a player ???");
	check_if_surrounded(data);
}
