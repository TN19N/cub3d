/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 08:20:02 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/11 11:56:18 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	check_format(char *map_name)
{
	char *tmp_str;

	tmp_str = ft_strrchr(map_name, '.');
	if (!tmp_str || ft_strcmp(tmp_str, ".cub"))
		ft_error("the map should be .cub format");
}

void	check_if_all_fill(t_data *data)
{
	if (data->ea_texture == NULL || data->no_texture == NULL \
	|| data->so_texture == NULL || data->we_texture == NULL \
	|| data->floor_color == NULL || data->ceilling_color == NULL)
		ft_error("invalid map !!");
}

void	get_info_from_lines(char *line, t_data *data)
{
	char **tab;
	
	tab = ft_split(line, ' ');
	if (ft_count_2d_array(tab) != 2)
		ft_error("invalid map !!");
	if (!ft_strcmp(tab[0], "NO"))
		get_xpm_files(tab[1], &data->no_texture, data->ml);
	else if (!ft_strcmp(tab[0], "SO"))
		get_xpm_files(tab[1], &data->so_texture, data->ml);
	else if (!ft_strcmp(tab[0], "WE"))
		get_xpm_files(tab[1], &data->we_texture, data->ml);
	else if (!ft_strcmp(tab[0], "EA"))
		get_xpm_files(tab[1], &data->ea_texture, data->ml);
	else if (!ft_strcmp(tab[0], "F"))
		get_colors(tab[1], data->floor_color);
	else if (!ft_strcmp(tab[0], "C"))
		get_colors(tab[1], data->ceilling_color);
	else
		check_if_all_fill(data);
}

void	get_texters(int fd, t_data *data)
{
	char	*line;
	int		fd_texter;

	while (1)
	{
		line = ft_get_line(fd);
		if (line)
			break ;
		if (!ft_is_just_spaces(line))
			get_info_from_lines(line, data);
		free(line);
	}
}

void	init_the_map(char *map_name, t_data *data)
{
	int fd;

	data->ea_texture = NULL;
	data->no_texture = NULL;
	data->so_texture = NULL;
	data->we_texture = NULL;
	data->floor_color = NULL;
	data->ceilling_color = NULL;
	check_format(map_name);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_error("open the map faild");
	get_texters(fd, data);
}
