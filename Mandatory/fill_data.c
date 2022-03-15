/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:36:38 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/15 07:31:57 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	add_to_map(t_data *data, char *line)
{
	int		i;
	int		len_arr;
	char	**tmp_map;

	i = -1;
	len_arr = 0;
	tmp_map = NULL;
	if (data->map)
	{
		tmp_map = data->map;
		len_arr = ft_count_2d_array(tmp_map);
	}
	data->map = malloc(sizeof(char *) * (len_arr + 2));
	if (!data->map)
		ft_error("malloc faild :(");
	if (!tmp_map)
		i = 0;
	else
		while (tmp_map[++i])
			data->map[i] = ft_strdup(tmp_map[i]);
	data->map[i++] = ft_strdup(line);
	data->map[i] = NULL;
	if (tmp_map)
		ft_free_2d_array(tmp_map);
}

void	get_xpm_files(char *file_path, t_texture *t, void *ml)
{
	int	tmp;

	if (t->texture)
		ft_error("you entered different textures for same element");
	t->texture = mlx_xpm_file_to_image(ml, file_path, &t->width, &t->hight);
	if (!t->texture)
		ft_error("envalid texter !!");
	t->info = mlx_get_data_addr(t->texture, &t->bits, &t->line_len, &tmp);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	get_colors(char *color, int **ptr)
{
	int		i;
	char	**arr;

	i = -1;
	if (*ptr)
		ft_error("you entered different colors for same element");
	while (color[++i])
	{
		if (color[i] == ',' && color[i + 1] == ',')
			ft_error("envalid color type !!");
		if (color[i] != ',' && (color[i] < '0' || color[i] > '9'))
			ft_error("envalid color type !!");
	}
	*ptr = malloc(sizeof(int) * 1);
	if (!*ptr)
		ft_error("malloc faild :(");
	arr = ft_split(color, ',');
	if (ft_count_2d_array(arr) != 3)
		ft_error("envalid color type !!");
	**ptr = create_trgb(0x0, ft_atoi(arr[0]), \
	ft_atoi(arr[1]), ft_atoi(arr[2]));
	ft_free_2d_array(arr);
}
