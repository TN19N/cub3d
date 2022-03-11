/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:36:38 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/11 12:09:42 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	get_xpm_files(char *file_path, void **ptr, void *ml)
{
	int	tmp;

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

	arr = ft_split(color, ',');
	if (ft_count_2d_array(arr) != 3)
		ft_error("envalid color type !!");
	*ptr = create_trgb(0x0, ft_atoi(arr[0]),\
	 ft_atoi(arr[1]), ft_atoi(arr[2]));
}