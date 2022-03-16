/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_the_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 08:20:02 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/16 21:17:46 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	check_format(char *map_name, char *format)
{
	char	*tmp_str;

	tmp_str = ft_strrchr(map_name, '.');
	if (!tmp_str || ft_strcmp(tmp_str, format))
	{
		if (!ft_strcmp(format, ".cub"))
			ft_error("the map should be .cub format");
		if (!ft_strcmp(format, ".png"))
			ft_error("the texturs should be .png format");
	}
}

int	check_if_all_fill(t_data *data)
{
	if (data->ea_t.texture == NULL || data->no_t.texture == NULL \
	|| data->so_t.texture == NULL || data->we_t.texture == NULL \
	|| data->ce_t.texture == NULL || data->fl_t.texture == NULL)
		return (1);
	else
		return (0);
}

void	get_info_from_lines(char *line, t_data *data)
{
	char	**tab;

	tab = ft_split(line, ' ');
	if (ft_count_2d_array(tab) != 2)
		ft_error("invalid map !!");
	if (!ft_strcmp(tab[0], "NO"))
		get_xpm_files(tab[1], &data->no_t, data->ml);
	else if (!ft_strcmp(tab[0], "SO"))
		get_xpm_files(tab[1], &data->so_t, data->ml);
	else if (!ft_strcmp(tab[0], "WE"))
		get_xpm_files(tab[1], &data->we_t, data->ml);
	else if (!ft_strcmp(tab[0], "EA"))
		get_xpm_files(tab[1], &data->ea_t, data->ml);
	else if (!ft_strcmp(tab[0], "F"))
		get_xpm_files(tab[1], &data->fl_t, data->ml);
	else if (!ft_strcmp(tab[0], "C"))
		get_xpm_files(tab[1], &data->ce_t, data->ml);
	else
		if (check_if_all_fill(data))
			ft_error("envalid map !!");
	ft_free_2d_array(tab);
}

void	get_texters_and_map(int fd, t_data *data)
{
	char	*line;

	while (1)
	{
		line = ft_get_line(fd);
		if (!line)
			break ;
		if (check_if_all_fill(data) && !ft_is_just_spaces(line))
			get_info_from_lines(line, data);
		else
		{
			if (ft_is_just_spaces(line) && data->map)
				ft_error("envalid map");
			else if (!ft_is_just_spaces(line))
				add_to_map(data, line);
		}
		free(line);
	}
	if (check_if_all_fill(data) || !data->map)
		ft_error("envalid map");
}

void	init_the_map(char *map_name, t_data *data)
{
	int	fd;

	data->ea_t.texture = NULL;
	data->no_t.texture = NULL;
	data->so_t.texture = NULL;
	data->we_t.texture = NULL;
	data->fl_t.texture = NULL;
	data->ce_t.texture = NULL;
	data->map = NULL;
	check_format(map_name, ".cub");
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_error("open the map faild");
	get_texters_and_map(fd, data);
	check_map(data);
}
