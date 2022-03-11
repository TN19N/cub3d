/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 08:20:02 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/11 08:39:20 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	check_the_map(char *map_name, t_data *data)
{
	char	*tmp_str;

	(void)data;
	tmp_str = ft_strrchr(map_name, '.');
	if (!tmp_str || ft_strcmp(tmp_str, ".cub"))
	{
		ft_putendl_fd("the map should be .cub format", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}