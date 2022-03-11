/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:36:38 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/11 13:26:49 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	add_to_map(t_data *data, char *line)
{
	int	i;
	int	len_arr;
	char **tmp_map;

	i = -1;
	len_arr = 0;
	tmp_map = NULL;
	if (data->map)
	{
		tmp_map = data->map;
		len_arr = ft_count_2d_array(tmp_map);
		free(data->map);
	}
	data->map = malloc(sizeof(char *) * (len_arr + 2));
	if (!data->map)
		ft_error("malloc faild :(");
	if (!tmp_map)
	{
		data->map[0] = ft_strdup(line);
		data->map[1] = NULL;
		return ;
	}
	while (tmp_map[++i])
		data->map[i] = ft_strdup(tmp_map[i]);
	data->map[i++] = ft_strdup(line);
	data->map[i] = NULL;
}

void	get_xpm_files(char *file_path, void **ptr, void *ml)
{
	int	tmp;

	if (*ptr)
		ft_error("you entered different textures for same element");
	*ptr = mlx_xpm_file_to_image(ml, file_path, &tmp, &tmp);
	if (!*ptr)
		ft_error("envalid texter !!"); 
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	get_colors(char *color, int **ptr)
{
	char	**arr;

	if (*ptr)
		ft_error("you entered different colors for same element");
	*ptr = malloc(sizeof(int) * 1);
	if (!*ptr)
		ft_error("malloc faild :(");
	arr = ft_split(color, ',');
	if (ft_count_2d_array(arr) != 3)
		ft_error("envalid color type !!");
	**ptr = create_trgb(0x0, ft_atoi(arr[0]),\
	 ft_atoi(arr[1]), ft_atoi(arr[2]));
	ft_free_2d_array(arr);
}